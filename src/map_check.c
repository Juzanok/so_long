/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:31:32 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/10 19:27:40 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_file(char *file)
{
	char	*a;

	a = ft_strrchr(file, '.');
	if (a == NULL || ft_strncmp(a, ".ber", 5) != 0)
	{
		ft_printf("\e[H\e[2J\e[3J");
		ft_printf("Error : map description file must end with .ber\n");
		return (0);
	}
	return (1);
}

int	map_border(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->max_y - 1][i] != '1')
		{
			ft_printf("Error : The map must be closed/surrounded by walls\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->max_y)
	{
		if (game->map[i][0] != '1' || game->map[i][game->max_x - 1] != '1')
		{
			ft_printf("Error : The map must be closed/surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_figure(t_game *game)
{
	size_t	x;
	int		i;

	i = 1;
	x = ft_strlen(game->map[0]);
	while (i < game->max_y)
	{
		if (x != ft_strlen(game->map[i]))
		{
			ft_printf("Error : The map must be rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_components(char *str)
{
	if (!ft_strchr(str, 'E') || !ft_strchr(str, 'C') || !ft_strchr(str, 'P'))
	{
		ft_printf("Error : The map must contain at least 1 E, 1 C, and 1 P\n");
		return (0);
	}
	return (1);
}

int	map_unknown_components(t_game *game)
{
	char	*str;
	int		x;
	int		y;

	str = "01CPEN";
	y = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x)
		{
			if (!ft_strchr(str, game->map[y][x]))
			{
				ft_printf("Error : Unknown character in the map\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

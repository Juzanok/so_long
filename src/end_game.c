/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:07:24 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/10 19:06:50 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_struct(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->max_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}

int	end_loop(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	end_game(t_game *game)
{
	int	x;

	x = -1;
	while (++x < 4)
		mlx_destroy_image(game->mlx, game->player[x]);
	x = -1;
	while (++x < 10)
		mlx_destroy_image(game->mlx, game->coin[x]);
	x = -1;
	while (++x < 10)
		mlx_destroy_image(game->mlx, game->enemy[x]);
	mlx_destroy_image(game->mlx, game->clear_moves);
	mlx_destroy_image(game->mlx, game->background);
	mlx_destroy_image(game->mlx, game->border);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (0);
}

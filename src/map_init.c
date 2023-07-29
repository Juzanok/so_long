/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:49 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/10 19:51:34 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_init(t_game *game)
{
	get_variables(game);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->max_x * game->bsize,
			(game->max_y + 1) * game->bsize, "so_long");
	xpm_init(game);
	mlx_get_screen_size(game->mlx, &game->window_size_x, &game->window_size_y);
	game->x_blocks = game->window_size_x / game->bsize + 1;
	game->y_blocks = (game->window_size_y / game->bsize) - 2;
	get_render(game, &game->render_x, &game->render_y);
	render(game);
	return (1);
}

void	get_variables(t_game *game)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	game->coin_count = count;
}

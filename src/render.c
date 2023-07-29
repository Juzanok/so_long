/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 03:04:39 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/10 22:33:19 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render(t_game *game)
{
	int	x;
	int	y;

	move_counter(game);
	animation(game);
	y = 0;
	while (y < game->max_y && y < game->y_blocks)
	{
		x = 0;
		while (x < game->max_x && x < game->x_blocks)
		{
			push_img(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

int	push_img(t_game *game, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = game->render_x + x;
	map_y = game->render_y + y;
	if (game->map[map_y][map_x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->border, x * game->bsize, y * game->bsize);
	else if (game->map[map_y][map_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit, x * game->bsize, y * game->bsize);
	else if (game->map[map_y][map_x] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player[game->player_anim], x * game->bsize, y * game->bsize);
	else if (game->map[map_y][map_x] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->background, x * game->bsize, y * game->bsize);
	return (1);
}

int	animation(t_game *game)
{
	static int	time = -1;
	static int	i = -1;

	time++;
	if (time == 0)
	{
		i++;
		if (i > 9)
			i = 0;
	}
	if (time > 400)
		time = -1;
	if (time == 0)
		animation_img(game, i);
	return (1);
}

void	animation_img(t_game *game, int i)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;

	y = 0;
	map_y = game->render_y;
	while (y < game->max_y && y < game->y_blocks)
	{
		x = 0;
		map_x = game->render_x;
		while (x < game->max_x && x < game->x_blocks)
		{
			if (game->map[map_y][map_x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->coin[i], x * game->bsize, y * game->bsize);
			else if (game->map[map_y][map_x] == 'N')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->enemy[i], x * game->bsize, y * game->bsize);
			x++;
			map_x++;
		}
		y++;
		map_y++;
	}
}

void	get_render(t_game *game, int *x, int *y)
{
	*x = game->player_x - game->x_blocks / 2;
	if (*x > game->max_x - game->x_blocks)
		*x = game->max_x - game->x_blocks;
	if (*x < 0)
		*x = 0;
	*y = game->player_y - game->y_blocks / 2;
	if (*y > game->max_y - game->y_blocks)
		*y = game->max_y - game->y_blocks;
	if (*y < 0)
		*y = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:42:26 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/08 17:56:27 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_counter(t_game *game)
{
	char	*count;
	int		x;
	int		y;

	if (game->max_y < game->y_blocks)
		y = game->max_y;
	else
		y = game->y_blocks;
	x = 1;
	while (x < game->max_x)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->clear_moves, x * game->bsize, y * game->bsize);
		x++;
	}
	count = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->mlx_win, 10,
		((y + 1) * game->bsize) - 20, 0xffffff, "MOVES : ");
	mlx_string_put(game->mlx, game->mlx_win, 55,
		((y + 1) * game->bsize) - 20, 0xffffff, count);
	free(count);
}

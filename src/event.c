/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:13:59 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/10 19:54:45 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move(t_game *game, int x, int y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + y][game->player_x + x] = 'P';
	game->player_x += x;
	game->player_y += y;
	game->moves++;
	get_render(game, &game->render_x, &game->render_y);
	render(game);
	ft_printf("\e[H\e[2J\e[3JMoves : %i\n", game->moves);
	move_counter(game);
}

void	ft_move_check(t_game *game, int x, int y, int p)
{
	game->player_anim = p;
	if (game->map[game->player_y + y][game->player_x + x] == '0')
		ft_move(game, x, y);
	else if (game->map[game->player_y + y][game->player_x + x] == 'C')
	{
		game->coin_count--;
		ft_move(game, x, y);
	}
	else if (game->map[game->player_y + y][game->player_x + x] == 'E')
	{
		if (game->coin_count == 0)
		{
			ft_move(game, x, y);
			mlx_loop_end(game->mlx);
			ft_printf("\e[H\e[2J\e[3J");
			ft_printf("Great job, you won <3\n");
		}
	}
	else if (game->map[game->player_y + y][game->player_x + x] == 'N')
	{
		ft_move(game, x, y);
		mlx_loop_end(game->mlx);
		ft_printf("\e[H\e[2J\e[3J");
		ft_printf("You lost, next time try to avoid the angry wizards!\n");
	}
}

int	key_events(int keycode, t_game *game)
{
	if (keycode == EVENT_W)
		ft_move_check(game, 0, -1, 1);
	else if (keycode == EVENT_S)
		ft_move_check(game, 0, 1, 0);
	else if (keycode == EVENT_A)
		ft_move_check(game, -1, 0, 2);
	else if (keycode == EVENT_D)
		ft_move_check(game, 1, 0, 3);
	else if (keycode == EVENT_ESC)
		mlx_loop_end(game->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:27:25 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/10 22:56:17 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	play_game(t_game *game)
{
	ft_printf("\e[H\e[2J\e[3JMoves : %i\n", game->moves);
	mlx_key_hook(game->mlx_win, key_events, game);
	mlx_hook(game->mlx_win, 12, (1L << 15), render, game);
	mlx_hook(game->mlx_win, 17, 0, end_loop, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
	end_game(game);
	ft_printf("Moves : %i\n", game->moves);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error : there should be one map as an argument\n");
		return (0);
	}
	game = malloc(sizeof(t_game));
	game->bsize = 50;
	game->moves = 0;
	game->player_anim = 0;
	if (!ft_check_file(argv[1]))
	{
		free(game);
		return (0);
	}
	if (get_map(&game, argv[1]))
		play_game(game);
	else
		ft_printf("Unable to stat the game\n");
	free_struct(game);
	return (0);
}

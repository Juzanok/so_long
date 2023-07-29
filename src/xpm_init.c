/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:26:04 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/07 16:28:45 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	xpm_init_player(t_game *game)
{
	game->player[0] = ft_open_xpm(game, "./images/player/0.xpm");
	game->player[1] = ft_open_xpm(game, "./images/player/1.xpm");
	game->player[2] = ft_open_xpm(game, "./images/player/2.xpm");
	game->player[3] = ft_open_xpm(game, "./images/player/3.xpm");
}

void	xpm_init_coin(t_game *game)
{
	game->coin[0] = ft_open_xpm(game, "./images/coin/0.xpm");
	game->coin[1] = ft_open_xpm(game, "./images/coin/1.xpm");
	game->coin[2] = ft_open_xpm(game, "./images/coin/2.xpm");
	game->coin[3] = ft_open_xpm(game, "./images/coin/3.xpm");
	game->coin[4] = ft_open_xpm(game, "./images/coin/4.xpm");
	game->coin[5] = ft_open_xpm(game, "./images/coin/5.xpm");
	game->coin[6] = ft_open_xpm(game, "./images/coin/6.xpm");
	game->coin[7] = ft_open_xpm(game, "./images/coin/7.xpm");
	game->coin[8] = ft_open_xpm(game, "./images/coin/8.xpm");
	game->coin[9] = ft_open_xpm(game, "./images/coin/9.xpm");
}

void	xpm_init_enemy(t_game *game)
{
	game->enemy[0] = ft_open_xpm(game, "./images/enemy/0.xpm");
	game->enemy[1] = ft_open_xpm(game, "./images/enemy/1.xpm");
	game->enemy[2] = ft_open_xpm(game, "./images/enemy/2.xpm");
	game->enemy[3] = ft_open_xpm(game, "./images/enemy/3.xpm");
	game->enemy[4] = ft_open_xpm(game, "./images/enemy/4.xpm");
	game->enemy[5] = ft_open_xpm(game, "./images/enemy/5.xpm");
	game->enemy[6] = ft_open_xpm(game, "./images/enemy/6.xpm");
	game->enemy[7] = ft_open_xpm(game, "./images/enemy/7.xpm");
	game->enemy[8] = ft_open_xpm(game, "./images/enemy/8.xpm");
	game->enemy[9] = ft_open_xpm(game, "./images/enemy/9.xpm");
}

void	xpm_init(t_game *game)
{
	xpm_init_player(game);
	xpm_init_enemy(game);
	xpm_init_coin(game);
	game->clear_moves = ft_open_xpm(game, "./images/moves_clear.xpm");
	game->background = ft_open_xpm(game, "./images/background.xpm");
	game->border = ft_open_xpm(game, "./images/border.xpm");
	game->exit = ft_open_xpm(game, "./images/exit.xpm");
}

void	*ft_open_xpm(t_game *game, char *str)
{
	return (mlx_xpm_file_to_image(game->mlx, str,
			&game->picture_size, &game->picture_size));
}

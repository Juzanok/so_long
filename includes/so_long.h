/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:15:35 by jkarosas          #+#    #+#             */
/*   Updated: 2022/03/10 23:01:53 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# define EVENT_W 119
# define EVENT_A 97
# define EVENT_S 115
# define EVENT_D 100
# define EVENT_ESC 65307

typedef struct t_game
{
	char	**map;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	int		player_anim;
	int		moves;
	int		bsize;
	int		coin_count;
	int		picture_size;
	int		window_size_x;
	int		window_size_y;
	int		render_x;
	int		render_y;
	int		y_blocks;
	int		x_blocks;

	void	*mlx;
	void	*mlx_win;
	void	*clear_moves;
	void	*background;
	void	*border;
	void	*exit;
	void	*player[4];
	void	*enemy[10];
	void	*coin[10];
}	t_game;

// so_long.c
int		main(int argc, char **argv);
void	play_game(t_game *game);

//xpm_init.c
void	xpm_init(t_game *game);
void	xpm_init_coin(t_game *game);
void	xpm_init_enemy(t_game *game);
void	xpm_init_player(t_game *game);
void	*ft_open_xpm(t_game *game, char *str);

// map_check.c
int		ft_check_file(char *file);
int		map_figure(t_game *game);
int		map_border(t_game *game);
int		map_components(char *str);
int		map_unknown_components(t_game *game);

// map_read.c
char	*read_file(int fd);
char	*ft_join(char *s1, char *s2);

// end_game.c
void	free_struct(t_game *game);
int		end_loop(t_game *game);
int		end_game(t_game *game);

// move_count.c
void	move_counter(t_game *game);

// render.c
int		push_img(t_game *game, int x, int y);
int		render(t_game *game);
int		animation(t_game *game);
void	animation_img(t_game *game, int i);
void	get_render(t_game *game, int *x, int *y);

// event.c
int		key_events(int keycode, t_game *game);
void	ft_move_check(t_game *game, int x, int y, int p);
void	ft_move(t_game *game, int x, int y);

// map_get.c
int		get_map(t_game **game, char *file);
int		word_length(char *src, char s);
int		line_count(char *src, char s);
char	**struct_map(char *src, char s, int *max_y);
char	*ft_strcpy(char *src, int j);

// map_init.c
int		map_init(t_game *game);
void	get_variables(t_game *game);

#endif
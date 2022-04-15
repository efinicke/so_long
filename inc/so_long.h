/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:41:07 by efinicke          #+#    #+#             */
/*   Updated: 2022/04/05 20:15:11 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ESC 	65307
# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100

# define PXL_NB	64

/* structures */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		lenght;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_map
{
	char	**map;
	int		x_size;
	int		y_size;
	int		p_x;
	int		p_y;
	int		moves;
	int		collectibles;
}		t_map;

typedef struct s_sprites
{
	t_img	exi;
	t_img	pos;
	t_img	col;
	t_img	wal;
	t_img	spc;
}		t_sprites;

typedef struct s_datas
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_sprites	sprites;
	t_img		img;
}		t_datas;

void	init_struct(t_datas *datas);

/* basics */
void	send_error(char *error_message);
int		ft_strlen(char *s);
char	*ft_strjoin_free(char *bigstring, char *buf);

/* ber file parsing */
int		parse_map_file(char *file, t_datas *datas);
int		is_ber_file(char *filename);
int		is_good_map(char **map, t_datas *datas);
int		is_map_rectagular(char **map, t_datas *datas);
int		is_good_wall(char **map);
int		is_valid_char(char **map);
int		is_good_char_nb(t_datas *datas);

/* generate, char **map with ber.file, and display and free it */
char	**ft_split(char *s, char c);
char	**extract_map(char *file_name, t_datas *datas);
void	display_map(char **map);
void	free_map(char **split);

/* display the map on the window */
void	init_img_window_and_sprites(t_datas *datas);
void	generate_window_map(t_datas *datas);

/* move the player on the displayed map */
int		key_hook(int key, t_datas *datas);
void	events(int x, int y, t_datas *datas, int key);
void	move_player_x(int x, int y, int mov, t_datas *datas);
void	move_player_y(int x, int y, int mov, t_datas *datas);
void	print_moves(int moves);

/* make free */
int		close_window(t_datas *datas);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:57:09 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/22 15:14:10 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx_int.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define PIKACHU "sprites/pikachu.xpm"
# define GROUND "sprites/ground.xpm"
# define BERRY "sprites/berry.xpm"
# define EXIT "sprites/exit.xpm"
# define WALL "sprites/wall.xpm"

# define K_ESC 65307
# define K_A			97
# define K_W			119
# define K_S			115
# define K_D			100

typedef struct s_data
{
	char			*line;
	struct s_data	*next;
}	t_data;

typedef struct s_image
{
	void	*pikachu;
	void	*ground;
	void	*berry;
	void	*exit;
	void	*wall;
}	t_image;

typedef struct s_map
{
	int				collectible;
	int				position;
	int				px;
	int				py;
	int				exit;
	int				horizontal;
	int				vertical;
	int				move_count;
	int				i;
	int				j;
	int				**visited;
	char			**map_array;
	t_image			*image;
	t_data			*data;
	void			*mlx;
	void			*mlx_win;
}	t_map;

int		init_struct(t_map *map);
int		close_window(t_map *map);
int		is_valid_map(t_map *map);
int		**init_tab_visited(t_map *map);
int		check_hook(int keycode, t_map *map);
int		list_to_tab(t_data *data, t_map *map);
int		put_image(t_map *map, int i, int j);
int		map_render(t_map *map);

int		parsing_border(t_data *data);
int		parsing_character(t_data *data);
int		parsing_extension(char *filename);
int		parsing_line(t_data **data, int fd);
int		parsing_img(t_image *image, void *mlx);
int		parsing_map(t_data *data, t_map *map);
int		parsing_first_and_last_line(t_data *data);
int		parsing_stack(char **argv, t_data **data);
int		parsing_minimal_map(t_data *data, t_map *map);
int		parsing_size_and_format(t_data *data, t_map *map);
int		parsing(int argc, char **argv, t_map *map, t_data **data);

int		move_top(t_map *map);
int		move_left(t_map *map);
int		move_down(t_map *map);
int		move_right(t_map *map);

void	free_tab(t_map *map);
void	close_img(t_map *map);
void	find_player(t_map *map);
void	free_all(t_map *map);
void	free_data(t_data *data);
void	free_char_tab(t_map *map);
void	free_invalid_map(t_map *map);
void	ft_move_player(int keycode, t_map *map);

char	*ft_itoa(int n);
char	**init_tab(t_map *map);

void	free_list(t_data *data);
void	print_list(t_data *data);

t_data	*lst_new(void *content);
t_data	*ft_lstlast(t_data *data);
t_data	*ft_lstadd_back(t_data **data, t_data *new);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:57:09 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/14 17:02:14 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	char			*line;
	struct s_data	*next;
}	t_data;

int		parsing_map(t_data *data);
int		parsing_border(t_data *data);
int		parsing_character(t_data *data);
int		parsing_extension(char *filename);
int		parsing_size_and_format(t_data *data);
int		parsing_first_and_last_line(t_data *data);
int		parsing(int argc, char **argv, t_data *data, void *mlx);
int		parsing_stack(char *filename, char **argv, t_data **data);

void	free_list(t_data *data);
void	print_list(t_data *data);

t_data	*lst_new(void *content);
t_data	*ft_lstlast(t_data *data);
t_data	*ft_lstadd_back(t_data **data, t_data *new);

#endif

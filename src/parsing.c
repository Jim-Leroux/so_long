/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:53:47 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/18 17:59:31 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parsing(int argc, char **argv, t_map *map, t_data **data)
{
	if (argc != 2)
		return (write(2, "Error: Wrong arguments\n", 23), 0);
	if (parsing_extension(argv[1]) == 0)
		return (write(2, "Error: Wrong file extension\n", 28), 0);
	if (parsing_stack(argv, data) == 0)
		return (2);
	if (parsing_map(*data, map) == 0)
		return (0);
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		return (write(2, "Error: mlx not initialised\n", 27), 0);
	return (1);
}

int	parsing_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i = i - 4;
	if (filename[i] == '.' && filename[i + 1] == 'b' && filename[i + 2] == 'e'
		&& filename[i + 3] == 'r')
		return (1);
	return (0);
}

int	parsing_stack(char **argv, t_data **data)
{
	int		fd;
	int		index;
	char	*line;
	t_data	*tmp;

	if (data == NULL)
		return (write(2, "Error: Structure malloc\n", 24), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error: can't open file\n", 23), 0);
	index = 0;
	(*data) = lst_new(get_next_line(fd));
	if ((*data)->line == NULL)
		return (write(2, "Error: No map to read\n", 22), 0);
	while (1)
	{
		tmp = lst_new(get_next_line(fd));
		line = (tmp->line);
		if (line == NULL)
			break ;
		ft_lstadd_back(data, tmp);
		tmp = tmp->next;
	}
	return (1);
}

int	parsing_map(t_data *data, t_map *map)
{
	init_struct(map);
	if (parsing_first_and_last_line(data) == 0)
		return (0);
	if (parsing_character(data) == 0 || parsing_border(data) == 0
		|| parsing_size_and_format(data, map) == 0
		|| parsing_minimal_map(data, map) == 0)
		return (0);
	while (data->next)
		data = data->next;
	if (parsing_first_and_last_line(data) == 0)
		return (0);
	return (1);
}

int	parsing_first_and_last_line(t_data *data)
{
	int		i;

	i = 0;
	while (data->line[i] != '\n' && data->line[i] != '\0')
	{
		if (data->line[i] != '1')
		{
			printf("Ici : %d\n", i);
			return (write(2, "Error: border is not a wall\n", 28), 0);
		}
		i++;
	}
	return (1);
}

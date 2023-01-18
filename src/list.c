/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:38:59 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/18 12:58:39 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	*lst_new(void *content)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->line = content;
	data->next = NULL;
	return (data);
}

t_data	*ft_lstadd_back(t_data **data, t_data *new)
{
	t_data	*last;

	if (*data == NULL)
		*data = new;
	else
	{
		last = ft_lstlast(*data);
		last->next = new;
	}
	return (*data);
}

t_data	*ft_lstlast(t_data *data)
{
	if (!data)
		return (NULL);
	while (data->next)
		data = data->next;
	return (data);
}

void	free_list(t_data *data)
{
	t_data	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		free(tmp);
	}
}

void	print_list(t_data *data)
{
	while (data)
	{
		printf("%s", data->line);
		data = data->next;
	}
}

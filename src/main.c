/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:49:17 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/14 15:11:21 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	t_data	*data;

	mlx = mlx_init();
	data = malloc(sizeof(t_data));
	if (parsing(argc, argc, data, mlx) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

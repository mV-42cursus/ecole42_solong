/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:18:43 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 23:20:45 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

int	main(int ac, char *av[])
{
	unsigned int	resolution[2];
	t_map			*data;

	if (ac != AC_ERROR)
		exit_program(AC_ERROR);
	init_data(&data, av);
	validate_logic(data);
	resolution[ROW] = PIXEL * data->row;
	resolution[COL] = PIXEL * data->col;
	if (resolution[ROW] > ROW_RESOLUTION_MAX || \
		resolution[COL] > COL_RESOLUTION_MAX)
		exit_program(RESOLUTION_ERROR);
	data->gpu.mlx = mlx_init();
	data->gpu.win = mlx_new_window(data->gpu.mlx, \
								resolution[COL], resolution[ROW], "so_long");
	init_img_map(data, 0, 0);
	mlx_hook(data->gpu.win, 2, 0, key_command, data);
	mlx_hook(data->gpu.win, 17, 0, close_mlx_window, data);
	mlx_loop(data->gpu.mlx);
	return (0);
}

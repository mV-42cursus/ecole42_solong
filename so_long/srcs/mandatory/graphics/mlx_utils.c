/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 04:01:02 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 23:08:33 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

int	close_mlx_window(t_map *data)
{
	mlx_destroy_window(data->gpu.mlx, data->gpu.win);
	free_queue(data);
	free_heap_int_double_pointer(data->visited, data->row);
	free_heap_struct_s_map(data);
	exit(EXIT_SUCCESS);
}

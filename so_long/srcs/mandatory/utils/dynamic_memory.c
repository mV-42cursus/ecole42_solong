/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:00:48 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 21:30:29 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "class_helper.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

void	free_heap_struct_s_map(t_map *data)
{
	int	i;

	i = data->row;
	while (i != STOP)
		free(data->map[i--]);
	free(data->queue_loc);
	free(data->map);
	free(data);
}

void	free_heap_int_double_pointer(int **buffer, int row)
{
	int	row_idx;

	row_idx = 0;
	while (row_idx < row)
		free(buffer[row_idx++]);
	free(buffer);
}

void	free_queue(struct s_map *data)
{
	void	*temp_loc;

	temp_loc = NULL;
	while (!is_empty(data->queue_loc))
	{
		temp_loc = dequeue(data->queue_loc);
		free(temp_loc);
	}
}

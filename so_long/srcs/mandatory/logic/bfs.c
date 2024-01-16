/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:58:34 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/08 00:07:16 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "class_helper.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

void	east_west_south_north(t_map *data, int *target_loc, int *_loc)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		target_loc = malloc(sizeof(int) * 2);
		if (!target_loc)
			exit_program(DYNAMIC_HEAP_ALLOCATION_ERROR);
		target_loc[ROW] = _loc[ROW] + data->delta[VERTICLE][i];
		target_loc[COL] = _loc[COL] + data->delta[HORIZONTAL][i];
		if (data->map[target_loc[ROW]][target_loc[COL]] != WALL && \
			data->visited[target_loc[ROW]][target_loc[COL]] == NOT_VISITED)
		{
			data->visited[target_loc[ROW]][target_loc[COL]] \
				= data->visited[_loc[ROW]][_loc[COL]] + 1;
			enqueue(data->queue_loc, (void *)target_loc);
		}
		else
			free(target_loc);
	}
}

void	bfs(struct s_map *data, int loc[2], int destination)
{
	int		*new_loc;
	int		*target_loc;
	int		*_loc;

	new_loc = malloc(sizeof(int) * 2);
	if (!new_loc)
		exit_program(DYNAMIC_HEAP_ALLOCATION_ERROR);
	new_loc[ROW] = loc[ROW];
	new_loc[COL] = loc[COL];
	target_loc = NULL;
	data->visited[new_loc[ROW]][new_loc[COL]] = VISITED;
	enqueue(data->queue_loc, (void *)new_loc);
	while (!is_empty(data->queue_loc))
	{
		_loc = dequeue(data->queue_loc);
		if (data->map[_loc[ROW]][_loc[COL]] == destination)
		{
			data->player.bfs_distance = data->visited[_loc[ROW]][_loc[COL]];
			free(_loc);
			free_queue(data);
			break ;
		}
		east_west_south_north(data, target_loc, _loc);
		free(_loc);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:25:01 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/06 00:24:06 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "class_helper.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

void	surrounded_by_wall(char **map, int row, int col)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	col_idx = 0;
	while (row_idx < row)
	{
		if (map[row_idx][0] != WALL)
			exit_program(MAP_WALL_ERROR);
		if (map[row_idx][col - 1] != WALL)
			exit_program(MAP_WALL_ERROR);
		row_idx++;
	}
	while (col_idx < col)
	{
		if (map[0][col_idx] != WALL)
			exit_program(MAP_WALL_ERROR);
		if (map[row - 1][col_idx] != WALL)
			exit_program(MAP_WALL_ERROR);
		col_idx++;
	}
}

void	logic_player_to_exit(struct s_map *data, int target_loc[2])
{
	calculate_target_loc(data, data->exit_loc, EXIT);
	calculate_target_loc(data, target_loc, PLAYER);
	data->player.row = target_loc[0];
	data->player.col = target_loc[1];
	target_to_destination(data, target_loc, PLAYER);
}

void	logic_collectibles_to_exit(struct s_map *data, int target_loc[2])
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	col_idx = 0;
	while (row_idx < data->row)
	{
		col_idx = 0;
		while (col_idx < data->col)
		{
			if (data->map[row_idx][col_idx] == COLLECTIBLE)
			{
				target_loc[0] = row_idx;
				target_loc[1] = col_idx;
				target_to_destination(data, target_loc, COLLECTIBLE);
			}
			col_idx++;
		}
		row_idx++;
	}
}

void	exhaustive_search(struct s_map *data)
{
	int	target_loc[2];
	int	i;

	i = 0;
	data->visited = (int **)malloc(sizeof(int *) * (data->row));
	if (!data->visited)
		exit_program(DYNAMIC_HEAP_ALLOCATION_ERROR);
	while (i < data->row)
	{
		data->visited[i] = (int *)malloc(sizeof(int) * (data->col));
		if (!data->visited[i])
			exit_program(DYNAMIC_HEAP_ALLOCATION_ERROR);
		i++;
	}	
	logic_player_to_exit(data, target_loc);
	logic_collectibles_to_exit(data, target_loc);
}

void	validate_logic(struct s_map *data)
{
	if (data->row > 2 && data->col > 2)
		surrounded_by_wall(data->map, data->row, data->col);
	else
		exit_program(MAP_ERROR);
	exhaustive_search(data);
}

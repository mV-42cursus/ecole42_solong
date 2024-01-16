/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 02:40:20 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 16:59:55 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "const_var.h"
#include "include.h"
#include "class_functions.h"
#include "class_helper.h"

int	find_destination(struct s_map *data, int row, int col, int destination)
{
	int	new_row;
	int	new_col;
	int	i;

	i = -1;
	data->visited[row][col] = VISITED;
	if (data->map[row][col] == destination)
		return (VALID);
	while (++i < 4)
	{
		new_row = row + data->delta[VERTICLE][i];
		new_col = col + data->delta[HORIZONTAL][i];
		if (data->map[new_row][new_col] != WALL && \
			data->visited[new_row][new_col] == NOT_VISITED)
		{
			if (destination == PLAYER)
				if (data->map[new_row][new_col] == EXIT)
					continue ;
			if (find_destination(data, new_row, new_col, destination))
				return (VALID);
		}
	}
	return (INVALID);
}

void	target_to_destination(struct s_map *data, int loc[2], int target)
{
	init_visited(data);
	if (target == PLAYER)
	{
		if (find_destination(data, loc[ROW], loc[COL], EXIT) == VALID)
			return ;
		else
			exit_program(LOGIC_PLAYER_EXIT_ERROR);
	}
	if (target == COLLECTIBLE)
	{
		if (find_destination(data, loc[ROW], loc[COL], PLAYER) == VALID)
			return ;
		else
			exit_program(LOGIC_COLLECTIBLE_EXIT_ERROR);
	}
}

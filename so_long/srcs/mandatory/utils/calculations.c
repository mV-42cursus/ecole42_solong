/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:18:49 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/05 19:59:09 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "const_var.h"

int	calculate_row(char **map, int row)
{
	while (map[row])
		row++;
	return (row);
}

int	calculate_col(char **map, int row, int col)
{
	while (map[row][col])
		col++;
	return (col);
}

void	calculate_target_loc(struct s_map *data, int player[2], int target)
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
			if (data->map[row_idx][col_idx] == target)
			{
				player[ROW] = row_idx;
				player[COL] = col_idx;
				return ;
			}
			col_idx++;
		}
		row_idx++;
	}
}

int	calculate_items(char **map, int row, int col)
{
	int	row_idx;
	int	col_idx;
	int	items;

	row_idx = 0;
	col_idx = 0;
	items = 0;
	while (row_idx < row)
	{
		col_idx = 0;
		while (col_idx < col)
		{
			if (map[row_idx][col_idx] == 'C')
				items++;
			col_idx++;
		}
		row_idx++;
	}
	return (items);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:18:49 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 21:29:25 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "class_helper.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

char	**init_map(char *file_name)
{
	char	buffer[1500];
	char	**map;
	int		fd;

	valid_format(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == OPEN_ERROR)
		exit_program(FD_OPEN_ERROR);
	ft_memset(buffer, 0, 1500);
	read(fd, buffer, 1500);
	is_valid_shape(buffer);
	is_valid_element(buffer);
	map = ft_split(buffer, '\n');
	return (map);
}

void	init_data(struct s_map **data, char *av[])
{
	*data = (struct s_map *)malloc(sizeof(struct s_map) * 1);
	if (!data)
		exit_program(DYNAMIC_HEAP_ALLOCATION_ERROR);
	*data = ft_memset(*data, 0, sizeof(*data));
	ft_memset(&((*data)->gpu), 0, sizeof((*data)->gpu));
	ft_memset(&((*data)->player), 0, sizeof((*data)->player));
	(*data)->map = init_map(av[1]);
	(*data)->row = calculate_row((*data)->map, 0);
	(*data)->col = calculate_col((*data)->map, 0, 0);
	(*data)->items = calculate_items((*data)->map, (*data)->row, (*data)->col);
	(*data)->delta[0][0] = NORTH;
	(*data)->delta[0][1] = SOUTH;
	(*data)->delta[0][2] = STAY;
	(*data)->delta[0][3] = STAY;
	(*data)->delta[1][0] = STAY;
	(*data)->delta[1][1] = STAY;
	(*data)->delta[1][2] = WEST;
	(*data)->delta[1][3] = EAST;
	(*data)->queue_loc = malloc(sizeof(t_queue));
	if (!((*data)->queue_loc))
		exit_program(DYNAMIC_HEAP_ALLOCATION_ERROR);
	(*data)->queue_loc->front = NULL;
	(*data)->queue_loc->rear = NULL;
}

void	init_visited(struct s_map *data)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < data->row)
	{
		col_idx = 0;
		while (col_idx < data->col)
		{
			data->visited[row_idx][col_idx] = 0;
			col_idx++;
		}
		row_idx++;
	}
}

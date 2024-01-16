/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 05:02:08 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/30 05:02:15 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


int	find_destination(struct s_map *data, int row, int col, int destination)
{
	int new_row;
	int new_col;
	int	i;

	i = 0;
	// ////////////////////////////////////////////////////
	// ////////////////////////////////////////////////////
	// int row_idx = 0;
	// int col_idx = 0;
	// while (row_idx < data->row)
	// {
	// 	col_idx = 0;
	// 	while (col_idx < data->col)
	// 	{
	// 		printf("%d ", visited[row_idx][col_idx]);
	// 		col_idx++;
	// 	}
	// 	puts("");
	// 	row_idx++;
	// }
	// ////////////////////////////////////////////////////
	// ////////////////////////////////////////////////////
	data->visited[row][col] = VISITED;
	if (data->map[row][col] == destination)
		return (VALID);
	while (i < 4)
	{
		new_row = row + data->delta[VERTICLE][i];
		new_col = col + data->delta[HORIZONTAL][i];
		printf("(%d %d)\n", new_row, new_col);
		if (data->map[new_row][new_col] != WALL && data->visited[new_row][new_col] == NOT_VISITED)
		{
			if (destination == PLAYER)
			{
				if (data->map[new_row][new_col] != EXIT)
					if (find_destination(data, new_row, new_col, destination))
						return (VALID);
			}
			else
				if (find_destination(data, new_row, new_col, destination))
					return (VALID);
		}
		i++;
	}
	return (INVALID);
}
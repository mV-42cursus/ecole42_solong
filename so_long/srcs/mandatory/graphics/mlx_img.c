/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:55:14 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/05 19:58:39 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

void	xpm_to_img_to_window(t_map *data, int row, int col, char *img_file)
{
	int		row_render;
	int		col_render;

	row_render = 0;
	col_render = 0;
	data->gpu.img = mlx_xpm_file_to_image(data->gpu.mlx, \
										img_file, &row_render, &col_render);
	mlx_put_image_to_window(data->gpu.mlx, data->gpu.win, \
							data->gpu.img, col * col_render, row * row_render);
}

void	init_img_map(t_map *data, int row_idx, int col_idx)
{
	while (row_idx < data->row)
	{
		col_idx = 0;
		while (col_idx < data->col)
		{
			if (data->map[row_idx][col_idx] == PLAYER)
				xpm_to_img_to_window(data, row_idx, col_idx, \
									"./texture/player.xpm");
			if (data->map[row_idx][col_idx] == WALL)
				xpm_to_img_to_window(data, row_idx, col_idx, \
									"./texture/wall.xpm");
			if (data->map[row_idx][col_idx] == PATH)
				xpm_to_img_to_window(data, row_idx, col_idx, \
									"./texture/path.xpm");
			if (data->map[row_idx][col_idx] == EXIT)
				xpm_to_img_to_window(data, row_idx, col_idx, \
									"./texture/exit.xpm");
			if (data->map[row_idx][col_idx] == COLLECTIBLE)
				xpm_to_img_to_window(data, row_idx, col_idx, \
									"./texture/item.xpm");
			col_idx++;
		}
		row_idx++;
	}
}

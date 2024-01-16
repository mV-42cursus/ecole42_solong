/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:55:11 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/08 04:49:35 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "class_helper.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

void	player_movement(t_map *data, int col, int row)
{
	xpm_to_img_to_window(data, data->player.row, data->player.col, \
						"./texture/path.xpm");
	xpm_to_img_to_window(data, data->exit_loc[ROW], data->exit_loc[COL], \
						"./texture/exit.xpm");
	xpm_to_img_to_window(data, data->player.row + row, data->player.col + col, \
						"./texture/path.xpm");
	xpm_to_img_to_window(data, data->player.row + row, data->player.col + col, \
						"./texture/player.xpm");
}

void	exit_bfs_distance(t_map *data, int loc[2], int idx)
{
	if (data->map[loc[ROW]][loc[COL]] == WALL)
		return ;
	data->player.total_movement++;
	ft_printf("current number of movements: %d\n", data->player.total_movement);
	data->player.cur_distance++;
	player_movement(data, data->delta[COL][idx], data->delta[ROW][idx]);
	if (data->player.cur_distance == data->player.bfs_distance - 1)
		if (data->map[loc[ROW]][loc[COL]] != EXIT)
			finish_process(data, FAIL);
	if (data->map[loc[ROW]][loc[COL]] == EXIT)
		if (data->player.collected == data->items)
			finish_process(data, SUCCESS);
	data->player.row += data->delta[ROW][idx];
	data->player.col += data->delta[COL][idx];
}

void	search_for_item(t_map *data, int loc[2], int idx)
{
	if (data->map[loc[ROW]][loc[COL]] == WALL)
		return ;
	data->player.total_movement++;
	ft_printf("current number of movements: %d\n", data->player.total_movement);
	player_movement(data, data->delta[COL][idx], data->delta[ROW][idx]);
	if (data->map[loc[ROW]][loc[COL]] == COLLECTIBLE)
	{
		data->map[loc[ROW]][loc[COL]] = PATH;
		data->player.collected++;
		if (data->player.collected == data->items)
			bfs(data, loc, EXIT);
	}
	data->player.row += data->delta[ROW][idx];
	data->player.col += data->delta[COL][idx];
}

void	graphics_apply_movement(t_map *data, int idx)
{
	int	loc[2];

	loc[ROW] = data->player.row + data->delta[ROW][idx];
	loc[COL] = data->player.col + data->delta[COL][idx];
	if (data->player.bfs_distance == SEARCH_ITEM)
		search_for_item(data, loc, idx);
	else
		exit_bfs_distance(data, loc, idx);
}

int	key_command(int key_code, t_map *data)
{
	init_visited(data);
	if (key_code == ESC)
		close_mlx_window(data);
	else if (key_code == UP_ASDW || key_code == UP_ARROW)
		graphics_apply_movement(data, 0);
	else if (key_code == DOWN_ASDW || key_code == DOWN_ARROW)
		graphics_apply_movement(data, 1);
	else if (key_code == LEFT_ASDW || key_code == LEFT_ARROW)
		graphics_apply_movement(data, 2);
	else if (key_code == RIGHT_ASDW || key_code == RIGHT_ARROW)
		graphics_apply_movement(data, 3);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:29:15 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/08 04:49:26 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

void	finish_process(t_map *data, int flag)
{
	if (flag == SUCCESS)
	{
		ft_putendl_fd("Congratulations! You have accomplished the goal \
of the game.", 1);
		free_heap_int_double_pointer(data->visited, data->row);
		free_heap_struct_s_map(data);
		exit(EXIT_SUCCESS);
	}
	if (flag == FAIL)
	{
		ft_putendl_fd("You have breached the limit!", 2);
		ft_putendl_fd("\"The player's goal is to collect every collectible \
present on the map, then escape chosing the shortest possible route\"", 2);
		free_heap_int_double_pointer(data->visited, data->row);
		free_heap_struct_s_map(data);
		exit(EXIT_FAILURE);
	}
}

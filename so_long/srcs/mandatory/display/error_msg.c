/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:18:33 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/05 19:58:49 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_helper.h"
#include "const_var.h"
#include "include.h"

void	error_class(int errno, char *msg)
{
	if (errno == AC_ERROR)
		msg = "Error: Too many arguments.";
	if (errno == FORMAT_ERROR)
		msg = "Error: Invalid file format.";
	if (errno == MAP_ERROR)
		msg = "Error\nThere is something wrong with the map.";
	if (errno == MAP_SHAPE_ERROR)
		msg = "Error\nMap should be in rectangular shape only.";
	if (errno == MAP_ELEMENT_ERROR)
		msg = "Error\nOnly 'P' 'E' 'C' '0' '1' are allowed as map element.";
	if (errno == MAP_ELEMENT_KIND_ERROR)
		msg = "Error\nAt least [one:'P'] [one:'E'] [one:'C'] '0' '1' needed";
	if (errno == MAP_PLAYER_ERROR)
		msg = "Error\nOnly one PLAYER is allowed.";
	if (errno == MAP_EXIT_ERROR)
		msg = "Error\nOnly one EXIT is allowed.";
	if (errno == MAP_WALL_ERROR)
		msg = "Error\nMap should be surrounded by walls.";
	if (errno == LOGIC_PLAYER_EXIT_ERROR)
		msg = "Error\nPLAYER cannot find EXIT.";
	if (errno == LOGIC_COLLECTIBLE_EXIT_ERROR)
		msg = "Error\nPLAYER must be able to collect ALL ITEMS.\n\
It is not possible to EXIT without collecting ALL ITEMS.";
	ft_putendl_fd(msg, 2);
}

void	exit_program(int errno)
{
	char	*msg;

	msg = NULL;
	if (errno != FD_OPEN_ERROR && errno != RESOLUTION_ERROR \
		&& errno != DYNAMIC_HEAP_ALLOCATION_ERROR)
		error_class(errno, msg);
	else if (errno == DYNAMIC_HEAP_ALLOCATION_ERROR \
			|| errno == RESOLUTION_ERROR)
	{
		if (errno == DYNAMIC_HEAP_ALLOCATION_ERROR)
			msg = "Error: Heap area is full, no more memory \
			allocations are allowed.";
		if (errno == RESOLUTION_ERROR)
			msg = "Error\nThis game has finite resolution.\n\
Please check your map.";
		ft_putendl_fd(msg, 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (errno == FD_OPEN_ERROR)
			msg = "Failed to open the map";
		perror(msg);
	}
	exit(EXIT_FAILURE);
}

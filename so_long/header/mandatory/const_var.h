/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_var.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:01:24 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 17:48:50 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_VAR_H
# define CONST_VAR_H

# define TRUE 1
# define FALSE 0

# define SUCCESS 1
# define FAIL 0

// MLX
# define PIXEL 64
# define ROW_RESOLUTION_MAX 1408
# define COL_RESOLUTION_MAX 2560

// MAIN
# define ONE_FILE 2
# define IDENTICAL 0

// MAP
# define EOF 0
# define OPEN_ERROR -1
# define PEC01 127
# define PEC1 119
# define VISITED 1
# define NOT_VISITED 0

// DFS
# define VALID 1
# define INVALID 0

// BFS
# define SEARCH_ITEM 0

// ELEMENTS
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PATH '0'
# define WALL '1'

// DELTA
# define VERTICLE 0
# define HORIZONTAL 1
# define NORTH -1
# define SOUTH 1
# define WEST -1
# define EAST 1
# define STAY 0

// FREE_MAP
# define STOP -1

// PLAYER
# define ROW 0
# define COL 1

// DIRECTION
# define ESC 53
# define UP_ASDW 13
# define UP_ARROW 126
# define LEFT_ASDW 0
# define LEFT_ARROW 123
# define DOWN_ASDW 1
# define DOWN_ARROW 125
# define RIGHT_ASDW 2
# define RIGHT_ARROW 124

// ERROR
enum e_error {
	AC_ERROR = 2,
	FORMAT_ERROR,
	MAP_ERROR,
	MAP_SHAPE_ERROR,
	MAP_ELEMENT_ERROR,
	MAP_ELEMENT_KIND_ERROR,
	MAP_PLAYER_ERROR,
	MAP_EXIT_ERROR,
	MAP_WALL_ERROR,
	LOGIC_PLAYER_EXIT_ERROR,
	LOGIC_COLLECTIBLE_EXIT_ERROR,
	DYNAMIC_HEAP_ALLOCATION_ERROR,
	RESOLUTION_ERROR,
	FD_OPEN_ERROR = 32
};

#endif

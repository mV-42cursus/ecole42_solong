/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:01:28 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 22:59:19 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft.h"

typedef struct s_player {
	int	row;
	int	col;
	int	collected;
	int	total_movement;
	int	cur_distance;
	int	bfs_distance;
}	t_player;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_map {
	t_mlx		gpu;
	t_player	player;
	t_queue		*queue_loc;
	int			exit_loc[2];
	int			item_loc[2];
	int			delta[2][4];
	char		**map;
	int			**visited;
	int			row;
	int			col;
	int			items;
}	t_map;

#endif

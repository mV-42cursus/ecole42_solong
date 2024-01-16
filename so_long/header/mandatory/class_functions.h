/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:01:42 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 22:56:56 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FUNCTIONS_H
# define CLASS_FUNCTIONS_H

# include "structure.h"
# include "libft.h"

/* display */
void	error_class(int errno, char *msg);
void	exit_program(int errno);
void	finish_process(t_map *data, int flag);

/* graphics */
void	xpm_to_img_to_window(t_map *data, int row, int col, char *img_file);
void	init_img_map(t_map *data, int row_idx, int col_idx);
void	player_movement(t_map *data, int col, int row);
void	apply_graphics(t_map *data, int idx);

int		key_command(int key_code, t_map *data);
void	graphics_apply_movement(t_map *data, int idx);
void	exit_bfs_distance(t_map *data, int loc[2], int idx);
void	search_for_item(t_map *data, int loc[2], int idx);
void	player_movement(t_map *data, int col, int row);
int		close_mlx_window(t_map *data);

/* logic */
int		find_destination(struct s_map *data, int row, int col, int destination);
void	bfs(struct s_map *data, int loc[2], int destination);
void	target_to_destination(struct s_map *data, int loc[2], int target);

void	validate_logic(struct s_map *data);
void	exhaustive_search(struct s_map *data);
void	logic_collectibles_to_exit(struct s_map *data, int target_loc[2]);
void	logic_player_to_exit(struct s_map *data, int target_loc[2]);
void	surrounded_by_wall(char **map, int row, int col);

/* main */
int		main(int ac, char *av[]);

/* parse */
char	**init_map(char *file_name);
void	init_data(struct s_map **data, char *av[]);
void	init_visited(struct s_map *data);

void	valid_format(char *file_name);
int		new_lines(int fd);
int		calculate_column(char *str);
void	is_valid_shape(char str[]);
void	parse_element(char c, char *pec01);

void	is_valid_element(char *buffer);

/* utils */
int		calculate_row(char **map, int row);
int		calculate_col(char **map, int row, int col);
void	calculate_target_loc(struct s_map *data, int player[2], int target);
int		calculate_items(char **map, int row, int col);

void	free_heap_struct_s_map(t_map *data);
void	free_heap_int_double_pointer(int **buffer, int row);
void	free_queue(struct s_map *data);

#endif

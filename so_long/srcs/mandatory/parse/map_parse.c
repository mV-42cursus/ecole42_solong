/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:18:54 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/05 19:59:04 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "class_helper.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

void	valid_format(char *file_name)
{
	while (*file_name)
		file_name++;
	file_name -= 4;
	if (ft_strcmp(file_name, ".ber") != IDENTICAL)
		exit_program(FORMAT_ERROR);
}

int	new_lines(int fd)
{
	int		new_lines;
	int		byte;
	char	c[2];

	new_lines = 0;
	byte = 0;
	while (1)
	{
		byte = read(fd, c, 1);
		if (byte == 0)
			break ;
		c[1] = '\0';
		if (c[0] == '\n')
			new_lines++;
	}
	return (new_lines);
}

int	calculate_column(char *str)
{
	int	i;
	int	col;

	i = 0;
	col = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
		{
			col = i - 1;
			break ;
		}
	}
	return (col);
}

void	is_valid_shape(char str[])
{
	int	len;
	int	col;
	int	i;
	int	k;

	col = calculate_column(str);
	len = ft_strlen(str);
	i = -1;
	k = 0;
	while (++i < len + 1)
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			if (k != col)
				exit_program(MAP_SHAPE_ERROR);
			k = 0;
			continue ;
		}
		k++;
	}
}

void	parse_element(char c, char *pec01)
{
	if (c == 'P')
	{
		if (ft_is_bit_set_7(*pec01, 0))
			exit_program(MAP_PLAYER_ERROR);
		*pec01 |= (1 << 0);
	}
	if (c == '\n')
		*pec01 |= (1 << 5);
	if (c == '\n' && ft_is_bit_set_7(*pec01, 5))
		*pec01 |= (1 << 6);
	else if (c == 'E')
	{
		if (ft_is_bit_set_7(*pec01, 1))
			exit_program(MAP_EXIT_ERROR);
		*pec01 |= (1 << 1);
	}
	else if (c == 'C')
		*pec01 |= (1 << 2);
	else if (c == '0')
		*pec01 |= (1 << 3);
	else if (c == '1')
		*pec01 |= (1 << 4);
	else
		return ;
}

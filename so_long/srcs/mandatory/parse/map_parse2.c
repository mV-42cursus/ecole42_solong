/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:53:33 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/05 19:59:06 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "class_functions.h"
#include "class_helper.h"
#include "const_var.h"
#include "include.h"
#include "structure.h"

void	is_valid_element(char *buffer)
{
	char	pec01;

	pec01 = 0;
	while (*buffer)
	{
		if (*buffer == 'P' || *buffer == 'E' || *buffer == 'C' \
			|| *buffer == '0' || *buffer == '1' || *buffer == '\n')
			parse_element(*buffer, &pec01);
		else
			exit_program(MAP_ELEMENT_ERROR);
		buffer++;
	}
	if (pec01 != PEC01)
	{
		if (pec01 == PEC1)
			return ;
		exit_program(MAP_ELEMENT_KIND_ERROR);
	}
}

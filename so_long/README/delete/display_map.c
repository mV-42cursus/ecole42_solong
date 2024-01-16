/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:24:07 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/28 20:37:37 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	display_map(char **map)
{
	int i = 0;
	int k = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
			printf("%c ", map[i][k++]);
		printf("\n");
		i++;
	}
}
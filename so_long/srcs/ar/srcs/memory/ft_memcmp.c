/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:42 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:22:13 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (n != 0)
	{
		p1 = s1;
		p2 = s2;
		while (n)
		{
			if (*p1 != *p2)
				return (*p1 - *p2);
			p1++;
			p2++;
			n--;
		}
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 0), 
//                               ft_memcmp("teste", "testex", 0));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 1), 
//                               ft_memcmp("teste", "testex", 1));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 2), 
//                               ft_memcmp("teste", "testex", 2));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 3), 
//                               ft_memcmp("teste", "testex", 3));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 4), 
//                               ft_memcmp("teste", "testex", 4));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 5), 
//                             ft_memcmp("teste", "testex", 5));
//     printf("[%d] <-> [%d]\n", memcmp("testexaa", "testeax", 6), 
//                               ft_memcmp("testexaa", "testeax", 6));
//     printf("[%d] <-> [%d]\n", memcmp("atestexaa", "etesteax", 6), 
//                               ft_memcmp("atestexaa", "etesteax", 6));
// }

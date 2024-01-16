/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:05:18 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:22:03 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
//     printf("(CALLOC)      [%p]", calloc(5, sizeof(int)));
//     printf(" -> [%s] ", (char *)calloc(5, sizeof(int)));
//     printf(" || [SIZE = %zu]\n", sizeof(calloc(5, sizeof(int))));
//     printf("(FT_CALLOC)   [%p]", ft_calloc(5, sizeof(int)));
//     printf(" -> [%s] ", (char *)ft_calloc(5, sizeof(int)));
//     printf(" || [SIZE = %zu]\n", sizeof(ft_calloc(5, sizeof(int))));
//     puts("");
//     printf("(CALLOC)      [%p]", calloc(5, 0));
//     printf(" -> [%s] ", (char *)calloc(5, 0));
//     printf(" || [SIZE = %zu]\n", sizeof(calloc(5, 0)));
//     printf("(FT_CALLOC)   [%p]", ft_calloc(5, 0));
//     printf(" -> [%s] ", (char *)ft_calloc(5, 0));
//     printf(" || [SIZE = %zu]\n", sizeof(ft_calloc(5, 0)));
//     puts("");
//     printf("(CALLOC)      [%p]", calloc(0, sizeof(int)));
//     printf(" -> [%s] ", (char *)calloc(0, sizeof(int)));
//     printf(" || [SIZE = %zu]\n", sizeof(calloc(0, sizeof(int))));
//     printf("(FT_CALLOC)   [%p]", ft_calloc(0, sizeof(int)));
//     printf(" -> [%s] ", (char *)ft_calloc(0, sizeof(int)));
//     printf(" || [SIZE = %zu]\n", sizeof(ft_calloc(0, sizeof(int))));
//     printf("(CALLOC)      [%p]", calloc(0, sizeof(int)));
//     puts("");
//     printf("(CALLOC)      [%p]", calloc(0, 0));
//     printf(" -> [%s] ", (char *)calloc(0, 0));
//     printf(" || [SIZE = %zu]\n", sizeof(calloc(0, 0)));
//     printf("(FT_CALLOC)   [%p]", ft_calloc(0, 0));
//     printf(" -> [%s] ", (char *)ft_calloc(0, 0));
//     printf(" || [SIZE = %zu]\n", sizeof(ft_calloc(0, 0)));
//     printf("(CALLOC)      [%p]", calloc(0, 0));
//     puts("");
//     return (0);
// }

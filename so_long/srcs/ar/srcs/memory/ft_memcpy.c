/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:10:58 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:22:15 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	i = 0;
	if (dest == src || n == 0)
		return (dest);
	while (n-- > 0)
	{
		*dest_cpy++ = *src_cpy++;
		i++;
	}
	dest_cpy = dest_cpy - i;
	return ((void *)dest);
}

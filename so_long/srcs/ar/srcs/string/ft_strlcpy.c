/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:06:58 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:23:05 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while ((len + 1 < size) && src[len])
	{
		dst[len] = src[len];
		len++;
	}
	if (size != 0)
		dst[len] = '\0';
	while (src[len])
		len++;
	return (len);
}

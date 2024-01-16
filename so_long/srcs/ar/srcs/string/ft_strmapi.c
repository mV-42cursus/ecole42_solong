/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:08:40 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:23:12 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	char			*buffer;

	buffer = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!buffer)
		return (NULL);
	buffer[ft_strlen(s)] = '\0';
	idx = -1;
	while (s[++idx])
		buffer[idx] = f(idx, s[idx]);
	return (buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:18:51 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:20:53 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

// int main()
// {
// 	ft_putendl_fd("lorem ipsum dolor sit amet", 2);
// 	ft_putendl_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
// 	ft_putendl_fd("", 2);
// 	ft_putendl_fd("lorem ipsum do\0lor sit amet", 1);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:11:10 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:20:59 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

// int main()
// {
// 	ft_putstr_fd("hello world!\n", 0);
// 	ft_putstr_fd("hello world!\n", 1);
// 	ft_putstr_fd("hello world!\n", 2);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:38:22 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:20:51 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// int main()
// {
//     int i = 96;
//     while (++i <= 122)
//         ft_putchar_fd(i, 0);
//     i = 96;
// 	write(1, "\n", 1);
//     while (++i <= 122)
//         ft_putchar_fd(i, 1);
//     i = 96;
// 	write(1, "\n", 1);
//     while (++i <= 122)
//         ft_putchar_fd(i, 2);
// }

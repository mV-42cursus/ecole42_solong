/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:36:44 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:21:26 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_decimal(unsigned int nbr)
{
	nbr = nbr + '0';
	return (write(1, &nbr, 1));
}

int	ft_put_decimal(unsigned int nbr)
{
	int	res;

	res = 0;
	if (nbr > 9)
	{
		res = ft_put_decimal(nbr / 10);
		if (res == -1)
			return (-1);
	}
	res = ft_display_decimal(nbr % 10);
	if (res == -1)
		return (-1);
	return (1);
}

int	display_decimal(va_list args)
{
	unsigned int	num;
	int				len;
	int				res;

	len = 0;
	num = (unsigned int)va_arg(args, unsigned int);
	res = ft_put_decimal(num);
	if (res == -1)
		return (-1);
	if (num == 0)
		return (1);
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	display_percent_sign(void)
{
	return (write(1, "%", 1));
}

int	ft_display_nbr(long long nbr)
{
	nbr = nbr + '0';
	return (write(1, &nbr, 1));
}

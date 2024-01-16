/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_original.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:50:58 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:22:23 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_atoll(const char *nptr)
{
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = sign * (-1);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = (10 * res) + (*nptr - '0');
		nptr++;
	}
	return ((sign) * res);
}

int	ft_atoi_original(const char *nptr)
{
	return (ft_atoll(nptr));
}

//#include <stdio.h>
//int main()
//{
//	printf("%d\n", ft_atoi_original("\t\n\r\v\fd469 \n"));
//	printf("%d\n", ft_atoi_original("2147483647"));
//	printf("%d\n", ft_atoi_original("\t\n\r\v\f  469 \n"));
//	printf("%d\n", ft_atoi_original("\e475"));
//	printf("%d\n", ft_atoi_original("546:5"));
//	printf("%d\n", ft_atoi_original("546:5"));
//}

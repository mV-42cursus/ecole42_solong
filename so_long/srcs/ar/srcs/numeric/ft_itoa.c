/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:50 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:22:32 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_len(int n)
{
	int	len;

	if (n <= 0)
	{
		n = n *(-1);
		len = 1;
	}
	else
		len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_positive(int n)
{
	char	*res;
	int		last_idx;

	res = (char *)malloc(sizeof(char) * (ft_digit_len(n) + 1));
	if (!res)
		return (NULL);
	res[ft_digit_len(n)] = '\0';
	last_idx = ft_digit_len(n) - 1;
	while (n)
	{
		res[last_idx] = (n % 10) + '0';
		last_idx--;
		n = n / 10;
	}
	return (res);
}

static char	*ft_zero_negative(int n)
{
	char	*res;
	int		last_idx;

	res = (char *)malloc(sizeof(char) * (ft_digit_len(n) + 1));
	if (!res)
		return (NULL);
	res[ft_digit_len(n)] = '\0';
	if (n == 0)
	{
		res[0] = 0 + '0';
		return (res);
	}
	last_idx = ft_digit_len(n) - 1;
	n = n * (-1);
	while (n)
	{
		res[last_idx] = (n % 10) + '0';
		last_idx--;
		n = n / 10;
	}
	res[0] = '-';
	return (res);
}

static char	*ft_int_min(void)
{
	char	*int_min;

	int_min = (char *)malloc(sizeof(char) * (11 + 1));
	if (!int_min)
		return (NULL);
	int_min[0] = '-';
	int_min[1] = '2';
	int_min[2] = '1';
	int_min[3] = '4';
	int_min[4] = '7';
	int_min[5] = '4';
	int_min[6] = '8';
	int_min[7] = '3';
	int_min[8] = '6';
	int_min[9] = '4';
	int_min[10] = '8';
	int_min[11] = '\0';
	return (int_min);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_int_min());
	else if (n > 0)
		return (ft_positive(n));
	else
		return (ft_zero_negative(n));
}

// int main()
// {
//     printf("%s\n", ft_itoa(-2147483648));
//     printf("%s\n", ft_itoa(-2147483647));
//     printf("%s\n", ft_itoa(-42));
//     printf("%s\n", ft_itoa(0));
//     printf("%s\n", ft_itoa(42));
//     printf("%s\n", ft_itoa(2147483647));
// }

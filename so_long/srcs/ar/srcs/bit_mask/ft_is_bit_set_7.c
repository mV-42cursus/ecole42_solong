/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bit_set_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:47:48 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/28 20:52:12 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_bit_set_7(char variable, int bit_position)
{
	char	bitmask;
	char	result;

	bitmask = 1 << bit_position;
	result = variable & bitmask;
	return (result != 0);
}

// #include <stdio.h>
// int main()
// {
// 	unsigned char bit;

// 	bit = 0;
// 	printf("%d\n", bit);
// 	bit |= (1 << 0);
// 	printf("%d\n", bit);
// 	bit |= (1 << 1);
// 	printf("%d\n", bit);
// 	bit |= (1 << 2);
// 	printf("%d\n", bit);
// 	bit |= (1 << 3);
// 	printf("%d\n", bit);
// 	bit |= (1 << 4);
// 	printf("%d\n", bit);
// 	bit |= (1 << 5);
// 	printf("%d\n", bit);
// 	bit |= (1 << 6);
// 	printf("%d\n", bit);
// 	bit |= (1 << 7);
// 	printf("value of current bit %d\n", bit);

// 	printf("%d\n", ft_is_bit_set_7(bit, 6));
// 	return (0);
// }

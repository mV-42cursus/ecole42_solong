/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:24:44 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/26 19:38:58 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_bit_set(char variable, int bit_position) 
{
    // Create a bitmask with only the desired bit set to 1
    char bitmask = 1 << bit_position;

    // Perform a bitwise AND operation to check the bit value
    char result = variable & bitmask;

    // Return true if the bit is set to 1, otherwise false
    return (result != 0);
}

int main()
{
	unsigned char bit;

	bit = 0;
	// printf("%d\n", bit);
	// bit |= (1 << 0);
	// printf("%d\n", bit);
	// bit |= (1 << 1);
	// printf("%d\n", bit);
	// bit |= (1 << 2);
	// printf("%d\n", bit);
	// bit |= (1 << 3);
	// printf("%d\n", bit);
	// bit |= (1 << 4);
	// printf("%d\n", bit);
	// bit |= (1 << 5);
	// printf("%d\n", bit);
	// bit |= (1 << 6);
	// printf("%d\n", bit);
	bit |= (1 << 7);
	printf("value of current bit %d\n", bit);

	printf("%d\n", is_bit_set(bit, 6));

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bit_set_8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:47:48 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:19:53 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_bit_set_8(unsigned char variable, int bit_position)
{
	unsigned char	bitmask;
	unsigned char	result;

	bitmask = 1 << bit_position;
	result = variable & bitmask;
	return (result != 0);
}

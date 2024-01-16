/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:18:13 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:22:48 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *string1, const char *string2)
{
	int	i;

	i = 0;
	while (string1[i] && string1[i] == string2[i])
		i++;
	return (string1[i] - string2[i]);
}

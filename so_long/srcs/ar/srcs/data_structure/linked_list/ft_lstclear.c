/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:18:51 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/28 20:26:56 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **lst, void (*del)(void*))
{
	t_node	*ptr;

	while (*lst)
	{
		ptr = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(ptr);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:36:17 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/28 20:27:28 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_node	*node_check(void *value, t_node *begin_lst, void (*del)(void *))
{
	del(value);
	ft_lstclear(&begin_lst, del);
	return (NULL);
}

t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node	*begin_lst;
	t_node	*node;
	void	*value;

	begin_lst = NULL;
	node = NULL;
	while (lst)
	{
		value = f(lst->content);
		if (value)
		{
			node = ft_lstnew(value);
			if (!node)
				return (node_check(value, begin_lst, del));
			ft_lstadd_back(&begin_lst, node);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&begin_lst, del);
			return (NULL);
		}
	}
	return (begin_lst);
}

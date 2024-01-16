/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:08:26 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/28 20:26:46 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	t_node	*ptr;

	if (!new)
		return ;
	ptr = new;
	ptr->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main()
// {
// 	t_node *head;
// 	t_node *new;

// 	head = (t_node *)malloc(sizeof(t_node) * 1);
// 	new = (t_node *)malloc(sizeof(t_node) * 1);
// 	head->content = (void *)"Wolrd";
// 	head->next = NULL;
// 	new->content = (void *)"Hello";
// 	new->next = NULL;
// 	ft_lstadd_front(&head, new);
// 	while (head)
// 	{
// 		printf("[%p]\t->\t", head->next);
// 		printf("[%s]\n", (char *)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }
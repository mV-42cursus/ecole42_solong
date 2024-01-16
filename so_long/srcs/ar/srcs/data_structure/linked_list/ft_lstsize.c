/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:43:53 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/28 20:27:42 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_node *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

// #include <stdio.h>
// #include "ft_lstnew.c"
// #include "ft_lstadd_front.c"
// void ft_display_lst(t_node *head)
// {
// 	while (head)
// 	{
// 		printf("[%p]\t", head);
// 		printf("[%s]\n", head->content);
// 		head = head->next;
// 	}
// }
// int main()
// {
// 	t_node *head = ft_lstnew("world");
// 	t_node *node1 = ft_lstnew("hello");

// 	puts("");
// 	ft_lstadd_front(&head, node1);
// 	ft_display_lst(head);
// 	printf("\nft_lstsize(t_node *head) = [%d]\n", ft_lstsize(head));
// 	puts("");
// 	return (0);
// }
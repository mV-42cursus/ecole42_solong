/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:52:01 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/28 20:27:36 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(void *content)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = (t_node *)malloc(sizeof(t_node) * 1);
	if (!ptr)
		return (NULL);
	ptr->content = (void *)content;
	ptr->next = NULL;
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
// 	puts("\n----------[INT ARRAY TEST]----------\n");
// 	int i = 42;
// 	t_node *p = ft_lstnew((void *)(&i));
// 	int *arr = (int *)(p->content);
// 	printf("p->content   =  [%d]\n", arr[0]);
// 	printf("p->next      =  [%p]\n", p->next);
// 	puts("\n----------[CHAR ARRAY TEST]----------\n");
// 	char *str = "Hello World!";
// 	t_node *p1 = ft_lstnew((void *)str);
// 	printf("p1->content  =  [%s]\n", (char *)p1->content);
// 	printf("p1->next     =  [%p]\n\n", p1->next);
// 	puts("-------------------------------------------");
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:09:33 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 20:16:34 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	enqueue(struct s_queue *queue, void *data)
{
	struct s_node	*node;
	struct s_node	*p;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	if (!node)
		exit(EXIT_FAILURE);
	node->content = data;
	node->next = NULL;
	if (queue == NULL)
		exit(EXIT_FAILURE);
	if (queue->front == NULL && queue->rear == NULL)
	{
		queue->front = node;
		queue->rear = node;
		p = queue->front;
	}
	else
	{
		p = queue->rear;
		while (p->next)
			p = p->next;
		p->next = node;
		node->next = NULL;
		queue->front = node;
	}
}

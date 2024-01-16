/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:09:31 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/06 18:09:16 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*dequeue(struct s_queue *queue)
{
	t_node	*tmp;
	void	*ret;

	if (queue == NULL)
		exit(EXIT_FAILURE);
	if (queue->rear == NULL)
		return (NULL);
	tmp = queue->rear;
	ret = tmp->content;
	if (queue->rear == queue->front)
	{
		queue->front = NULL;
		queue->rear = NULL;
		free(tmp);
		return (ret);
	}
	queue->rear = queue->rear->next;
	free(tmp);
	return (ret);
}

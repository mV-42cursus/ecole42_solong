/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:14:58 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/06 00:36:15 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	void *data;
	data = (void *)"asdf";
	printf("%p\n", data);
	printf("%c\n", *((char *)data));
	write(1, data, 1);
	char *str = (char *)data;
	printf("\n%c", str[0]);
	// void *data;
	// char c = 'c';
	// data = &c;
	// printf("%p\n", data);
	// printf("%c\n", *((char *)data));
	// write(1, data, 1);
	// char *str = (char *)data;
	// printf("\n%c", str[0]);
}

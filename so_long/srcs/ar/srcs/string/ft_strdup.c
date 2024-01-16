/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:06:13 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/27 00:22:50 by dong-kim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		idx;
	char	*dest;

	len = ft_strlen(s);
	idx = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (idx < len)
	{
		dest[idx] = s[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

// #include <stdio.h>
// int	main()
// {
// 	char *str;
// 	str = ft_strdup("");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("hello 42");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("fcM4LHyYVwX6HGy3UlExvn0zBUnZyKDujHow8EeZazleaJ");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("88oy3xTw01JoEtmMsWc9H2QFmKfLNrdr3myWC");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("KnitN9pcyccGPGJXmSeqxd6u2SMlm");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("EuR8jbXcYAlTacPVa0M1814V1PjGmngWcPu8nRVoT9DSV");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("Nld6Ks4aSqWC5iK9");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("uhHFp3d5MvW5TgObTaFAYM6HcqGJAXjUqXJOXcl");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("2aDGL8hHTmK4p2U");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strdup("cVXYQJZEJUYZbNBJXCkKPA2HRmLHeXDXWl");
// 	printf("%s\n", str);
// 	free(str);
// }

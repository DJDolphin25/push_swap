/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:10:48 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/09 21:40:03 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t				i;
	size_t				src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && *src)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (src_len);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	char	d[100];
	const char	*s;

	s = " ";

	printf("The lenght is: %zu\n", ft_strlcpy(d, s, 0));
	printf("The lenght is: %zu\n", strlcpy(d, s, 0));
	return (0);
}*/
//Use -lbsd to compile

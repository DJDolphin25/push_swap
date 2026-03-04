/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:41:00 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/09 21:19:06 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	original_dst_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	original_dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + src_len);
	dst += dst_len;
	while (*src && dst_len + 1 < size)
	{
		*dst++ = *src++;
		dst_len++;
	}
	*dst = '\0';
	return (src_len + original_dst_len);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	char	dst[2];

	printf("The lenght of the string is: %zu\n", ft_strlcat(dst, "Good", 4));
	printf("The lenght of the string is: %zu\n", strlcat(dst, "Good", 4));
	return (0);
}*/

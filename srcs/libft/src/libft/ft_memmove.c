/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:21:03 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 18:41:05 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d <= s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dst);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	char		dst [] = "oldstring";
	const char	src [] = "newstring";
	
	printf("Memory direction before moving is: %p\n", src);
	printf("Memory direction after moving is: %p\n", ft_memmove(dst, src, 8));
	printf("Memory direction after moving is: %p\n", memmove(dst, src, 8));
	return (0);
}*/

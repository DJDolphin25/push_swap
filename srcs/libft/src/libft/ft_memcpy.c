/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:41:59 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 18:33:50 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>
 
int	main()
{
	char	dst[500];

	printf("%p\n", ft_memcpy(dst, "Hello", 2)); 
	printf("%p\n", memcpy(dst, "Hello", 2));
	//Use %p when dealing with memory or if you have to cast
	return (0);
}*/

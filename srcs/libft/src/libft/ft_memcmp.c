/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:20:45 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/09 21:33:05 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
		n--;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	const char	*s1 = "54782";
	const char	*s2 = "45782";
	size_t		n = 7;

	printf("The difference is %d\n", ft_memcmp(s1, s2, n));
	printf("The difference is %d\n", memcmp(s1, s2, n));
	return (0);
}*/

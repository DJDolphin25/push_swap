/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:21:01 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 18:44:54 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*l;
	const char	*b;
	const char	*b_start;
	size_t		i;

	if (*little == '\0')
		return ((char *)big);
	while (*big && len > 0)
	{
		b_start = big;
		b = big;
		l = little;
		i = len;
		while (i > 0 && *b && *l && *l == *b)
		{
			b++;
			l++;
			i--;
		}
		if (*l == '\0')
			return ((char *)b_start);
		big++;
		len--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	const char	large[100] = "Foo Bar Baz";
	const char	small[100] = "Bar";
	
	printf("Found: %s\n", ft_strnstr(large, small, 11));
	printf("Found %s\n", strnstr(large, small, 11));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:20:23 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/09 21:32:19 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*t;
	unsigned char			d;

	t = (const unsigned char *)s;
	d = (unsigned char)c;
	while (n-- > 0)
	{
		if (*t == d)
			return ((void *)t);
		t++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	const char	s[100] = "Hello World";
	int		c = 'l';
	size_t		n = 9;

	printf("Memory address after the finding is: %p\n",ft_memchr(s, c, n));
       printf("Memory address after the finding is: %p\n", memchr(s, c, n));	

}*/

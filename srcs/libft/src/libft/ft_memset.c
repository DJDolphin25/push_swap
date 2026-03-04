/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:55:22 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/09 21:18:14 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		*ptr++ = c;
		i++;
	}
	return (s);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	char	s[100] = "Hola que tal";

	printf("%p\n", memset(s, '2', 3));
	printf("%p\n", ft_memset(s, '2', 3));
	return (0);
}*/

/*int	main()
{
	char	p[500] = "Hola que tal";
	char	*s = p;
	
	ft_memset(s, 'a', 7);
	while (*s)
	{
		printf("%c", *s);
		s++;
	}
	return (0);
}*/

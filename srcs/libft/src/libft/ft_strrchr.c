/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:30:57 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/08 21:14:10 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = NULL;
	while (*s)
	{
		if (*s == (char)c)
			p = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)p);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	const char	*s = "A couple of moments";
	char 		*result;
	int		c = '\0';

	result = ft_strrchr(s, c);
	printf("The last ocurrence of %c in %s is: %s\n", c, s, result);
	result = strrchr(s, c);
	printf("The last ocurrence of %c in %s is: %s\n", c, s, result);
	return (0);
}*/

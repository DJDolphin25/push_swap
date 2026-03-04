/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:58:00 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/08 21:16:52 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char 	*s = "A couple of moments ago";
  	char		*result;
	int		c = 126;
	
	result = ft_strchr(s, c);
	printf("The first ocurrence of '%c' in '%s' is: %s\n", c, s, result);
	result = strchr(s, c);
	printf("The first ocurrence of '%c' in '%s' is: %s\n", c, s, result);
	return (0);
}*/

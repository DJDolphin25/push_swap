/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:28:57 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/11 22:52:26 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	char	*start_t;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		t = malloc(1);
		if (!t)
			return (NULL);
		*t = '\0';
		return (t);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	t = malloc(len + 1);
	if (!t)
		return (NULL);
	start_t = t;
	s += start;
	while (*s && len--)
		*t++ = *s++;
	*t = '\0';
	return (start_t);
}

/*#include <stdio.h>

int	main()
{
	char	s[] = "I like pasta and chocolate";
	
	printf("Substring is: %s\n", ft_substr(s, 50, 10));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:53:22 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/12 12:40:01 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	joined_string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_string)
		return (NULL);
	start = joined_string;
	while (*s1)
		*joined_string++ = *s1++;
	while (*s2)
		*joined_string++ = *s2++;
	*joined_string = '\0';
	return (start);
}

/*#include <stdio.h>

int	main()
{
	char const	s1[] = "I like";
	char const	s2[] = "chocolate";

	printf("Joined string is: %s\n", ft_strjoin(s1, s2));
	return (0);
}*/

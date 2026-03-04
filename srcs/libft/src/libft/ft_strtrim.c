/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:40:48 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 19:50:39 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new_string;
	char		*start_new_string;
	char const	*start;
	char const	*end;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	while (*start && in_set(*start, set))
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (end >= start && in_set(*end, set))
		end--;
	new_string = malloc((end - start + 1) + 1);
	if (!new_string)
		return (NULL);
	start_new_string = new_string;
	while (start <= end)
		*new_string++ = *start++;
	*new_string = '\0';
	return (start_new_string);
}

/*#include <stdio.h>

int	main()
{
	char const	s1[] = "++-8+-+I like++ chocolate+-+8++";
	char const	set[] = "+-";
	
	printf("Trimmed string is: %s\n", ft_strtrim(s1, set));
	return (0);
}*/

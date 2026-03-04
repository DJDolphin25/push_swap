/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:18:44 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/08 22:19:59 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	const char	*s1 = "";
	const char	*s2 = " ";
	size_t		n = 8;

	printf("The difference is: %d\n", ft_strncmp(s1, s2, n));
	printf("The difference is: %d\n", strncmp(s1, s2, n));
	return (0);
}*/

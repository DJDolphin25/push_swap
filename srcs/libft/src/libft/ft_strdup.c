/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:09:40 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/11 19:32:46 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	char	*u;

	t = malloc(ft_strlen(s) + 1);
	if (!t)
		return (NULL);
	u = t;
	while (*s)
		*t++ = *s++;
	*t = '\0';
	return (u);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	a[] = "Buenas tardes";
	char	*b = ft_strdup(a);
	char	*c = strdup(a);

	printf("%s\n", b);
	printf("%s\n", c);
	return (0);
}*/

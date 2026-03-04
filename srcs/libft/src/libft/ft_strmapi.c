/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:07:39 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 19:41:19 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*#include <stdio.h>

char	f(unsigned int i, char c)
{
	char	str;
	(void)i;

	str = c + 1;
	return (str);
}

int main()
{
	char	str1[] = "abc";
	char	*str2;
	
	str2 = ft_strmapi(str1, f);
	printf("%s\n", str2);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:51:40 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 16:09:35 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
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

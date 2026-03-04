/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:08:40 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/09 21:16:55 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		*ptr++ = '\0';
		i++;
	}
}

/*#include <stdio.h>
#include <strings.h>

int	main()
{
	char	string[100] = "abcdefg";
	char	string1[100] = "abcdefg";

	printf("%s\n", string);
	printf("%s\n", string1);
	bzero(string, 4);
	ft_bzero(string1, 4);
	printf("%s\n", string);
	printf("%s\n", string1);
	return (0);
}*/

//For better verification print each byte 
/*int	main()
{
	char	string[100] = "abcdefg";
	int	i;

	i = 0;
	ft_bzero(string, 3);
	bzero(string, 3);
	while (i < 6)
	{
		if (i == '\0')
			printf("\\0");
		else
			printf("%c", *string);
	}
}*/

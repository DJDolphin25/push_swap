/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:14:57 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/11 19:08:27 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/*#include <stdio.h>

int	main()
{
	int	*ptr;
	int	*str;
	int	n = 5;
	int	i;
	
	ptr = ft_calloc(n, sizeof(int));
	str = calloc(n, sizeof(int));
	printf("Array elements after ft_calloc: ");
	i = 0;
	while (i < n)
	{
		printf("%d",ptr[i]);
		i++;
	}
	free(ptr);
	printf("\n");
	printf("Array elements after calloc : ");
	i = 0;
	while (i < n)
	{
		printf("%d", str[i]);
		i++;
	}
	free(str);
	return (0);
}*/

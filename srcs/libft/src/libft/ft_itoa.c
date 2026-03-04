/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:44:47 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 20:14:28 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(long n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*conversion(char *str, int sign, int len, long num)
{
	while (len > sign)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			sign;
	int			len;
	long int	num;

	sign = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		sign = 1;
	}
	len = count_numbers(num) + sign;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	conversion(str, sign, len, num);
	if (sign == 1)
		str[0] = '-';
	return (str);
}

/*#include <stdio.h>

int	main()
{
	int	n = 100000;
	
	printf("%s\n", ft_itoa(n));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:43:55 by theoppon          #+#    #+#             */
/*   Updated: 2025/12/22 19:29:07 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_numbers(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 15)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static char	*conversion(char *str, int len, unsigned int num)
{
	while (len > 0)
	{
		if ((num % 16) < 10)
			str[len - 1] = (num % 16) + '0';
		else
			str[len - 1] = (num % 16) + 'a' - 10;
		num /= 16;
		len--;
	}
	return (str);
}

int	print_hex_lowercase(int n)
{
	char				*str;
	int					len;
	int					res;
	unsigned int		num;

	num = (unsigned int)n;
	len = count_numbers(num);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	conversion(str, len, num);
	res = print_string(str);
	free(str);
	return (res);
}

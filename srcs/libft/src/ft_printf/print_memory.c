/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:36:20 by theoppon          #+#    #+#             */
/*   Updated: 2025/12/22 19:50:32 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_numbers(unsigned long n)
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

static char	*conversion(char *str, int len, unsigned long num)
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

int	print_memory(void *s)
{
	char			*str;
	int				len;
	int				res;
	unsigned long	num;

	if (!s)
		return (print_string("(nil)"));
	num = (unsigned long)s;
	len = count_numbers(num);
	str = malloc(len + 3);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 'x';
	conversion(str + 2, len, num);
	str[len + 2] = '\0';
	res = print_string(str);
	free(str);
	return (res);
}

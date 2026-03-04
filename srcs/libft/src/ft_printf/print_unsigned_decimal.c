/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:46:13 by theoppon          #+#    #+#             */
/*   Updated: 2025/12/07 20:02:50 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_numbers(unsigned int n)
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

static char	*conversion(char *str, int len, unsigned int n)
{
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

static char	*ft_uitoa(unsigned int n)
{
	char		*str;
	int			len;

	len = count_numbers(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	conversion(str, len, n);
	return (str);
}

int	print_unsigned_decimal(unsigned int n)
{
	char	*s;
	int		o;

	s = ft_uitoa(n);
	o = print_string(s);
	free(s);
	return (o);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 00:03:44 by theoppon          #+#    #+#             */
/*   Updated: 2025/12/07 19:12:01 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_decimal(int n)
{
	char	*s;
	int		o;

	s = ft_itoa(n);
	o = print_string(s);
	free(s);
	return (o);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:35:56 by theoppon          #+#    #+#             */
/*   Updated: 2025/12/07 19:17:29 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *c)
{
	int	counter;

	counter = 0;
	if (!c)
		return (print_string("(null)"));
	while (*c)
	{
		write(1, c++, 1);
		counter++;
	}
	return (counter);
}

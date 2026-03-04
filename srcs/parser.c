/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:16:03 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/04 23:33:09 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	error_msg(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	validate_single(char *num)
{
	long	result;
	int	sign;

	if (!num || *num == '\0')
		error_msg();
	sign = 1;
	if (*num == '+' || *num == '-')
	{
		if (*num == '-')
			sign = -1;
		num++;
	}
	if (!ft_isdigit(*num))
		error_msg();
	result = 0;
	while (*num)
	{
		if (!ft_isdigit(*num))
			error_msg();
		result = result * 10 + (*num - '0');
		if ((sign == 1 && result > 2147483647) || 
				(sign == -1 && -result < -2147483648))
			error_msg();
		num++;
	}
}

void	validate_all(int ac, char **av)
{
	int	*num;
	int	total;

	if (ac < 2)
		exit(1);
	total = count_numbers(ac, av);
	num = malloc(sizeof(int) * total);
	if (!num)
		error_msg();
	fill_numbers(num, ac, av);
	check_duplicates(num, total);
	free(num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:10:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/04 23:30:07 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	total;
	int	*num;
	t_stack	*stack;

	validate_all(ac, av);
	total = count_numbers(ac, av);
	num = malloc(sizeof(int) * total);
	if (!num)
		error_msg();
	fill_numbers(num, ac, av);
	stack = init_stack(num, total);
	free(num);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:10:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/22 18:39:36 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac < 2)
		return (1);
	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		error_msg();
	stacks->a = parse_stack(av);
	if (!stacks->a)
	{
		free(stacks);
		error_msg();
	}
	stacks->b = NULL;
	check_duplicates(stacks->a);
	stacks->tail_a = ft_lstlast(stacks->a);
	stacks->tail_b = NULL;
	if (is_sorted(stacks) == 0)
	{
		ft_lstclear(&stacks->a);
		free(stacks);
		return (0);
	}
	if (ft_lstsize(stacks->a) <= 5)
		sort_small(stacks);
	else
		sort_big(stacks);
	ft_lstclear(&stacks->a);
	ft_lstclear(&stacks->b);
	free(stacks);
	return (0);
}

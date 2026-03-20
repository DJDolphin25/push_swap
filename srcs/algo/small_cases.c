/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:22:56 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/20 16:47:22 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	sort_two(t_stack *stacks)
{
	if (ft_lstsize(stacks->a) == 2)
	{
		if (stacks->a->number > stacks->tail_a->number)
			sa(stacks);
	}
}

static void	sort_three(t_stack *stacks)
{
	if (stacks->a->number > stacks->a->next->number
		&& stacks->a->next->number > stacks->tail_a->number)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (stacks->a->number < stacks->a->next->number
		&& stacks->a->next->number > stacks->tail_a->number
		&& stacks->a->number > stacks->tail_a->number)
		rra(stacks);
	else if (stacks->a->number > stacks->a->next->number
		&& stacks->a->next->number < stacks->tail_a->number
		&& stacks->a->number > stacks->tail_a->number)
		ra(stacks);
	else if (stacks->a->number < stacks->a->next->number
		&& stacks->a->next->number > stacks->tail_a->number
		&& stacks->a->number < stacks->tail_a->number)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (stacks->a->number > stacks->a->next->number
		&& stacks->a->next->number < stacks->tail_a->number
		&& stacks->a->number < stacks->tail_a->number)
		sa(stacks);
}

static void	sort_five(t_stack *stacks)
{
	int	max;

	while (ft_lstsize(stacks->a) > 3)
	{
		max = find_max(stacks);
		move_to_top(stacks, max);
		pb(stacks);
	}
	sort_three(stacks);
	if (ft_lstsize(stacks->b) == 2)
	{
		pa(stacks);
		ra(stacks);
		pa(stacks);
		ra(stacks);
	}
	else
	{
		pa(stacks);
		ra(stacks);
	}
}

void	sort_small(t_stack *stacks)
{
	if (ft_lstsize(stacks->a) == 2)
		sort_two(stacks);
	else if (ft_lstsize(stacks->a) == 3)
		sort_three(stacks);
	else if (ft_lstsize(stacks->a) == 4 || ft_lstsize(stacks->a) == 5)
		sort_five(stacks);
}

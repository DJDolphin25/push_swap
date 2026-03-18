/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:22:56 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/18 23:38:24 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int find_max(t_stack *stacks)
{
    t_node *current = stacks->a;
    int max = current->number;

    while (current)
    {
        if (current->number > max)
            max = current->number;
        current = current->next;
    }
    return max;
}

static void move_to_top(t_stack *stacks, int value)
{
    while (stacks->a->number != value)
    {
        ra(stacks);  // Rota Stack A hasta que el valor esté en el tope
    }
}

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
	int	max1;
	int	max2;
	if (ft_lstsize(stacks->a) == 5)
	{
		max1 = find_max(stacks);
		move_to_top(stacks, max1);
		pb(stacks);
		max2 = find_max(stacks);
		move_to_top(stacks, max2);
		pb(stacks);
	}
	else if (ft_lstsize(stacks->a) == 4)
	{
		max1 = find_max(stacks);
		move_to_top(stacks, max1);
		pb(stacks);
	}
	sort_three(stacks);
	pa(stacks);
	while (stacks->a->number != max1)
		ra(stacks);
	if (ft_lstsize(stacks->a) == 5)
	{
		pa(stacks);
		while (stacks->a->number != max2)
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

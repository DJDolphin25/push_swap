/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 01:30:31 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/25 00:16:03 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rotate_both(t_stack *stacks, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stacks);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stacks);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	finish_rotations(t_stack *stacks, int cost_a, int cost_b, char dir)
{
	while (cost_a > 0)
	{
		ra(stacks);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(stacks);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(stacks);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stacks);
		cost_b++;
	}
	if (dir == 'a')
		pa(stacks);
	else
		pb(stacks);
}

void	execute_move(t_stack *stacks, int cost_a, int cost_b, char dir)
{
	rotate_both(stacks, &cost_a, &cost_b);
	finish_rotations(stacks, cost_a, cost_b, dir);
}

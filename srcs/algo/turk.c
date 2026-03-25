/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 00:34:07 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/25 20:15:39 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_cost	get_cheapest_from_a(t_stack *stacks)
{
	int		target_pos;
	t_cost	temp;
	t_cost	best;
	t_node	*current;

	current = stacks->a;
	best.total = 2147483647;
	while (current)
	{
		temp.value = current->number;
		temp.cost_in_a = cost_from_pos(ft_lstsize(stacks->a),
				get_position(stacks->a, temp.value));
		target_pos = find_target_in_b(stacks, temp.value);
		temp.cost_in_b = cost_from_pos(ft_lstsize(stacks->b), target_pos);
		temp.total = total_cost(temp.cost_in_a, temp.cost_in_b);
		if (temp.total < best.total)
			best = temp;
		current = current->next;
	}
	return (best);
}

static t_cost	get_cheapest_from_b(t_stack *stacks)
{
	int		target_pos;
	t_cost	temp;
	t_cost	best;
	t_node	*current;

	current = stacks->b;
	best.total = 2147483647;
	while (current)
	{
		temp.value = current->number;
		temp.cost_in_b = cost_from_pos(
				ft_lstsize(stacks->b), get_position(stacks->b, temp.value));
		target_pos = find_target_in_a(stacks, temp.value);
		temp.cost_in_a = cost_from_pos(ft_lstsize(stacks->a), target_pos);
		temp.total = total_cost(temp.cost_in_a, temp.cost_in_b);
		if (temp.total < best.total)
			best = temp;
		current = current->next;
	}
	return (best);
}

void	final_rotation(t_stack *stacks)
{
	int	pos;
	int	cost;

	pos = get_position(stacks->a, find_min(stacks->a));
	cost = cost_from_pos(ft_lstsize(stacks->a), pos);
	while (cost > 0)
	{
		ra(stacks);
		cost--;
	}
	while (cost < 0)
	{
		rra(stacks);
		cost++;
	}
}

void	move_b_to_a(t_stack *stacks)
{
	t_cost	cheapest;

	while (stacks->b)
	{
		cheapest = get_cheapest_from_b(stacks);
		execute_move(stacks, cheapest.cost_in_a, cheapest.cost_in_b, 'a');
	}
}

void	sort_big(t_stack *stacks)
{
	t_cost	cheapest;

	pb(stacks);
	pb(stacks);
	while (ft_lstsize(stacks->a) > 3)
	{
		cheapest = get_cheapest_from_a(stacks);
		execute_move(stacks, cheapest.cost_in_a, cheapest.cost_in_b, 'b');
	}
	sort_small(stacks);
	while (stacks->b)
		move_b_to_a(stacks);
	final_rotation(stacks);
}

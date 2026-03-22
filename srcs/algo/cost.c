/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 20:08:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/22 05:32:36 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	find_target_in_a(t_stack *stacks, int value)
{
	int		nb;
	int		best_nb;
	int		pos;
	t_node	*current;

	current = stacks->a;
	best_nb = 2147483647;
	pos = 0;
	while (current)
	{
		nb = current->number;
		if (nb > value && nb < best_nb)
		{
			pos = get_position(stacks->a, nb);
			best_nb = nb;
		}
		current = current->next;
	}
	if (best_nb == 2147483647)
		pos = get_position(stacks->a, find_min(stacks->a));
	return (pos);
}

int	find_target_in_b(t_stack *stacks, int value)
{
	int		nb;
	int		best_nb;
	int		pos;
	t_node	*current;

	current = stacks->b;
	best_nb = -2147483648;
	pos = 0;
	while (current)
	{
		nb = current->number;
		if (nb < value && nb > best_nb)
		{
			pos = get_position(stacks->b, nb);
			best_nb = nb;
		}
		current = current->next;
	}
	if (best_nb == -2147483648)
		pos = get_position(stacks->b, find_min(stacks->b));
	return (pos);
}

int	cost_a(t_stack *stacks, int value)
{
	int	pos;
	int	size;

	size = ft_lstsize(stacks->a);
	pos = get_position(stacks->a, value);
	if (pos <= size / 2)
		return (pos);
	else
		return (-(size - pos));
}

int	cost_b(t_stack *stacks, int value)
{
	int	pos;
	int	size;

	size = ft_lstsize(stacks->b);
	pos = find_target_in_b(stacks, value);
	if (pos <= size / 2)
		return (pos);
	else
		return (-(size - pos));
}

int	total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			return (ft_abs(cost_a));
		else
			return (ft_abs(cost_b));
	}
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

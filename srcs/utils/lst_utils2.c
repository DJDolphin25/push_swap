/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:22:31 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/22 03:31:41 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	find_min(t_node *stack)
{
	int		min;
	t_node	*current;

	current = stack;
	min = current->number;
	while (current)
	{
		if (current->number < min)
			min = current->number;
		current = current->next;
	}
	return (min);
}

int	get_position(t_node *stack, int value)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->number == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	move_to_top(t_stack *stacks, int value)
{
	int	pos;
	int	size;

	size = ft_lstsize(stacks->a);
	pos = get_position(stacks->a, value);
	if (pos <= size / 2)
	{
		while (stacks->a->number != value)
			ra(stacks);
	}
	else
	{
		while (stacks->a->number != value)
			rra(stacks);
	}
}

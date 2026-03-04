/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:22:31 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/04 23:23:18 by theoppon         ###   ########.fr       */
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

static t_node	*fill_stack(int *numbers, int total)
{
	t_node	*head;
	t_node	*prev;
	t_node	*curr;
	int	*ptr;
	int	*end;

	if (total <= 0)
		return (NULL);
	ptr = numbers;
	end = numbers + total;
	head = ft_lstnew(*ptr++);
	prev = head;
	while (ptr < end)
	{
		curr = ft_lstnew(*ptr++);
		prev->next = curr;
		curr->prev = prev;
		prev = curr;
	}
	return (head);
}

t_stack	*init_stack(int *numbers, int total)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		error_msg();
	stack->a = fill_stack(numbers, total);
	stack->b = NULL;
	return (stack);
}

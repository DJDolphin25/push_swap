/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:34:51 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/20 16:46:30 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap(t_node **head, t_node **tail)
{
	t_node	*first;
	t_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		*tail = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(t_stack *stacks)
{
	swap(&stacks->a, &stacks->tail_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stacks)
{
	swap(&stacks->b, &stacks->tail_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stacks)
{
	swap(&stacks->a, &stacks->tail_a);
	swap(&stacks->b, &stacks->tail_b);
	ft_printf("ss\n");
}

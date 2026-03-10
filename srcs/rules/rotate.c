/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:26:00 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/10 23:04:47 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rotate(t_node **head, t_node **tail)
{
	t_node	*top;

	if (!*head || !(*head)->next)
		return ;
	top = *head;
	*head = top->next;
	(*head)->prev = NULL;
	(*tail)->next = top;
	top->next = NULL;
	top->prev = *tail;
	(*tail) = top;
}

void	ra(t_stack *stacks)
{
	rotate(&(stacks->a), &(stacks->tail_a));
	ft_printf("ra\n");
}

void	rb(t_stack *stacks)
{
	rotate(&(stacks->b), &(stacks->tail_b));
	ft_printf("rb\n");
}

void	rr(t_stack *stacks)
{
	rotate(&(stacks->a), &(stacks->tail_a));
	rotate(&(stacks->b), &(stacks->tail_b));
	ft_printf("rr\n");
}

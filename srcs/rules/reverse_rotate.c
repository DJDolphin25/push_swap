/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:01:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/10 23:12:54 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	reverse_rotate(t_node **head, t_node **tail)
{
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	last = *tail;
	*tail = last->prev;
	(*tail)->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	(*head) = last;
}

void	rra(t_stack *stacks)
{
	reverse_rotate(&stacks->a, &stacks->tail_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stacks)
{
	reverse_rotate(&stacks->b, &stacks->tail_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stacks)
{
	reverse_rotate(&stacks->a, &stacks->tail_a);
	reverse_rotate(&stacks->b, &stacks->tail_b);
	ft_printf("rrr\n");
}

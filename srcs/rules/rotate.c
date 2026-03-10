/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:26:00 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/10 00:59:53 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ra(t_stack *stacks)
{
	t_node	*head;

	head = stacks->a;
	if (stacks->a)
	{
		if (head->next)
		{
			stacks->a = stacks->a->next;
			if (stacks->tail_a)
			{
				stacks->a->prev = NULL;
				stacks->tail_a->next = head;
				head->next = NULL;
				head->prev = stacks->tail_a;
				stacks->tail_a = head;
			}
			ft_printf("ra\n")
		}
	}
}

void	rb(t_stack *stacks)
{
	t_node	*head;

	head = stacks->b;
	if (stacks->b)
	{
		if (head->next)
		{
			stacks->b = stacks->b->next;
			if (stacks->tail_b)
			{
				stacks->b->prev = NULL;
				stacks->tail_b->next = head;
				head->next = NULL;
				head->prev = stacks->tail_b;
				stacks->tail_b = head;
			}
			ft_printf("rb\n")
		}
	}
}

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
	ft_printf("rr\n")
}

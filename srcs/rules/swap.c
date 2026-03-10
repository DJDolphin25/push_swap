/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:34:51 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/10 23:30:09 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;
	
	if (*head && (*head)->next)
	{
		ft_printf("swapped called\n");
		first = *head;
		second = (*head)->next;
		ft_printf("%d\n", first->number);
		ft_printf("%d\n", second->number);
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		*head = second;
		first->prev = second;
		if (first->next)
			first->next->prev = first;
		ft_printf("%d\n", first->number);
		ft_printf("%d\n", second->number);
	}
}

void	sa(t_stack *stacks)
{
	swap(&(stacks->a));
	ft_printf("sa\n");
}

void	sb(t_stack *stacks)
{
	swap(&(stacks->b));
	ft_printf("sb\n");
}

void	ss(t_stack *stacks)
{
	swap(&(stacks->a));
	swap(&(stacks->b));
	ft_printf("ss\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:35:05 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/10 00:27:23 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	pa(t_stack *stacks)
{
	t_node	*head;
	
	head = stacks->b;
	if (stacks->b)
	{	
		stacks->b = stacks->b->next;
		if (stacks->b)
			stacks->b->prev = NULL;
		lst_add_front((&(stacks->a)), head);
		ft_printf("pa\n")
	}
}

void	pb(t_stack *stacks)
{
	t_node  *head;
	
	head = stacks->a;
	if (stacks->a)
	{
		stacks->a = stacks->a->next;
		if (stacks->a)
			stacks->a->prev = NULL;
		lst_add_front((&(stacks->b)), head);
		ft_printf("pb\n")
	}
}


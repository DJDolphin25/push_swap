/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 21:10:41 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/20 16:50:03 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_sorted(t_stack *stacks)
{
	t_node	*curr;

	curr = stacks->a;
	if (!curr || !curr->next)
		return (0);
	while (curr->next)
	{
		if (curr->number > curr->next->number)
			return (1);
		curr = curr->next;
	}
	return (0);
}

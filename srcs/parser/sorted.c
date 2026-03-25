/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 21:10:41 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/25 19:46:23 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_sorted(t_stack *stacks)
{
	t_node	*curr;

	curr = stacks->a;
	if (!curr || !curr->next)
		return (1);
	while (curr->next)
	{
		if (curr->number > curr->next->number)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_free(t_node *head)
{
	ft_lstclear(&head);
	error_msg();
}

void	check_duplicates(t_node *head)
{
	t_node	*i;
	t_node	*j;

	i = head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->number == j->number)
				error_free(head);
			j = j->next;
		}
		i = i->next;
	}
}

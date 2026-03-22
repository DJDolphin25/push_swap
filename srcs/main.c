/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:10:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/22 22:23:14 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	init_stack(t_stack *stacks, char **av)
{
	stacks->a = parse_stack(av);
	if (!stacks->a)
	{
		free(stacks);
		error_msg();
	}
	stacks->b = NULL;
	check_duplicates(stacks->a);
	stacks->tail_a = ft_lstlast(stacks->a);
	stacks->tail_b = NULL;
}

static void	sort_and_free(t_stack *stacks)
{
	if (is_sorted(stacks) == 0)
	{
		ft_lstclear(&stacks->a);
		free(stacks);
		return ;
	}
	if (ft_lstsize(stacks->a) <= 5)
		sort_small(stacks);
	else
		sort_big(stacks);
	ft_lstclear(&stacks->a);
	ft_lstclear(&stacks->b);
	free(stacks);
}

int	main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac < 2)
		return (1);
	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		error_msg();
	init_stack(stacks, av);
	sort_and_free(stacks);
	return (0);
}

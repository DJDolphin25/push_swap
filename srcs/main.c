/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:10:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/25 19:56:09 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	init_stack(t_stack *stacks, char **av)
{
	stacks->a = parse_stack(av);
	if (!stacks->a)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stacks->b = NULL;
	check_duplicates(stacks->a);
	stacks->tail_a = ft_lstlast(stacks->a);
	stacks->tail_b = NULL;
}

static void	sort_and_free(t_stack *stacks)
{
	if (!stacks)
		return ;
	if (is_sorted(stacks))
	{
		ft_lstclear(&stacks->a);
		ft_lstclear(&stacks->b);
		return ;
	}
	if (ft_lstsize(stacks->a) <= 5)
		sort_small(stacks);
	else
		sort_big(stacks);
	ft_lstclear(&stacks->a);
	ft_lstclear(&stacks->b);
}

int	main(int ac, char **av)
{
	t_stack	stacks;

	if (ac < 2)
		return (0);
	init_stack(&stacks, av);
	sort_and_free(&stacks);
	return (0);
}

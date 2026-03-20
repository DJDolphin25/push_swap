/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:10:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/20 16:51:47 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*static void list_print(t_node *list)
{
	t_node    *cur = list;
	printf("[");
	while (cur)
	{
		printf("%ld", cur->number);
		cur = cur->next;
		if (cur) 
			printf(" -> ");
	}
	printf("]\n");
}
*/
int	main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac < 2)
		return (1);
	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		error_msg();
	stacks->a = parse_stack(av);
	stacks->b = NULL;
	check_duplicates(stacks->a);
	stacks->tail_a = ft_lstlast(stacks->a);
	stacks->tail_b = NULL;
	if (is_sorted(stacks) == 0)
		return (0);
	if (ft_lstsize(stacks->a) <= 5)
		sort_small(stacks);
	// list_print(stacks->a);
	// list_print(stacks->b);
	return (0);
}

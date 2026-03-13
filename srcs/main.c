/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:10:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/13 14:33:31 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static void list_print(t_node *list)
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

int     main(int ac, char **av)
{
        t_stack        *stacks;

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

        /*ft_printf("Initial:\n");
        list_print(stacks->a);
        list_print(stacks->b);

        ft_printf("\npb pb (llenamos B)\n");
        pb(stacks);
        pb(stacks);
        list_print(stacks->a);
        list_print(stacks->b);

        ft_printf("\nsa sb\n");
        ft_printf("%p\n", (void *)stacks->a);
	sa(stacks);
	ft_printf("%p\n", (void *)stacks->a);
        sb(stacks);
	ft_printf("ptr: %p\n", (void *)stacks->a);
        list_print(stacks->a);
        list_print(stacks->b);

        printf("\npa pb\n");
	ft_printf("%p\n", (void *)stacks->b);
        pa(stacks);
        pb(stacks);
        list_print(stacks->a);
        list_print(stacks->b);

        ft_printf("\nra rb\n");
	ft_printf("%p\n", stacks->tail_a);
        ra(stacks);
	rb(stacks);
        list_print(stacks->a);
        list_print(stacks->b);

        ft_printf("\nrra rrb\n");
        rra(stacks);
        rrb(stacks);
        list_print(stacks->a);
        list_print(stacks->b);*/

        return (0);
}

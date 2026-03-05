/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:10:48 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/05 23:28:50 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

//static void list_print(t_node *list)
//{
//	t_node    *cur = list;
//	printf("[");
//	while (cur)
//	{
//		printf("%ld", cur->number);
//		cur = cur->next;
//		if (cur) 
//			printf(" -> ");
//	}
//	printf("]\n");
//}
int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		exit(1);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		error_msg();
	stack->a = parse_stack(av);
	stack->b = NULL;
	check_duplicates(stack->a);
	// list_print(stack->a);
	// list_print(stack->b);
	return (0);
}

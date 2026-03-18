/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:14:47 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/05 22:40:43 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(long number)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_node **head, t_node *new)
{
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}

t_node	*ft_lstlast(t_node *head)
{
	t_node	*temp;

	if (!head)
		return (NULL);
	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_lstadd_back(t_node **head, t_node *new)
{
	t_node	*last;

	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	last = ft_lstlast(*head);
	new->next = NULL;
	new->prev = last;
	last->next = new;
}

void	ft_lstclear(t_node **head)
{
	t_node	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}
}
/*#include <stdio.h>

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

int main()
{
	t_node	*a;
	t_node	*b;
	t_node	*c;
	//t_node 	*d = NULL;
	
	a = ft_lstnew(5);
	b = ft_lstnew(10);
	c = ft_lstnew(3);
	ft_lstclear(&a);
	ft_lstsize(a);
	list_print(a);
	int len = ft_lstsize(a);
	printf("%d\n", len);
	ft_lstadd_front(&d, c);
	list_print(d)
	ft_lstadd_back(&d, b);
	list_print(d);
	int len = ft_lstsize(d);
	printf("%d\n", len);
	ft_lstclear(&d);
	printf("%p", d);

	return (0);

}*/

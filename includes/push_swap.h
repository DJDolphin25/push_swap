/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:37:04 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/10 01:04:55 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	long			number;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*tail_a;
	t_node	*b;
	t_node	*tail_b;
}	t_stacks

//Linked list funtcions

int		ft_lstsize(t_node *head);

t_node	*ft_lstnew(long number);
t_node	*ft_lstlast(t_node *head);
t_stack	*init_stack(int *numbers, int total);

void	ft_lstadd_front(t_node **head, t_node *new);
void	ft_lstadd_back(t_node **head, t_node *new);
void	ft_lstclear(t_node **head);		

//Parsing funtcions
t_node	*parse_stack(char **av);

void	error_msg(void);
void	check_duplicates(t_node *head);

//Rules
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);

void	pa(t_stack *stacks);
void	pb(t_stack *stacks);

void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
#endif

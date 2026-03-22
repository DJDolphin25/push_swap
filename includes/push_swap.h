/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:37:04 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/22 17:12:36 by theoppon         ###   ########.fr       */
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

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	t_node	*tail_a;
	t_node	*tail_b;
}	t_stack;

typedef struct s_cost
{
	int	value;
	int	cost_in_a;
	int	cost_in_b;
	int	total;
}	t_cost;

//Linked list funtcions
int		ft_lstsize(t_node *head);

t_node	*ft_lstnew(long number);
t_node	*ft_lstlast(t_node *head);

void	ft_lstadd_front(t_node **head, t_node *new);
void	ft_lstadd_back(t_node **head, t_node *new);
void	ft_lstclear(t_node **head);

//Utils
int		cost_from_pos(int size, int pos);
int		cost_a(t_stack *stacks, int value);
int		cost_b(t_stack *stacks, int value);
int		find_min(t_node *stack);
int		find_target_in_a(t_stack *stacks, int value);
int		find_target_in_b(t_stack *stacks, int value);
int		ft_abs(int n);
int		get_position(t_node *stack, int value);
int		total_cost(int cost_a, int cost_b);

void	move_to_top(t_stack *stacks, int value);

//Parsing funtcions
int		is_sorted(t_stack *stacks);

t_node	*parse_stack(char **av);

void	error_msg(void);
void	check_duplicates(t_node *head);

//Rules
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);

void	pa(t_stack *stacks);
void	pb(t_stack *stacks);

void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
void	rr(t_stack *stacks);

void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rrr(t_stack *stacks);

//Algo
//t_cost	get_cheapest(t_node *stacks);

void	execute_move(t_stack *stacks, int cost_a, int cost_b, char dir);
void	move_b_to_a(t_stack *stacks);
void	final_rotation(t_stack *stacks);
void	sort_small(t_stack *stacks);
void	sort_big(t_stack *stacks);
#endif

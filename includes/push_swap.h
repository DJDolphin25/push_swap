/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:37:04 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/04 00:33:06 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct	s_node
{
	long		number;
	struct s_node 	*next;
	struct s_node	*prev;
}t_node;

typedef struct	s_stack
{
	t_node	*a;
	t_node	*b;
}t_stack;

//Linked list funtcions: lst_utils.c

t_node	*ft_lstnew(long number);
t_node	*ft_lstlast(t_node *head);
void	ft_lstadd_front(t_node **head, t_node *new);
void	ft_lstadd_back(t_node **head, t_node *new);
void	ft_lstclear(t_node **head);
int	ft_lstsize(t_node *head);		


//Parsing funtcions
void		error_msg(void);
void		validate_all(int ac, char **av);

#endif

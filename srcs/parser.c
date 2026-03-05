/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:16:03 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/05 23:18:29 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	error_msg(void)
{
	ft_printf("Error\n");
	exit(1);
}

static void	free_split(char **split)
{
	char	**tmp;

	if (!split)
		return ;
	tmp = split;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(split);
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
				error_msg();
			j = j->next;
		}
		i = i->next;
	}
}

long	parse_number(char *num)
{
	int		sign;
	long	result;

	if (!num || *num == '\0')
		error_msg();
	sign = 1;
	if (*num == '+' || *num == '-')
	{
		if (*num == '-')
			sign = -1;
		num++;
	}
	if (!ft_isdigit(*num))
		error_msg();
	result = 0;
	while (*num)
	{
		if (!ft_isdigit(*num))
			error_msg();
		result = result * 10 + (*num++ - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && - result < -2147483648))
			error_msg();
	}
	return (result * sign);
}

t_node	*parse_stack(char **av)
{
	char	**split;
	char	**s;
	long	num;
	t_node	*head;
	t_node	*node;

	head = NULL;
	av++;
	while (*av)
	{
		split = ft_split(*av++, ' ');
		if (!split)
			error_msg();
		s = split;
		while (*s)
		{
			num = parse_number(*s++);
			node = ft_lstnew(num);
			if (!node)
				error_msg();
			ft_lstadd_back(&head, node);
		}
		free_split(split);
	}
	return (head);
}

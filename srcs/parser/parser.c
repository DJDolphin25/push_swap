/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:16:03 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/25 19:50:38 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

static int	parse_digits(char *num, long *result)
{
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		*result = *result * 10 + (*num - '0');
		if (*result > 2147483648)
			return (0);
		num++;
	}
	return (1);
}

static int	parse_number(char *num, long *out)
{
	int		sign;
	long	result;

	if (!num || *num == '\0')
		return (0);
	sign = 1;
	if (*num == '+' || *num == '-')
	{
		if (*num == '-')
			sign = -1;
		num++;
	}
	if (!ft_isdigit(*num))
		return (0);
	result = 0;
	if (!parse_digits(num, &result))
		return (0);
	if ((sign == 1 && result > 2147483647)
		|| (sign == -1 && result > 2147483648))
		return (0);
	*out = result * sign;
	return (1);
}

static void	process_split(char **split, t_node **head)
{
	char	**s;
	long	num;
	t_node	*node;

	s = split;
	while (*s)
	{
		if (!parse_number(*s, &num))
		{
			free_split(split);
			error_free(*head);
		}
		node = ft_lstnew(num);
		if (!node)
		{
			free_split(split);
			error_free(*head);
		}
		ft_lstadd_back(head, node);
		s++;
	}
}

t_node	*parse_stack(char **av)
{
	char	**split;
	t_node	*head;

	head = NULL;
	while (*++av)
	{
		split = ft_split(*av, ' ');
		if (!split || !split[0])
		{
			free_split(split);
			error_free(head);
		}
		process_split(split, &head);
		free_split(split);
	}
	return (head);
}

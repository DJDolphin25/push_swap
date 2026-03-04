/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:16:03 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/04 00:59:10 by theoppon         ###   ########.fr       */
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

static void	check_duplicates(char **split)
{
	char	**i;
	char	**j;

	i = split;
	while (*i)
	{
		j = i + 1;
		while (*j)
		{
			if (ft_atoi(*i) == ft_atoi(*j))
				error_msg();
			j++;
		}
		i++;
	}
}

static void	validate_single(char *num)
{
	long	result;
	int	sign;

	if (!num || *num == '\0')
		error_msg();
	sign = 1
	if (*num == '+' || *ptr == '-')
	{
		if (*num == '-')
			sign = -1;
		num++;
	}
	if (!ft_isdigit(*num))
		error_msg();
	result = 0
	while (*num)
	{
		if (!ft_isdigit(*num))
			error_msg();
		re
		ptr++;
	}
	value = ft_atoi(num);
	if (value < -2147483648 || value > 2147483647)
		error_msg();
}

void	validate_all(int ac, char **av)
{
	char 	**arg;
	char	**num;
	char	**split;

	arg = av + 1;
	while (arg < av + ac)
	{
		split = ft_split(*arg, ' ');
		if (!split)
			error_msg ();
		num = split;
		while (num)
		{
			validate_single(*num);
			num++;
		}
		check_duplicates(split);
		free_split(split);
		arg++;
	}
}

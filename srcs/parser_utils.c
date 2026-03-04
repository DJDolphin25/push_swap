/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:22:04 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/04 23:43:46 by theoppon         ###   ########.fr       */
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

static int	count_split(char **split)
{
	char **s;

	s = split;
	while (*s)
		s++;
	return (s - split);
}

int	count_numbers(int ac, char **av)
{
	char	**split;
	char	**end;
	int	total;

	total = 0;
	av++;
	end = av + (ac - 1);
	while (av < end)
	{
		split = ft_split(*av, ' ');
		if (!split)
			error_msg();
		total += count_split(split);
		free_split(split);
		av++;
	}
	return (total);
}

void	fill_numbers(int *num, int ac, char **av)
{
	char	**split;
	char	**s;
	char	**end;
	int	*ptr;

	ptr = num;
	av++;
	end = av + (ac - 1);
	while (av < end)
	{
		split = ft_split(*av, ' ');
		if (!split)
			error_msg();
		s = split;
		while (*s)
		{	
			validate_single(*s);
			*ptr++ = ft_atoi(*s++);
		}
		free_split(split);
		av++;
	}
}

void	check_duplicates(int *arr, int size)
{
	int	*end_i;
	int	*i;
	int	*j;
	int	*end_j;

	i = arr;
	end_i = arr + size;
	while (i < end_i)
	{
		j = i + 1;
		end_j = arr + size;
		while (j < end_j)
		{
			if (*i == *j)
				error_msg();
			j++;
		}
		i++;
	}
}

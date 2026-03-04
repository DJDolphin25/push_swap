/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:27:59 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 23:51:26 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*reserve_memory_and_copy(char const *start, char const *end)
{
	char	*str;
	char	*beg;

	str = malloc((end - start) + 1);
	if (!str)
		return (NULL);
	beg = str;
	while (start < end)
		*str++ = *start++;
	*str = '\0';
	return (beg);
}

char	**free_memory(char **ptr, int n)
{
	while (n > 0)
	{
		free(ptr[n - 1]);
		n--;
	}
	free(ptr);
	return (NULL);
}

static int	split_words(char const *s, char const *d, char c, char **result)
{
	char const	*start;
	char const	*end;
	int			count;

	count = 0;
	while (s < d)
	{
		while (*s == c && s < d)
			s++;
		start = s;
		while (*s != c && s < d)
			s++;
		end = s;
		if (start != end)
		{
			result[count] = reserve_memory_and_copy(start, end);
			if (!result[count])
				return (-(count + 1));
			count++;
		}
	}
	result[count] = NULL;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char const	*d;
	char		**result;
	int			n;

	if (!s)
		return (NULL);
	d = s + ft_strlen(s);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	n = split_words(s, d, c, result);
	if (n < 0)
		return (free_memory(result, -n));
	return (result);
}

/*#include <stdio.h>

int main(void)
{
    //char const	*s = "//I//like/chocolate//";
   // char	c = '/';
    char	**words;
    char	**ptr;

    words = ft_split("hello!              ",' ');
    if (!words)
	    return (1);
    ptr = words;
    while (*ptr)
    {
        printf("%s\n", *ptr);
        ptr++;
    }
    ptr = words;
    while (*ptr)
        free(*ptr++);
    free(words);
    return (0);
}*/

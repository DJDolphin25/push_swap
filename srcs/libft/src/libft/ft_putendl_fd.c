/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:11:02 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/15 17:40:12 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

/*#include <fcntl.h>

int	main()
{
	int	fd;

	fd = 1;
	ft_putendl_fd("Hello", fd);
	return(0);
}*/

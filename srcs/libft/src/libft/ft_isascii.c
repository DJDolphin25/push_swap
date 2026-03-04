/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:13:24 by theoppon          #+#    #+#             */
/*   Updated: 2025/11/01 21:26:46 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isascii(1));
	printf("%d\n", isascii(1));
	return(0);
}*/

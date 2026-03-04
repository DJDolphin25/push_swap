/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:51:43 by theoppon          #+#    #+#             */
/*   Updated: 2026/03/04 00:21:43 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		parser(va_list arguments, const char *format);
int		print_char(int c);
int		print_string(char *c);
int		print_decimal(int n);
int		print_unsigned_decimal(unsigned int n);
int		print_hex_lowercase(int n);
int		print_hex_uppercase(int n);
int		print_memory(void *s);

#endif

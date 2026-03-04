/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoppon <theoppon@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:06:19 by theoppon          #+#    #+#             */
/*   Updated: 2025/12/23 20:27:01 by theoppon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			char_printed;
	va_list		arguments;

	char_printed = 0;
	va_start (arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			char_printed += parser(arguments, format);
			format ++;
		}
		else
		{
			char_printed += print_char(*format);
			format++;
		}
	}
	va_end(arguments);
	return (char_printed);
}

int	parser(va_list arguments, const char *format)
{
	int	chars;

	chars = 0;
	if (*format == 'c')
		chars = print_char(va_arg(arguments, int));
	else if (*format == 's')
		chars = print_string(va_arg(arguments, char *));
	else if (*format == 'd')
		chars = print_decimal(va_arg(arguments, int));
	else if (*format == 'i')
		chars = print_decimal(va_arg(arguments, signed int));
	else if (*format == 'u')
		chars = print_unsigned_decimal(va_arg(arguments, unsigned int));
	else if (*format == 'x')
		chars = print_hex_lowercase(va_arg(arguments, int));
	else if (*format == 'X')
		chars = print_hex_uppercase(va_arg(arguments, int));
	else if (*format == 'p')
		chars = print_memory(va_arg(arguments, void *));
	else if (*format == '%')
		chars = print_char('%');
	return (chars);
}

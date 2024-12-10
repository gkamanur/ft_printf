/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:38:36 by gkamanur          #+#    #+#             */
/*   Updated: 2024/12/10 16:56:06 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_inp(char letter, va_list args)
{
	int	count;

	count = 0;
	if (letter == 'c')
		count += print_char(va_arg(args, int));
	else if (letter == 's')
		count += print_str(va_arg(args, char *));
	else if ((letter == 'd') || (letter == 'i'))
		count += print_digit(va_arg(args, int), 10, "0123456789");
	else if (letter == 'p')
		count += print_pointer(va_arg(args, void *));
	else if (letter == 'u')
		count += print_udigit(va_arg(args, unsigned int), 10, "0123456789");
	else if (letter == 'x')
		count += print_digit(va_arg(args, unsigned int), 16,
				"0123456789abcdef");
	else if (letter == 'X')
		count += print_digit(va_arg(args, unsigned int), 16,
				"0123456789ABCDEF");
	else if (letter == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	va_start(args, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			count += print_inp(*input, args);
		}
		else
		{
			count += write(1, input, 1);
		}
		input++;
	}
	va_end(args);
	return (count);
}

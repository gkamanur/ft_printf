/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:09:04 by gkamanur          #+#    #+#             */
/*   Updated: 2024/12/10 16:57:20 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
		i += write(1, str++, 1);
	return (i);
}

int	print_digit(long n, int base, char *symbols)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		count += print_digit(n / base, base, symbols);
	count += write(1, &symbols[n % base], 1);
	return (count);
}

int	print_udigit(unsigned long n, int base, char *symbols)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)base)
		count += print_udigit(n / base, base, symbols);
	count += write(1, &symbols[n % base], 1);
	return (count);
}

int	print_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += print_udigit((unsigned long)ptr, 16, "0123456789abcdef");
	return (count);
}

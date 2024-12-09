/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:38:36 by gkamanur          #+#    #+#             */
/*   Updated: 2024/12/09 16:38:46 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	print_char(int c)
{
	return (write(1, &c, 1));
}
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	while (*str)
		i += write(1, str++, 1);
	return (i);
}

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return (print_digit(n % base, base));
	}
}

int print_inp(char letter, va_list args)
{
    int count;

    count = 0;
    if (letter == 'c')
        count += print_char(va_arg(args,int));
    else if (letter == 's')
       count += print_str(va_arg(args,char *));
    else if (letter == 'd')
        count += print_digit((long)va_arg(args, int), 10);
    return (count);
}

int ft_printf(const char *input, ...)
{
    va_list args;
    int count;
    va_start(args, input);

    count = 0;
    while (*input)
    {
        if (*input == '%')
        {
            count += print_inp(*++input, args);
        }
        else
        {
            count += write(STDOUT_FILENO, input, 1);
        }
        ++input;
    }
    va_end(args);
    return (count);
}
int main(int argc, char **argv)
{
    int count = 0;
    
    count = ft_printf("123:%c %s %d\n", 'v',"abc",234.23);
    printf("count: %i\n", count);
    return (0);
}

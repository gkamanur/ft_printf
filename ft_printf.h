/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:03:56 by gkamanur          #+#    #+#             */
/*   Updated: 2024/12/10 16:43:44 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base, char *symbols);
int	print_udigit(unsigned long n, int base, char *symbols);
int	print_pointer(void *ptr);
int	print_inp(char letter, va_list args);
int	ft_printf(const char *input, ...);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortmann <aortmann@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:09:12 by aortmann          #+#    #+#             */
/*   Updated: 2024/02/11 16:31:50 by aortmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The ft_formats function processes the format specifier and the corresponding
** argument from va_list. It calls the appropriate functions based on the format
** specifier and returns the length of the printed output.
*/
int	ft_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'x' || format == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (format == '%')
		length += ft_printpercent();
	return (length);
}

/* The ft_printf function is a formatted output 
** function that takes a format string*/
/* and a variable number of arguments. 
** It processes the format string and calls the
** corresponding functions to print the formatted output.*/
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			length += ft_putchar('%');
			i++;
		}
		else if (str[i] == '%')
			length += ft_formats(args, str[++i]);
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}

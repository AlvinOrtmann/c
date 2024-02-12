/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortmann <aortmann@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:09:08 by aortmann          #+#    #+#             */
/*   Updated: 2024/02/11 12:45:54 by aortmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <errno.h>
#include <stdio.h>

/*
** The ft_printstr function prints a string to the standard output.
** It returns the length of the printed string.
** If the input string is NULL, it prints "(null)" and returns 6.
*/
int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/*
** The ft_numlen function calculates the number of digits in an integer.
** It returns the number of digits, including the negative sign and NULL.
*/
int	ft_numlen(int c)
{
	int	len;

	len = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		len = 1;
		c = -c;
	}
	while (c > 0)
	{
		c /= 10;
		len++;
	}
	return (len + 1);
}

/*
** The ft_putchar function prints a single character to the standard output.
** It returns 1 to indicate the successful printing of a character.
*/
int	ft_putchar(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (write(1, &uc, 1) == -1)
		return (-1);
	return (1);
}

/*
** The ft_printnbr function prints an integer to the standard output.
** It converts the integer to a string using the ft_itoa function,
** then prints the string using ft_putstr, and finally returns the length
** of the printed string.
*/
int	ft_printnbr(int c)
{
	int		l;
	char	*str;

	str = ft_itoa(c);
	l = ft_print_str(str);
	free(str);
	return (l);
}

/*
** The ft_printpercent function prints a '%' character to the standard output.
** It returns 1 to indicate the successful printing of '%'.
*/
int	ft_printpercent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

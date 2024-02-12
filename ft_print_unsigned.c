/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortmann <aortmann@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:09:01 by aortmann          #+#    #+#             */
/*   Updated: 2024/02/09 15:20:34 by aortmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* Function to calculate the length of an unsigned integer */
static int	unbrlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/* Function to convert an unsigned integer to a string */
static void	convert_unbr(char *str, unsigned int n, int size, int isovf)
{
	int	count;

	count = size;
	while (n > 0)
	{
		str[count - 1] = n % 10 + '0';
		n /= 10;
		count--;
	}
	if (isovf == 1)
		str[size - 1]++;
}

/* Function to convert unsigned integer to string */
char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		size;

	str = NULL;
	if (n > 0)
	{
		size = unbrlen(n);
		str = malloc((size + 1) * sizeof(char));
		if (!str)
			return (NULL);
		str[size] = '\0';
		convert_unbr(str, n, size, 0);
	}
	else if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = 0 + '0';
		str[1] = '\0';
	}
	return (str);
}

/* Function to print unsigned integers */
int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	num = NULL;
	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_print_str(num);
		free(num);
	}
	return (print_length);
}

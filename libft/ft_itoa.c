/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortmann <aortmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 06:16:24 by aortmann          #+#    #+#             */
/*   Updated: 2024/01/20 00:35:20 by aortmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.*/

#include "libft.h"

static int	nbrlen(int n)
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

static void	convert_nbr(char *str, int n, int size, int isovf)
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

static char	*neg_num(int n)
{
	char	*str;
	int		isovf;
	int		size;

	isovf = 0;
	if (n == -2147483648)
	{
		n += 1;
		isovf = 1;
	}
	n *= -1;
	size = nbrlen(n) + 1;
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	str[0] = '-';
	convert_nbr(str, n, size, isovf);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n > 0)
	{
		size = nbrlen(n);
		str = malloc((size + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[size] = '\0';
		convert_nbr(str, n, size, 0);
	}
	else if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = 0 + '0';
		str[1] = '\0';
	}
	else
		str = neg_num(n);
	return (str);
}

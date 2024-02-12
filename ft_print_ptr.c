/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortmann <aortmann@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:08:52 by aortmann          #+#    #+#             */
/*   Updated: 2024/02/09 15:17:47 by aortmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_ptrl(uintptr_t ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ptr %= 16;
	}
	if (ptr < 10)
		ft_putchar(ptr + '0');
	else
		ft_putchar(ptr - 10 + 'a');
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		ft_print_str("0x0");
		return (3);
	}
	i += write(1, "0x0", 2);
	ft_put_ptr(ptr);
	i += ft_ptrl(ptr);
	return (i);
}

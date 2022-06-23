/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirapra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 04:58:54 by shirapra          #+#    #+#             */
/*   Updated: 2022/06/22 01:18:50 by shirapra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	ft_put_pointer(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_pointer(num / 16);
		ft_put_pointer(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_pointer(unsigned long ptr)
{
	int	len_printed;

	len_printed = 0;
	len_printed += write(1, "0x", 2);
	if (ptr == 0)
		len_printed += write(1, "0", 1);
	else
	{
		ft_put_pointer(ptr);
		len_printed += ft_pointer_len(ptr);
	}
	return (len_printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_hexadecimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirapra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 04:58:13 by shirapra          #+#    #+#             */
/*   Updated: 2022/06/22 01:18:11 by shirapra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int num)
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

static void	ft_put_hex(unsigned int num, const char fmt)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, fmt);
		ft_put_hex(num % 16, fmt);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (fmt == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (fmt == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char fmt)
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_put_hex(num, fmt);
	return (ft_hex_len(num));
}

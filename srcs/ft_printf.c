/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirapra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:27:46 by shirapra          #+#    #+#             */
/*   Updated: 2022/06/22 01:15:42 by shirapra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_get_fmt(va_list args, const char fmt)
{
	int	len_printed;

	len_printed = 0;
	if (fmt == 'c')
		len_printed += ft_print_char(va_arg(args, int));
	else if (fmt == 's')
		len_printed += ft_print_str(va_arg(args, char *));
	else if (fmt == 'd' || fmt == 'i')
		len_printed += ft_print_nbr(va_arg(args, int));
	else if (fmt == 'x' || fmt == 'X')
		len_printed += ft_print_hex(va_arg(args, unsigned int), fmt);
	else if (fmt == 'u')
		len_printed += ft_print_unsigned(va_arg(args, unsigned int));
	else if (fmt == 'p')
		len_printed += ft_print_pointer(va_arg(args, unsigned long));
	else if (fmt == '%')
		len_printed += ft_print_percent();
	return (len_printed);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len_return;
	va_list	args;

	i = 0;
	len_return = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_return += ft_get_fmt(args, str[i + 1]);
			i++;
		}
		else
		{
			len_return += ft_print_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len_return);
}

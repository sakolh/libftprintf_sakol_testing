/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirapra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:32:49 by shirapra          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:22 by shirapra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_unsigned_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*num;
	int		print_length;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirapra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:51:25 by shirapra          #+#    #+#             */
/*   Updated: 2022/06/23 00:10:27 by shirapra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_pointer(unsigned long ptr);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int num, const char format);
int	ft_print_percent(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shirapra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:30:31 by shirapra          #+#    #+#             */
/*   Updated: 2022/06/19 22:30:32 by shirapra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mystronebyte(void)
{
	char	*str;

	str = (char *) malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = ft_mystronebyte();
		return (str);
	}
	if (s_len <= len)
		str = (char *) malloc(sizeof(char) * (s_len - start + 1));
	else
		str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

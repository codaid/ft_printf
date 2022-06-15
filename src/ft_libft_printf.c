/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:17:03 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/15 14:53:58 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	car;

	i = -1;
	while (s[++i])
	{
		car = s[i];
		if (car == (unsigned char)c)
			return ((char *)&s[i]);
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

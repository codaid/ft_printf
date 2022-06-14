/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:17:03 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/14 15:42:56 by gsaid            ###   ########.fr       */
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

// void	ft_inttohex(char *str, int nbr, int ind, char *base)
// {
// 	if (nbr > 15)
// 		ft_inttohex(str, nbr / 16, ind - 1, base);
// 	write(1, &base[(nbr % 16)], 1);
// 	g_len_writed++;
// }

// char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	char	*dup;

// 	i = 0;
// 	while (s1[i])
// 		i++;
// 	dup = malloc((i + 1) * sizeof(s1[0]));
// 	if (!dup)
// 		return (0);
// 	dup[i] = '\0';
// 	while (i--)
// 		dup[i] = s1[i];
// 	return (dup);
// }

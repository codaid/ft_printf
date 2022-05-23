/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:35:13 by gsaid             #+#    #+#             */
/*   Updated: 2022/05/23 18:27:50 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_power_itoa(long long int n)
{
	long long int	i;
	long long int	nbr;

	i = 0;
	nbr = n;
	if (n == 0)
		return (1);
	if (n < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static void	ft_pushint(char *s, long long int n, long long int indice)
{
	if (n > 9 || n < -9)
		ft_pushint(s, n / 10, indice - 1);
	if (n < 0)
		s[indice] = (-n % 10) + '0';
	else
		s[indice] = (n % 10) + '0';
}

char	*ft_itoa_printf(long long int n)
{
	int		power;
	char	*res;

	power = ft_power_itoa(n);
	if (n > -1)
	{
		res = malloc((power + 1) * sizeof(char));
		if (!res)
			return (NULL);
		ft_pushint(res, n, power - 1);
		res[power] = '\0';
	}
	else
	{
		res = malloc((power + 2) * sizeof(char));
		if (!res)
			return (NULL);
		ft_pushint(res, n, power);
		res[0] = '-';
		res[power + 1] = '\0';
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:59:11 by gsaid             #+#    #+#             */
/*   Updated: 2022/05/23 21:15:16 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

extern int	g_len_writed;

int	ft_nbr_bit(long long int nbr)
{
	int	prov;
	int	need;

	need = 0;
	prov = nbr;
	while (prov > 0)
	{
		prov /= 2;
		need++;
	}
	if (need < 8)
		return (8);
	else if (need < 16)
		return (16);
	else if (need < 32)
		return (32);
	return (64);
}

void	ft_bin_neg(char *bin)
{
	int	i;
	int	ret;

	i = -1;
	ret = 1;
	while (bin[++i])
	{
		if (bin[i] == '0')
			bin[i] = '1';
		else
			bin[i] = '0';
	}
	i = ft_strlen(bin);
	while (--i >= 0 && ret == 1)
	{
		if (bin[i] == '0')
		{
			bin[i] = '1';
			ret = 0;
		}
		else
			bin[i] = '0';
	}
}

static int	ft_btodec(char *nbr)
{
	int	i;
	int	j;
	int	res;
	int	pow;

	i = 4;
	pow = 0;
	res = 0;
	while (i-- > 0)
	{
		j = 3 - i;
		pow = 1;
		while (j-- > 0)
			pow *= 2;
		res += pow * (nbr[i] - '0');
	}
	return (res);
}

char	*ft_btohex(char *bin, int nbrBit, char *base)
{
	char	binary_part[5];
	int		i;
	int		dec;
	char	*hex;

	hex = malloc(9 * sizeof(char));
	if (!hex)
		return (NULL);
	i = 8;
	while (nbrBit > 0 && i >= 0)
	{
		nbrBit -= 4;
		ft_copy_n_char(&bin[nbrBit], binary_part, 4);
		dec = ft_btodec(binary_part);
		hex[--i] = base[dec];
	}
	while (--i >= 0)
		hex[i] = base[15];
	hex[8] = '\0';
	return (hex);
}

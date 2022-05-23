/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:51:11 by gsaid             #+#    #+#             */
/*   Updated: 2022/05/23 20:51:47 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

char	*ft_btohex(char *bin, int nbrBit, char *base);

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
		return 8;
	else if (need < 16)
		return 16;
	else if (need < 32)
		return 32;
	return 64;
}

// void	ft_addone_bin(char *tab, int index, int ret)
// {
// 	if (tab[index] == '0')
// 	{
// 		tab[index] = '1';
// 		ret = 0;
// 	}
// 	else
// 		tab[index] = '0';
// 	if (index != 0 && ret == 1)
// 		ft_addone_bin(tab, index - 1, ret);
// }

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
	i = strlen(bin);
	// ft_addone_bin(bin, i - 1, 1);
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

char	*ft_get_hex2(long int nbr, char *base)
{
	int		i;
	int		prov;
	int		nbr_bit;
	char	*str_binary;
	char	*hex;

	if ((int)nbr >= 0)
		prov = nbr;
	else
		prov = -nbr;
	nbr_bit = ft_nbr_bit(prov);
	str_binary = malloc((nbr_bit + 1) * sizeof(char));
	if (!str_binary)
		return (NULL);
	i = nbr_bit;
	while (--i >= 0)
	{
		str_binary[i] = (prov % 2) + '0';
		prov /= 2;
	}
	// if ((int)nbr < 0)
	ft_bin_neg(str_binary);
	hex = ft_btohex(str_binary, nbr_bit, base);
	free(str_binary);
	return (hex);
}


void	ft_copy_n_char(char *src, char *dst, int nbr)
{
	if (!src || !dst)
		return ;
	while (nbr-- > 0)
		dst[nbr] = src[nbr];
}

int	ft_btodec(char *nbr)
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
	return res;
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
	while (nbrBit > 0 && i >=0)
	{
		nbrBit -= 4;
		ft_copy_n_char(&bin[nbrBit], binary_part, 4);
		dec = ft_btodec(binary_part);
		hex[--i] = base[dec];
	}
	while (--i >= 0)
		hex[i] = base[15];
	hex[8] = '\0';
	return hex;
}

void	ft_print_hex_pos(long long int nbr, char *base)
{
	if (nbr > 16)
		ft_print_hex_pos(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
	// g_len_writed++;
}

void	ft_convert_hex(long int nbr, char *base)
{
	char	*binary;
	int		len;

	if (nbr == -2147483648)
	{
		write(1, "80000000", 8);
		// g_len_writed += 8;
		return ;
	}
	if (nbr >= 0)
	{
		ft_print_hex_pos(nbr, base);
		return ;
	}
	binary = ft_get_hex2(nbr, base);
	len = ft_strlen(binary);
	write(1, binary, len);
	free(binary);
	// g_len_writed += len;
}


int	main(void)
{
	int nbr;

	nbr = -1223;
	if (!nbr && nbr != 0)
		return 0;
	ft_convert_hex(nbr, "0123456789abcdef");
	printf("\n%x : printf\n", nbr);

	return (0);
}

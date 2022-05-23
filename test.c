/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:10:18 by gsaid             #+#    #+#             */
/*   Updated: 2022/05/23 13:48:17 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ft_itobin(long long int nbr, char *str);
void ft_addone_bin(char *tab, int index, int ret);
void	ft_btohex(char *bin, char *hex, int nbrBit);
int	ft_btodec(char *nbr);

int main()
{
	char *bin = "11010110";
	// char *bin = "1111";
	char *hex;
	hex = malloc(9 * sizeof(char));
	// int i = ft_btodec(bin);
	// printf("i : %d\n", i);
	// printf("%x", -42);
	// ft_itobin(-200, bin);
	ft_btohex(bin, hex, 8);
	printf("%s", bin);
	// free(bin);
	free(hex);
	return 0;
}

void	ft_nbr_bit(long long int nbr, int *tab)
{
	int	prov;

	tab[0] = 0;
	prov = nbr;
	while (prov > 0)
	{
		prov /= 2;
		tab[0]++;
	}
	if (tab[0] < 8)
		tab[1] = 8;
	else if (tab[0] < 16)
		tab[1] = 16;
	else if (tab[0] < 32)
		tab[1] = 32;
	else
		tab[1] = 64;
}

void	ft_bin_neg(char *bin)
{
	int	i;

	i = -1;
	printf("\nneg before : %s\n", bin);
	while (bin[++i])
	{
		if (bin[i] == '0')
			bin[i] = '1';
		else
			bin[i] = '0';
	}
	i = strlen(bin);
	ft_addone_bin(bin, i - 1, 1);
}

void	ft_itobin(long long int nbr, char *str)
{
	int	i;
	int	prov;
	int	nbr_bit[3];

	if ((int)nbr >= 0)
		prov = nbr;
	else
		prov = -nbr;
	printf("prov : %d\n", prov);
	ft_nbr_bit(prov, nbr_bit);
	nbr_bit[2] = 0;
	str = malloc((nbr_bit[1] + 1) * sizeof(char));
	if (!str)
		return ;
	i = nbr_bit[1];
	printf("len : %d\n", i);
	while (--i >= 0)
	{
		str[i] = (prov % 2) + '0';
		prov /= 2;
	}
	printf("%s\n", str);
	if ((int)nbr < 0)
		ft_bin_neg(str);
}

void	ft_addone_bin(char *tab, int index, int ret)
{
	if (tab[index] == '0')
	{
		tab[index] = '1';
		ret = 0;
	}
	else
		tab[index] = '0';
	if (index != 0 && ret == 1)
		ft_addone_bin(tab, index - 1, ret);
}

void	ft_copy_n_char(char *src, char *dst, int nbr)
{
	if (!src || !dst)
		return ;

	printf("src : %s\n", src);
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

void	ft_btohex(char *bin, char *hex, int nbrBit)
{
	char	binary_part[5];
	int		i;
	int		dec;
	char	*base = "0123456789abcdef";

	i = nbrBit;
	while (nbrBit > 0)
	{
		nbrBit -= 4;
		ft_copy_n_char(&bin[nbrBit], binary_part, 4);
		dec = ft_btodec(binary_part);
		hex[--i] = base[dec];
		printf("%c\n", hex[i]);
	}
	while (--i >= 0)
		hex[i] = base[15];
	printf("%s\n", hex);
}

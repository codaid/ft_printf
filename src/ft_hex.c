/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:52:53 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/08 14:10:34 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

extern int	g_len_writed;

void	ft_copy_n_char(char *src, char *dst, int nbr)
{
	if (!src || !dst)
		return ;
	while (nbr-- > 0)
		dst[nbr] = src[nbr];
}

char	*ft_get_hex(long int nbr, char *base)
{
	int		i;
	int		prov;
	int		nbr_bit;
	char	*str_binary;
	char	*hex;

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
	ft_bin_neg(str_binary);
	hex = ft_btohex(str_binary, nbr_bit, base);
	free(str_binary);
	return (hex);
}

void	ft_print_hex_pos(unsigned long int nbr, char *base)
{
	if (nbr >= 16)
		ft_print_hex_pos(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
	g_len_writed++;
}

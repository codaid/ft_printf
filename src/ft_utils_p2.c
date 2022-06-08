/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:52:06 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/08 11:15:36 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

extern int	g_len_writed;

static void	ft_print_hex(long int nbr, char *base)
{
	char	*hex;
	int		len;

	if (nbr == -2147483648)
	{
		write(1, "80000000", 8);
		g_len_writed += 8;
		return ;
	}
	if (nbr >= 0)
	{
		ft_print_hex_pos(nbr, base);
		return ;
	}
	hex = ft_get_hex(nbr, base);
	len = ft_strlen(hex);
	write(1, hex, len);
	free(hex);
	g_len_writed += len;
}

void	ft_print_x(va_list *ap)
{
	long int	nbr;

	nbr = va_arg(*ap, unsigned int);
	if (!nbr && nbr != 0)
		return ;
	ft_print_hex(nbr, "0123456789abcdef");
}

void	ft_print_x_maj(va_list *ap)
{
	long int	nbr;

	nbr = va_arg(*ap, unsigned int);
	if (!nbr && nbr != 0)
		return ;
	ft_print_hex(nbr, "0123456789ABCDEF");
}

void	ft_print_p(va_list *ap)
{
	long int	nbr;

	nbr = va_arg(*ap, long int);
	if (!nbr && nbr != 0)
		return ;
	write(1, "0x", 2);
	g_len_writed += 2;
	ft_print_hex(nbr, "0123456789abcdef");
}

void	ft_print_percent(va_list *ap)
{
	char	car;

	(void)ap;
	car = '%';
	write(1, &car, 1);
	g_len_writed++;
}

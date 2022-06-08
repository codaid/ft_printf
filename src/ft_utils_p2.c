/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:52:06 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/08 15:30:14 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

extern int	g_len_writed;

static void	ft_print_hex(unsigned long int nbr, char *base)
{
	if (nbr >= 16)
		ft_print_hex(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
	g_len_writed++;
}

void	ft_print_x(va_list *ap)
{
	unsigned int	nbr;

	nbr = va_arg(*ap, unsigned int);
	if (!nbr && nbr != 0)
		return ;
	ft_print_hex(nbr, "0123456789abcdef");
}

void	ft_print_x_maj(va_list *ap)
{
	unsigned int	nbr;

	nbr = va_arg(*ap, unsigned int);
	if (!nbr && nbr != 0)
		return ;
	ft_print_hex(nbr, "0123456789ABCDEF");
}

void	ft_print_p(va_list *ap)
{
	unsigned long	nbr;

	nbr = va_arg(*ap, unsigned long);
	if (!nbr)
	{
		write(1, "(nil)", 5);
		g_len_writed += 5;
		return ;
	}
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

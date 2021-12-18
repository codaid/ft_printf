/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:52:06 by gsaid             #+#    #+#             */
/*   Updated: 2021/12/18 02:13:22 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

extern int	g_len_writed;

void	ft_print_x(va_list *ap)
{
	int		nbr;
	int		len;
	char	*str;

	nbr = va_arg(*ap, int);
	if (!nbr && nbr != 0)
		return ;
	if (nbr < 0)
		nbr = -nbr;
	len = ft_power(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	ft_inttohex(str, nbr, len - 1, "0123456789abcdef");
	str[len] = '\0';
	write(1, str, len);
	free(str);
	g_len_writed += len;
}

void	ft_print_x_maj(va_list *ap)
{
	int		nbr;
	int		len;
	char	*str;

	nbr = va_arg(*ap, int);
	if (!nbr && nbr != 0)
		return ;
	if (nbr < 0)
		nbr = -nbr;
	len = ft_power(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	ft_inttohex(str, nbr, len - 1, "0123456789ABCDEF");
	str[len] = '\0';
	write(1, str, len);
	free(str);
	g_len_writed += len;
}

void	ft_print_percent(va_list *ap)
{
	char	car;

	(void)ap;
	car = '%';
	write(1, &car, 1);
	g_len_writed++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_p1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:17:54 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/14 15:43:10 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_c(va_list *ap, int *g_len_writed)
{
	char	car;

	car = va_arg(*ap, int);
	write(1, &car, 1);
	*g_len_writed += 1;
}

void	ft_print_s(va_list *ap, int *g_len_writed)
{
	char	*str;
	int		len;

	str = va_arg(*ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*g_len_writed += 6;
		return ;
	}
	len = ft_strlen(str);
	write(1, str, len);
	*g_len_writed += len;
}

void	ft_print_d(va_list *ap, int *g_len_writed)
{
	long long int	nbr;
	int				len;
	char			*str;

	nbr = va_arg(*ap, int);
	if (!nbr && nbr != 0)
		return ;
	str = ft_itoa_printf(nbr);
	len = ft_strlen(str);
	write(1, str, len);
	*g_len_writed += len;
	free(str);
}

void	ft_print_u(va_list *ap, int *g_len_writed)
{
	unsigned int	nbr;
	int				len;
	char			*str;

	nbr = va_arg(*ap, unsigned int);
	if (!nbr && nbr != 0)
		return ;
	str = ft_itoa_printf(nbr);
	len = ft_strlen(str);
	write(1, str, len);
	*g_len_writed += len;
	free(str);
}

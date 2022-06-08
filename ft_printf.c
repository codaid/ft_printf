/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:00:11 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/08 11:16:33 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_len_writed = 0;
t_pf	*g_list = NULL;
char	*g_base = "cspdiuxX%";

static void	ft_print_arg(char c, va_list *ap)
{
	t_pf	*tmp;

	tmp = g_list;
	while (tmp->next && tmp->car != c)
		tmp = tmp->next;
	if (tmp)
		tmp->pf(ap);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;

	g_len_writed = 0;
	if (!create_list())
		return (0);
	va_start(ap, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			if (ft_strchr(g_base, s[i + 1]))
				ft_print_arg(s[++i], &ap);
		}
		else if (s[i] != '%')
		{
			write(1, &s[i], 1);
			g_len_writed++;
		}
	}
	va_end(ap);
	return (g_len_writed);
}

/*
#include <stdio.h>
#include <limits.h>
int main(void)
{
	ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ft_printf(" %x\n", LONG_MAX);
	printf("----printf----\n");
	// printf(" %x\n", LONG_MAX);
	printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	return (0);
}
*/

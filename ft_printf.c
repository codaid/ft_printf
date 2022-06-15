/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:00:11 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/15 14:52:09 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_arg(char c, va_list *ap, t_pf *g_list, int *g_len_writed)
{
	t_pf	*tmp;

	tmp = g_list;
	while (tmp->next && tmp->car != c)
		tmp = tmp->next;
	if (tmp)
		tmp->pf(ap, g_len_writed);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_pf	*g_list;
	int		g_len_writed;
	int		i;

	g_len_writed = 0;
	g_list = create_list();
	if (!g_list)
		return (0);
	va_start(ap, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1] && ft_strchr("cspdiuxX%", s[i + 1]))
			ft_print_arg(s[++i], &ap, g_list, &g_len_writed);
		else if (s[i] != '%')
		{
			write(1, &s[i], 1);
			g_len_writed += 1;
		}
	}
	ft_clear_list(g_list);
	va_end(ap);
	return (g_len_writed);
}

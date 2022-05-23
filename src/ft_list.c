/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:16:06 by gsaid             #+#    #+#             */
/*   Updated: 2021/12/17 00:31:39 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

extern t_pf	*g_list;

static t_pf	*create_item(char c, void (*f)(va_list *))
{
	t_pf	*new;

	new = malloc(sizeof(t_pf));
	if (!new)
		return (NULL);
	new->car = c;
	new->pf = f;
	return (new);
}

static t_pf	*add_item(t_pf *list, t_pf *new_add)
{
	t_pf	*last;

	if (!list)
	{
		list = new_add;
		return (list);
	}
	last = list;
	while (last->next != NULL)
		last = last->next;
	last->next = new_add;
	return (list);
}

static int	ft_list_len(t_pf *list)
{
	int	len;

	len = 0;
	if (!list)
		return (0);
	while (++len && list->next)
		list = list->next;
	return (len);
}

int	create_list(void)
{
	g_list = add_item(g_list, create_item('c', &ft_print_c));
	g_list = add_item(g_list, create_item('s', &ft_print_s));
	g_list = add_item(g_list, create_item('p', &ft_print_p));
	g_list = add_item(g_list, create_item('d', &ft_print_d));
	g_list = add_item(g_list, create_item('i', &ft_print_d));
	g_list = add_item(g_list, create_item('u', &ft_print_u));
	g_list = add_item(g_list, create_item('x', &ft_print_x));
	g_list = add_item(g_list, create_item('X', &ft_print_x_maj));
	g_list = add_item(g_list, create_item('%', &ft_print_percent));
	if (!ft_list_len(g_list))
		return (0);
	return (1);
}
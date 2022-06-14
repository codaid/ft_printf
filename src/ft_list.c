/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:16:06 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/14 15:49:57 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_pf	*create_item(char c, void (*f)(va_list *ap, int *g_len_writed))
{
	t_pf	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->car = c;
	new->pf = f;
	new->next = NULL;
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
	int		len;
	t_pf	*tmp;

	len = 0;
	tmp = list;
	if (!tmp)
		return (0);
	while (++len && tmp->next)
		tmp = tmp->next;
	return (len);
}

t_pf	*create_list(void)
{
	t_pf	*g_list;

	g_list = NULL;
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
		return (NULL);
	return (g_list);
}

void	ft_clear_list(t_pf *list)
{
	t_pf	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp)
			free(tmp);
	}
}

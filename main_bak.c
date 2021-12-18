/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 00:11:57 by gsaid             #+#    #+#             */
/*   Updated: 2021/12/17 00:34:48 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	*p;
	int	i;

	i = 15;
	p = &i;
	ft_printf("%s%c%s%c\n", "Hello", ' ', "world ", '!');
	ft_printf("i : %i\n", 10);
	ft_printf("i : %i\n", -10);
	ft_printf("i : %p\n", p);
	printf("i : %p\n", p);
	ft_printf("i : %X\n", -10);
	return (0);
}

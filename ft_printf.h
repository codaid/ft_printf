/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:23:13 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/14 15:43:36 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pf
{
	char		car;
	void		(*pf)(va_list *, int *);
	struct s_pf	*next;
}			t_pf;

// ft_utils_p1.c
void	ft_print_c(va_list *ap, int *g_len_writed);
void	ft_print_s(va_list *ap, int *g_len_writed);
void	ft_print_d(va_list *ap, int *g_len_writed);
void	ft_print_u(va_list *ap, int *g_len_writed);

// ft_utils_p2.c
void	ft_print_x(va_list *ap, int *g_len_writed);
void	ft_print_x_maj(va_list *ap, int *g_len_writed);
void	ft_print_p(va_list *ap, int *g_len_writed);
void	ft_print_percent(va_list *ap, int *g_len_writed);

// Function libft
char	*ft_itoa_printf(long long int n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);

// ft_list.c
t_pf	*create_list(void);
void	ft_clear_list(t_pf *list);

int		ft_printf(const char *s, ...);

#endif

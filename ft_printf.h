/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:23:13 by gsaid             #+#    #+#             */
/*   Updated: 2022/06/08 15:40:42 by gsaid            ###   ########.fr       */
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
	void		(*pf)(va_list *);
	struct s_pf	*next;
}			t_pf;

// ft_utils_p2.c
void	ft_print_x(va_list *ap);
void	ft_print_x_maj(va_list *ap);
void	ft_print_percent(va_list *ap);

// Function libft
char	*ft_itoa_printf(long long int n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);

void	ft_print_c(va_list *ap);
void	ft_print_s(va_list *ap);
void	ft_print_p(va_list *ap);
void	ft_print_d(va_list *ap);
void	ft_print_u(va_list *ap);
int		create_list(void);
void	ft_inttohex(char *str, int nbr, int ind, char *base);
int		ft_power(long long int nbr);
char	*ft_itobin(long long int nbr, char *base);
void	ft_bin_neg(char *bin);
int		ft_printf(const char *s, ...);

#endif

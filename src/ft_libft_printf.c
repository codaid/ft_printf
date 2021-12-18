/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaid <gsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:17:03 by gsaid             #+#    #+#             */
/*   Updated: 2021/12/18 02:14:10 by gsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	car;

	i = -1;
	while (s[++i])
	{
		car = s[i];
		if (car == (unsigned char)c)
			return ((char *)&s[i]);
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_inttohex(char *str, int nbr, int ind, char *base)
{
	if (nbr > 15)
		ft_inttohex(str, nbr / 16, ind - 1, base);
	str[ind] = base[(nbr % 16)];
}

int	ft_power(long long int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

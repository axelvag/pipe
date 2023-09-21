/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:44:27 by avaganay          #+#    #+#             */
/*   Updated: 2022/11/14 16:24:36 by avaganay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	abs(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

int	lennb(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
}

void	var0(int *sign, int *i)
{
	*sign = 0;
	*i = 0;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;

	var0(&sign, &i);
	if (n < 0)
		sign = 1;
	str = (char *)malloc((lennb(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		i++;
	}
	while (n != 0)
	{
		str[i++] = abs(n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

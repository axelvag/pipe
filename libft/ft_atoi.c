/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:38:50 by avaganay          #+#    #+#             */
/*   Updated: 2022/11/17 15:02:11 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	limit(long long n, const char str, int sign)
{
	long long	reslong;

	reslong = ((n * 10) + (str - '0')) * sign;
	if (reslong < -2147483648)
		return (0);
	if (reslong > 2147483647)
		return (-1);
	return (1);
}

void	init0(int *i, int *res, int *sign)
{
	*i = 0;
	*res = 0;
	*sign = 1;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;
	int	limit_test;

	init0(&i, &res, &sign);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '+' || str[i] == '-')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		limit_test = limit(res, *str, sign);
		if (limit_test == 0 || limit_test == -1)
			return (limit_test);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

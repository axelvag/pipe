/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:33:26 by avaganay          #+#    #+#             */
/*   Updated: 2023/01/26 13:20:31 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbtab(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			|| (i == 0 && s[i] != c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_filltab(char const *s, char c, int *index)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (s[*index] == c)
		(*index)++;
	while (s[*index + len] != c && s[*index + len])
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i++] = s[*index];
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nbtab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nbtab = ft_nbtab(s, c);
	res = malloc((nbtab + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	j = 0;
	while (i < nbtab)
	{
		res[i] = ft_filltab(s, c, &j);
		i++;
	}
	res[i] = 0;
	return (res);
}

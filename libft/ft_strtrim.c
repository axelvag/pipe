/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:59:56 by avaganay          #+#    #+#             */
/*   Updated: 2022/11/15 16:08:34 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	char_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	cutleft(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && char_in_set(set, s1[i]))
	{
		i++;
	}
	return (i);
}

size_t	cutright(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (s1[i] && char_in_set(set, s1[i]))
	{
		i--;
	}
	return (ft_strlen(s1) - i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	nbcutleft;
	size_t	nbcutright;
	size_t	i;
	char	*ptr;

	nbcutleft = cutleft(s1, set);
	i = 0;
	if (nbcutleft == ft_strlen(s1))
	{
		ptr = malloc(sizeof(char) * 1);
		ptr[0] = '\0';
		return (ptr);
	}
	nbcutright = cutright(s1, set);
	ptr = malloc(ft_strlen(s1) - nbcutleft - nbcutright + 1);
	if (!ptr)
		return (NULL);
	while (nbcutleft < ft_strlen(s1) - nbcutright)
	{
		ptr[i] = s1[nbcutleft];
		i++;
		nbcutleft++;
	}
	ptr[i] = '\0';
	return (ptr);
}

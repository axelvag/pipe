/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:49:04 by avaganay          #+#    #+#             */
/*   Updated: 2022/11/16 10:28:41 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;

	if (dst == NULL && dstsize == 0)
		return (0);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || lendst > dstsize)
	{
		return (dstsize + lensrc);
	}
	while ((src[i] != '\0') && (i + lendst < dstsize - 1))
	{
		dst[i + lendst] = src[i];
		i++;
	}
	dst[i + lendst] = '\0';
	return (lendst + lensrc);
}

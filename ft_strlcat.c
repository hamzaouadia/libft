/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:35:33 by haouadia          #+#    #+#             */
/*   Updated: 2022/10/13 09:05:39 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	l;
	size_t	len;
	size_t	i;

	if (dst == 0 && dstsize == 0)
		return (0);
	j = ft_strlen(dst);
	l = ft_strlen(src) + j;
	len = (dstsize - j - 1);
	if (j >= dstsize)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (l);
}

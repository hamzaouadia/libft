/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:09:07 by haouadia          #+#    #+#             */
/*   Updated: 2022/10/15 12:32:54 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst1 == 0 && src1 == 0)
		return (0);
	if (dst1 >= src1)
	{
		i = len;
		while (i-- > 0)
		{
			dst1[i] = src1[i];
		}
	}
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}

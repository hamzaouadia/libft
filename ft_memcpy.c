/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:53:00 by haouadia          #+#    #+#             */
/*   Updated: 2022/10/13 08:50:15 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*a;
	const char	*b;
	size_t		i;

	i = 0;
	a = (char *)dst;
	b = (const char *)src;
	if (a == NULL && b == NULL)
		return (NULL);
	while (n > i)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}

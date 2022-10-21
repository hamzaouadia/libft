/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:49:33 by haouadia          #+#    #+#             */
/*   Updated: 2022/10/13 10:43:47 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	put_str(char *string, long long int nb, int size)
{
	if (nb == 0)
		string[0] = '0';
	else if (nb < 0)
	{
		nb *= -1;
		string[0] = '-';
	}
	size--;
	while (size >= 0 && nb != 0)
	{
		string[size] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
}

static int	string_size(long long int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i ++;
	}
	if (nb != 0)
	{
		while (nb != 0)
		{
			nb = nb / 10;
			i++;
		}
	}
	else
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*string;
	long long int	nb;
	int				size;

	nb = n;
	size = string_size(nb);
	string = (char *)malloc(sizeof(char) * size + 1);
	if (!string)
		return (NULL);
	put_str(string, nb, size);
	string[size] = '\0';
	return (string);
}

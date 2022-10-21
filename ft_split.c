/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:34:20 by haouadia          #+#    #+#             */
/*   Updated: 2022/10/18 15:55:04 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	len_string(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			while (s[start] != c)
			{
				start++;
				len++;
			}
			break ;
		}
		start++;
	}
	return (len);
}

static int	string_count(char const *s, char c)
{
	int	i;
	int	nbr_s;

	i = 0;
	nbr_s = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nbr_s++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	return (nbr_s);
}

static void	fill_string(char *splited, char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			while (s[start] != c)
			{
				splited[i++] = s[start];
				start++;
			}
			splited[i] = '\0';
			break ;
		}
		start++;
	}
}

static char	**str_malloc(char **splited, char const *s, char c)
{
	int		i;
	int		str_nbr;
	int		start;

	i = -1;
	start = 0;
	str_nbr = string_count(s, c);
	while (++i < str_nbr)
	{
		splited[i] = malloc(sizeof(char) * (len_string(s, c, start) + 1));
		if (!splited[i])
		{
			i = 0;
			while (splited[i])
				free (splited[i]);
			return (0);
		}
			
		fill_string(splited[i], s, c, start);
		while (s[start])
		{
			if (s[start++] != c)
			{
				while (s[start] != c)
					start++;
				break ;
			}
		}
	}
	splited[i] = NULL;
	return (splited);
}

char	**ft_split(char const *s, char c)
{
	int		str_nbr;
	char	**splited;

	str_nbr = string_count(s, c);
	splited = (char **)malloc(sizeof(char *) * (str_nbr + 1));
	if (!splited)
		return (0);
	str_malloc(splited, s, c);
	return (splited);
}

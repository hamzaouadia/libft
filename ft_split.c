/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:41:38 by haouadia          #+#    #+#             */
/*   Updated: 2022/10/21 13:47:24 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_func(char **splited, int i)
{
	while (i--)
	{
		free (splited[i]);
	}
	free (splited);
}

void	word_malloc(char **splited, char const *s1, char c, int nw)
{
	int		i;
	int		start;
	size_t	len;

	i = -1;
	start = 0;
	while (++i < nw)
	{
		len = 0;
		while (s1[start] && s1[start] == c)
			start++;
		while (s1[start] && s1[start] != c)
		{
			start++;
			len++;
		}
		splited[i] = ft_substr(s1, start - len, len);
		if (!splited[i])
			free_func(splited, i);
	}
}

static int	number_of_word(char const *s1, char c)
{
	int	i;
	int	nbr_s;

	i = 0;
	nbr_s = 0;
	while (s1[i])
	{
		if (s1[i] != c)
		{
			nbr_s++;
			while (s1[i] && s1[i] != c)
				i++;
		}
		if (s1[i])
			i++;
	}
	return (nbr_s);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (!s)
		return (NULL);
	splited = malloc(sizeof(char *) * (number_of_word(s, c) + 1));
	if (!(splited))
		return (0);
	word_malloc(splited, s, c, number_of_word(s, c));
	splited[number_of_word(s, c)] = NULL;
	return (splited);
}
// #include <stdio.h>
// int main()
// {
// 	char *s1 = "tripouille";
// 	char c = ' ';
// 	char **string = ft_split(s1, c);
// 	int i = 2;
// 	while (i--)
// 		printf("|%s|\n", *string++);
// }
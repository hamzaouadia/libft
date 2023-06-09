/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:18:19 by haouadia          #+#    #+#             */
/*   Updated: 2022/10/19 17:32:28 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		j;
	int		start;
	char	*trimed;

	start = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) != 0 && s1[start])
		start++;
	while (j > start && ft_strrchr(set, s1[j]) != 0)
		j--;
	trimed = ft_substr(s1, start, sizeof(char) * (j - start + 1));
	return (trimed);
}

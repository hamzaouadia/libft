/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:42:30 by haouadia          #+#    #+#             */
/*   Updated: 2022/10/23 23:42:32 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*s;
	t_list	*save;

	s = malloc(sizeof(lst));
	save = s;
	if (s == NULL)
		return (0);
	while (lst != NULL)
	{
		f(lst->content);
		s->content = lst->content;
		lst = lst->next;
		s->next = malloc(sizeof(lst));
		s = s->next;
		if (s == NULL)
		{
			while (save != NULL)
			{
				del(save->content);
				free (lst);
				save = save->next;
			}
			return (NULL);
		}
	}
	s->next = NULL;
	return (s);
}

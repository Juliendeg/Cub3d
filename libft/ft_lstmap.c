/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:53:57 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*i;
	t_list	*n;

	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			n = new->next;
			(del)(new->content);
			free(new);
			new = n;
		}
		ft_lstadd_back(&i, new);
		new = new->next;
		lst = lst->next;
	}
	return (new);
}

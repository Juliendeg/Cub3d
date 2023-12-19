/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:52:50 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*s;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	s = *lst;
	while ((s->next) != NULL)
	{
		s = s->next;
	}
	s->next = new;
}

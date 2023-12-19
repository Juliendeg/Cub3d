/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:19:43 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *str )
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;
	size_t	y;
	char	*s2;

	i = 0;
	n = ft_strlen(s1);
	while (s1[i] && in_set(s1[i], set))
		i++;
	while (n > i && in_set(s1[n - 1], set))
		n--;
	s2 = (char *)malloc(sizeof(*s1) * (n - i + 1));
	if (!s2)
		return (NULL);
	y = 0;
	while (i < n)
		s2[y++] = s1[i++];
	s2[y] = 0;
	return (s2);
}

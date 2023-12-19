/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:23:24 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	n;
	int		found;

	i = -1;
	found = 1;
	if (ft_strlen(little) == '\0')
		return ((char *)big);
	while (big[++i] && i < len)
	{
		n = 0;
		if (big[i] == little[0])
		{
			x = i;
			found = 1;
			while (big[x] && little[n] && n < len && x < len)
				if (big[x++] != little[n++])
					found = 0;
			if (found && !little[n])
				return ((char *)big + i);
		}
	}
	return (NULL);
}

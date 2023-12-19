/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:03:49 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		x;
	char		*char_dest;
	const char	*char_src;

	x = 0;
	if ((dest == src) || (n == 0))
		return (dest);
	if (!src)
		return (NULL);
	char_src = (const char *) src;
	char_dest = (void *) dest;
	while (x < n)
	{
		char_dest[x] = (const char)char_src[x];
		x++;
	}
	return (dest);
}

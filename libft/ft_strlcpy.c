/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:13:41 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	n;

	i = ft_strlen(src);
	n = 0;
	if (size != 0)
	{
		while (src[n] && n < size - 1)
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	return (i);
}

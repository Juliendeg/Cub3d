/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:42:31 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *s2, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	size_t			i;

	x = (unsigned char *)s;
	y = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (x[i] != y[i])
			return (x[i] - y[i]);
		i++;
	}
	return (0);
}

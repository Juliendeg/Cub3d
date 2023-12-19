/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:13:00 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexa(unsigned long nbr, char *c, unsigned int size)
{
	int	x;

	x = 0;
	if (nbr > size - 1)
	{
		x = x + ft_hexa(nbr / 16, c, size);
		nbr = nbr % size;
	}
	x = x + ft_putchar(c[nbr]);
	return (x);
}

int	ft_put_memory(unsigned long nbr)
{
	int		x;
	char	*hexa;

	x = 0;
	hexa = "0123456789abcdef";
	if ((long)nbr == 0)
	{
		x = x + ft_putstr("(nil)");
		return (x);
	}
	x = x + ft_putstr("0x");
	x = x + ft_hexa(nbr, hexa, 16);
	return (x);
}

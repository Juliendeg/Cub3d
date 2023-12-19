/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:32:11 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexa(unsigned int nbr, char *c, unsigned int size)
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

int	ft_putnbr_hexa_maj(unsigned int nbr)
{
	int		x;
	char	*hexa;

	x = 0;
	hexa = "0123456789ABcDEf";
	x = x + ft_hexa(nbr, hexa, 16);
	return (x);
}

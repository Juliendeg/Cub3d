/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2022/12/07 12:36:23 by jdegluai          #+#    #+#             */
/*   Updated: 2022/12/07 12:36:27 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_letter(const char *str, va_list arg, int i, int x)
{
	if (str[i] == 'c')
		x = x + ft_putchar(va_arg(arg, int));
	else if (str[i] == 's')
		x = x + ft_putstr(va_arg(arg, char *));
	else if (str[i] == 'p')
		x = x + ft_put_memory(va_arg(arg, unsigned long));
	else if (str[i] == 'd' || str[i] == 'i')
		x = x + ft_putnbr(va_arg(arg, int));
	else if (str[i] == 'u')
		x = x + ft_putnbr_u(va_arg(arg, unsigned int));
	else if (str[i] == 'x')
		x = x + ft_putnbr_hexa_min(va_arg(arg, unsigned int));
	else if (str[i] == 'X')
		x = x + ft_putnbr_hexa_maj(va_arg(arg, unsigned int));
	else if (str[i] == '%')
		x = x + ft_putchar('%');
	return (x);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		x;
	va_list	arg;

	x = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			x = x + ft_letter(str, arg, ++i, 0);
		else
			x = x + ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (x);
}

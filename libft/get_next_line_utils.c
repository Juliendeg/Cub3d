/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:17:18 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *a)
{
	free(a);
	return (0);
}

void	ft_cut(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[++j])
	{
		str[j] = str[j + i];
	}
	str[j] = '\0';
}

int	ft_new_line(char *a, char b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] != b)
		i++;
	if (a[i] == b)
		return (i);
	return (-1);
}

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char *a, char *b)
{
	int		i;
	int		j;
	char	*s;

	i = ft_strlen2(a);
	j = ft_strlen2(b);
	s = malloc(i + j + 1);
	if (s)
	{
		i = -1;
		j = -1;
		while (a && a[++i])
			s[i] = a[i];
		if (i == -1)
			i = 0;
		while (b && b[++j] && b[j] != '\n')
			s[i + j] = b[j];
		s[i + j] = b[j];
		if ((b && b[j] == '\n') || j == -1)
			j++;
		s[i + j] = '\0';
	}
	free(a);
	return (s);
}
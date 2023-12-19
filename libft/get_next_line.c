/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:17:04 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUffER_SIZE + 1];
	char		*txt;
	int			i;

	txt = NULL;
	i = 1;
	if (fd < 0 || BUffER_SIZE == 0)
		return (0);
	if (ft_new_line(buffer, '\n') != -1)
	{
		ft_cut(buffer);
		txt = ft_strjoin2(txt, buffer);
		if (txt[0] == '\0')
			txt = ft_free(txt);
	}
	while (ft_new_line(buffer, '\n') == -1 && i != 0)
	{
		i = read(fd, buffer, BUffER_SIZE);
		if (i <= 0)
			return (txt);
		buffer[i] = '\0';
		txt = ft_strjoin2(txt, buffer);
	}
	return (txt);
}

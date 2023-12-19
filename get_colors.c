/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:55:27 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/19 11:42:18 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	error_color(t_data_pars *pars)
{
	free(pars);
	print_err("Color init failed\n");
	exit(1);
}

int	stat_color(char s, int *vergul, int *nbr, int *rgb)
{
	if (s >= '0' && s <= '9')
		(*nbr) = (*nbr) * 10 + s - '0';
	else if (s == ',')
	{
		if ((*vergul) < 3)
			rgb[(*vergul)] = *nbr;
		(*vergul)++;
		(*nbr) = 0;
	}
	else if (s != ' ')
	{
		*vergul = 0;
		return (0);
	}
	return (1);
}

int	check_verg(char *line)
{
	int	index;
	int	vergul;
	int	nbr;
	int	c[3];

	index = 0;
	vergul = 0;
	nbr = 0;
	while (line[index])
	{
		if (stat_color(line[index], &vergul, &nbr, c) == 0)
			break ;
		index++;
	}
	if (vergul == 2 && c[0] <= 255 && c[1] <= 255 && nbr <= 255)
		return (((c[0] << 16) + (c[1] << 8) + nbr));
	return (-1);
}

int	colors(char *line, char *type)
{
	char	*type_colors;
	int		colors;

	colors = -1;
	type_colors = ft_strtrim(line, type);
	if (type_colors[0] != ',' && type_colors[ft_strlen(type_colors) - 1] != ',')
		colors = check_verg(type_colors);
	free(line);
	free(type_colors);
	return (colors);
}

void	get_colors(t_data_pars *pars, char *line, t_index *index)
{
	if (!ft_strncmp(line, "C ", 2))
		pars->c = colors(line, " C");
	else if (!ft_strncmp(line, "F ", 2))
		pars->f = colors(line, " F");
	index->n_color++;
}

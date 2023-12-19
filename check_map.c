/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:16:28 by pduhamel          #+#    #+#             */
/*   Updated: 2023/12/19 17:58:34 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

int	is_dir(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

int	get_spawn(char *spawn, t_data_pars *pars, int i, int x)
{
	if (is_dir(pars->maze[i][x]))
	{
		if (*spawn != -1)
			err_map(pars);
		return (1);
	}
	else if (pars->maze[i][x] != '0' && pars->maze[i][x] != '1'
			&& pars->maze[i][x] != ' ')
		err_map(pars);
	return (0);
}

int	check_char(char *a, char *b, char *c)
{
	if (*a == ' ')
		*a = '0';
	if (*b == ' ')
		*b = '0';
	if (c && *c == ' ')
		*c = '0';
	if (*a != '0' && *a != '1' && !is_dir(*a))
		return (1);
	if (*b != '0' && *b != '1' && !is_dir(*b))
		return (1);
	if (c && *c != '0' && *c != '1' && !is_dir(*c))
		return (1);
	return (0);
}

void	ft_check_maze(int i, int x, int len_maze, t_data_pars *pars)
{
	int	len;

	len = ft_strlen(pars->maze[i]);
	if (x == 0 || x == len - 1 || i == 0 || i == len_maze - 1)
		err_map(pars);
	if (i > 0 && check_char(&pars->maze[i - 1][x], &pars->maze[i - 1][x - 1],
			&pars->maze[i - 1][x + 1]))
		err_map(pars);
	if (check_char(&pars->maze[i][x - 1], &pars->maze[i][x + 1], NULL))
		err_map(pars);
	if (check_char(&pars->maze[i + 1][x], &pars->maze[i + 1][x - 1],
			&pars->maze[i + 1][x + 1]))
		err_map(pars);
}

void	check_map(t_data_pars *pars, int len_maze)
{
	char	spawn;
	int		i;
	int		x;
	int		len;

	spawn = -1;
	i = -1;
	while (++i < len_maze)
	{
		x = -1;
		len = ft_strlen(pars->maze[i]);
		while (++x < len)
		{
			if (get_spawn(&spawn, pars, i, x))
				spawn = pars->maze[i][x];
			if (pars->maze[i][x] == '0')
				ft_check_maze(i, x, len_maze, pars);
		}
	}
	if (spawn == -1)
		err_map(pars);
}

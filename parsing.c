/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:39:26 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	init_pars(t_data_pars *pars)
{
	pars->no = 0;
	pars->so = 0;
	pars->ea = 0;
	pars->we = 0;
	pars->c = -1;
	pars->f = -1;
	pars->maze = 0;
	pars->nbr_line = 0;
}

int	check_cub(char *c)
{
	if (((ft_strnstr (c, ".cub\0", 100)) == NULL)
		|| (ft_strnstr(c, ".cub\0", 100)[4]))
		return (-1);
	return (0);
}

int	get_line(char **av)
{
	int		fd;
	char	*line;
	int		nbr_line;

	line = 0;
	nbr_line = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (perror(av[1]), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
		{
			close(fd);
			break ;
		}
		free(line);
		nbr_line++;
	}
	return (nbr_line);
}

int	parsing(char **av, t_data_pars *pars)
{
	int	line;

	init_pars(pars);
	if (check_cub(av[1]) == -1)
		return (printf("Error\nIl faut un fichier .cub\n"), 0);
	line = get_line(av);
	if (line == 0)
		return (0);
	pars->maze = malloc(line * sizeof(char *));
	if (!pars->maze)
		return (printf("error\n"), 0);
	pars->nbr_line = line;
	read_map(av[1], pars);
	return (1);
}

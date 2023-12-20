/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:39:26 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/20 14:06:18 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	init_pars(t_data_pars *pars, t_data *data)
{
	pars->no = 0;
	pars->so = 0;
	pars->ea = 0;
	pars->we = 0;
	pars->c = -1;
	pars->f = -1;
	pars->maze = 0;
	pars->nbr_line = 0;
	pars->mlx = data->mlx;
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
		return (ft_putstr_fd("Error\n", 2), perror(av[1]), 0);
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

int	parsing(char **av, t_data_pars *pars, t_data *data)
{
	int	line;

	init_pars(pars, data);
	if (check_cub(av[1]) == -1)
		return (print_err("Il faut un fichier .cub\n", data), 1);
	line = get_line(av);
	if (line == 0)
	{
		mlx_destroy_display(data->pars->mlx);
		free(data->pars->mlx);
		free(data->pars);
		return (1);
	}
	pars->maze = malloc(line * sizeof(char *));
	if (!pars->maze)
		return (print_err("Malloc failed.\n", data), 1);
	*pars->maze = 0;
	pars->nbr_line = line;
	read_map(av[1], pars, data);
	return (0);
}

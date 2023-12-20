/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:53:51 by pduhamel          #+#    #+#             */
/*   Updated: 2023/12/20 11:42:00 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	err_map(t_data *data)
{
	print_err("Wrong map format.\n", data);
	exit(1);
}

void	error_texture(t_data *data, char *line)
{
	free(line);
	free(data->parsing);
	print_err("Loading textures failed.\n", data);
	exit(1);
}

void	error_color(t_data *data, char *line)
{
	free(line);
	free(data->parsing);
	print_err("Color init failed.\n", data);
	exit(1);
}

void	free_textures(t_data *data)
{
	if (data->pars->no)
		mlx_destroy_image(data->mlx, data->pars->no);
	if (data->pars->so)
		mlx_destroy_image(data->mlx, data->pars->so);
	if (data->pars->ea)
		mlx_destroy_image(data->mlx, data->pars->ea);
	if (data->pars->we)
		mlx_destroy_image(data->mlx, data->pars->we);
}

void	print_err(char *str, t_data *data)
{
	int	i;

	if (data->pars)
	{
		i = -1;
		if (data->pars->maze && *data->pars->maze)
		{
			while (data->pars->maze[++i])
				free(data->pars->maze[i]);
		}
	}
	free_textures(data);
	free(data->pars->maze);
	mlx_destroy_display(data->pars->mlx);
	free(data->pars->mlx);
	free(data->pars);
	i = 0;
	while (str[i])
		i++;
	write(2, "Error\n", 6);
	write(2, str, i);
}

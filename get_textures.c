/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:50:47 by pduhamel          #+#    #+#             */
/*   Updated: 2023/12/19 12:17:30 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

void	print_err(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(2, "Error\n", 6);
	write(2, str, i);
}

//checker les leaks
void	error_texture(t_data *data)
{
	free(data->pars);
	print_err("Loading textures failed\n");
	exit(1);
}

char	*get_path_textures(char *line)
{
	int		i;

	i = 0;
	i += 2;
	while (line[i] == 32 || (line[i] <= 13 && line[i] >= 8))
		i++;
	return (&line[i]);
}

void	*textures(char *line, t_data *data)
{
	void	*img;
	char	*path;

	path = get_path_textures(line);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->size, &data->size2);
	if (!img)
		error_texture(data);
	return (img);
}

void get_textures(char *line, t_index *index, t_data *data, t_data_pars *pars)
{
	if (!ft_strncmp(line, "NO ", 3))
		pars->no = textures(line, data);
	else if (!ft_strncmp(line, "SO ", 3))
		pars->so = textures(line, data);
	else if (!ft_strncmp(line, "EA ", 3))
		pars->ea = textures(line, data);
	else if (!ft_strncmp(line, "WE ", 3))
		pars->we = textures(line, data);
	// free(line);
	index->n_texture++;
}

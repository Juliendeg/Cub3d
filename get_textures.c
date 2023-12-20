/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:50:47 by pduhamel          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:29 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

char	*get_path_textures(char *line)
{
	int	i;

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
		error_texture(data, line);
	return (img);
}

void	get_textures(char *line, t_index *index, t_data *data,
		t_data_pars *pars)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		pars->no = textures(line, data);
		data->my_mlx.addr_n = mlx_get_data_addr(pars->no, &data->my_mlx.bpp_n,
				&data->my_mlx.l_len_n, &data->my_mlx.endian_n);
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		pars->so = textures(line, data);
		data->my_mlx.addr_s = mlx_get_data_addr(pars->so, &data->my_mlx.bpp_s,
				&data->my_mlx.l_len_s, &data->my_mlx.endian_s);
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		pars->ea = textures(line, data);
		data->my_mlx.addr_e = mlx_get_data_addr(pars->ea, &data->my_mlx.bpp_e,
				&data->my_mlx.l_len_e, &data->my_mlx.endian_e);
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		pars->we = textures(line, data);
		data->my_mlx.addr_w = mlx_get_data_addr(pars->we, &data->my_mlx.bpp_w,
				&data->my_mlx.l_len_w, &data->my_mlx.endian_w);
	}
	index->n_texture++;
}

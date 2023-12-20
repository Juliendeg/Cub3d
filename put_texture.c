/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:51:03 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/20 11:42:41 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

char	*n_texture(t_data *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	if (mlx->projection_3d > 64.0)
		y = ((int)(round((i + (mlx->projection_3d - 64.0) / 2.0) * (1000.0
							/ mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color_c = mlx->my_mlx.addr_n + (y * mlx->my_mlx.l_len_n + (x * 4));
	return (mlx->color_c);
}

char	*s_texture(t_data *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	if (mlx->projection_3d > 64.0)
		y = ((int)(round((i + (mlx->projection_3d - 64.0) / 2.0) * (1000.0
							/ mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color_c = mlx->my_mlx.addr_s + (y * mlx->my_mlx.l_len_s + (x * 4));
	return (mlx->color_c);
}

char	*w_texture(t_data *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	if (mlx->projection_3d > 64.0)
		y = ((int)(round((i + (mlx->projection_3d - 64.0) / 2.0) * (1000.0
							/ mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color_c = mlx->my_mlx.addr_w + (y * mlx->my_mlx.l_len_w + (x * 4));
	return (mlx->color_c);
}

char	*e_texture(t_data *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	if (mlx->projection_3d > 64.0)
		y = ((int)(round((i + (mlx->projection_3d - 64.0) / 2.0) * (1000.0
							/ mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color_c = mlx->my_mlx.addr_e + (y * mlx->my_mlx.l_len_e + (x * 4));
	return (mlx->color_c);
}

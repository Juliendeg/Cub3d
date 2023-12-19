/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:13:18 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/19 16:53:13 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	draw(t_data *data, float i, char dir)
{
	// (void)i;
	// printf("val: %f\n", i);
	if (dir == 'N')
		my_mlx_pixel_put(&data->my_mlx, data->height, data->width, ((int *)data->my_mlx.addr_n)[(int)(i * 64) * 64 + ((int)data->px) % 64]);
	else if (dir == 'S')
		my_mlx_pixel_put(&data->my_mlx, data->height, data->width, ((int *)data->my_mlx.addr_s)[(int)(i * 64) * 64 + ((int)data->px) % 64]);
	else if (dir == 'W')
		my_mlx_pixel_put(&data->my_mlx, data->height, data->width, ((int *)data->my_mlx.addr_w)[(int)(i * 64) * 64 + ((int)data->py) % 64]);
	else if (dir == 'E')
		my_mlx_pixel_put(&data->my_mlx, data->height, data->width, ((int *)data->my_mlx.addr_e)[(int)(i * 64) * 64 + ((int)data->py) % 64]);
}

double	calc_dis(double y_player,
	double x_player, double y_wall, double x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall))
			+ ((y_player - y_wall) * (y_player - y_wall))));
}

void	final_cast(double distance, int height, t_data *data, char dir)
{
	int	i;

	i = -1;
	data->width = 0;
	data->dst_to_projection = ((1920.00 / 2) / (tan((32.00) * (M_PI / 180))));
	data->projection_3d = (64.00 / distance) * data->dst_to_projection;
	data->flo_cei = (1080.00 / 2) - (data->projection_3d / 2);
	while (data->width < 1080.00 && data->width < data->flo_cei)
		my_mlx_pixel_put(&data->my_mlx, height, data->width++, data->pars->c);
	while (data->width < 1080.00 && data->width < data->flo_cei
		+ data->projection_3d && ++i < 1080.0)
	{
		draw(data, i / data->projection_3d, dir);
		data->width++;
	}
	while (data->width < 1080.00)
		my_mlx_pixel_put(&data->my_mlx, height, data->width++, data->pars->f);
}

void	ft_raycasting(t_data *data, double angle, int x)
{
	// double	px;
	// double	py;

	data->dir = '\0';
	data->px = data->x_player;
	data->py = data->y_player;
	data->xfoot = cos((angle) * (M_PI / 180));
	data->yfoot = sin((angle) * (M_PI / 180));
	while (1)
	{
		data->x = (int)(data->px / 64.00);
		data->y = (int)(data->py / 64.00);
		if (data->map[data->y][data->x] == '1'
			|| data->map[(int)(((data->py - data->yfoot) / 64))][data->x] == '1'
			|| data->map[data->y][(int)(((data->px - data->xfoot) / 64))] == '1')
		{
			data->distance = calc_dis(data->y_player, data->x_player, data->py, data->px);
			data->dir = set_directions(data->py, data->px, data);
			data->where = (int)(data->where * (1000.00 / 64.00)) % 1000;
			break ;
		}
		data->px += data->xfoot;
		data->py += data->yfoot;
	}
	final_cast(fix_view(data, angle), x, data, data->dir);
}

void	put_wall(t_data *data)
{
	double	angle;

	data->height = -1;
	angle = data->player_view - 32.00;
	data->my_mlx.img = mlx_new_image(data->mlx, 1920.00, 1080.00);
	data->my_mlx.addr = mlx_get_data_addr(data->my_mlx.img,
			&data->my_mlx.bpp, &data->my_mlx.line_len, &data->my_mlx.endian);
	while (++data->height < 1920.00)
	{
		ft_raycasting(data, angle, data->height);
		angle += 64.00 / 1920.00;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->my_mlx.img, 0, 0);
}

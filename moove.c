/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:50:45 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/19 10:04:06 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	apply_coll(t_data *data, double step_x, double step_y)
{
	int		y_map;
	int		x_map;
	
	y_map = (int)((data->y_player + step_y) / 64.0);
	x_map = (int)((data->x_player + step_x) / 64.0);
	if (data->map[(int)(data->y_player / 64.0)][x_map] == '0')
		data->x_player += step_x;
	if (data->map[y_map][(int)(data->x_player / 64.0)] == '0')
		data->y_player += step_y;
}

void	moove_front(t_data *data)
{	
	double	y_step;
	double	x_step;

	x_step = cos((data->player_view * (M_PI / 180))) * 10.0;
	y_step = sin((data->player_view * (M_PI / 180))) * 10.0;
	apply_coll(data, x_step, y_step);
}

void	moove_back(t_data *data)
{
	double	y_step;
	double	x_step;

	x_step = -cos((data->player_view * (M_PI / 180))) * 10.0;
	y_step = -sin((data->player_view * (M_PI / 180))) * 10.0;
	apply_coll(data, x_step, y_step);
}

void	moove_right(t_data *data)
{
	double	y_step;
	double	x_step;

	x_step = cos((data->player_view + 90) * (M_PI / 180)) * 10.0;
	y_step = sin((data->player_view + 90) * (M_PI / 180)) * 10.0;
	apply_coll(data, x_step, y_step);
}

void	moove_left(t_data *data)
{
	double	y_step;
	double	x_step;

	x_step = cos((data->player_view - 90) * (M_PI / 180)) * 10.0;
	y_step = sin((data->player_view - 90) * (M_PI / 180)) * 10.0;
	apply_coll(data, x_step, y_step);
}
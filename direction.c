/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:58:53 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/13 13:35:58 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

char	check_north_west(double w_y, double w_x, t_data *wind)
{
	if ((int)(w_y + 1) % 64 == 0
	&& wind->map[(int)(w_y / 64.0) + 1][(int)(w_x / 64.0)] == '0')
		return (wind->where = w_x, 'N');
	else
		return (wind->where = w_y, 'W');
}

char	check_north_east(double w_y, double w_x, t_data *wind)
{
	if ((int)(w_y + 1) % 64 == 0
	&& wind->map[(int)((w_y / 64.0) + 1)][(int)(w_x / 64.0)] == '0')
		return (wind->where = w_x, 'N');
	else
		return (wind->where = w_y, 'E');
}

char	check_south_east(double w_y, double w_x, t_data *wind)
{
	if ((int)(w_y) % 64 == 0
	&& wind->map[(int)((w_y / 64.0) - 1)][(int)(w_x / 64.0)] == '0')
		return (wind->where = w_x, 'S');
	else
		return (wind->where = w_y, 'E');
}

char	check_south_west(double w_y, double w_x, t_data *wind)
{
	if ((int)(w_y) % 64 == 0
	&& wind->map[(int)((w_y / 64.0) - 1)][(int)(w_x / 64.0)] == '0')
		return (wind->where = w_x, 'S');
	else
		return (wind->where = w_y, 'W');
}

char	set_directions(double w_y, double w_x, t_data *wind)
{
	if (wind->y_player > w_y && wind->x_player > w_x)
		return (check_north_west(w_y, w_x, wind));
	else if (wind->y_player > w_y && wind->x_player < w_x)
		return (check_north_east(w_y, w_x, wind));
	else if (wind->y_player <= w_y && wind->x_player <= w_x)
		return (check_south_east(w_y, w_x, wind));
	else if (wind->y_player <= w_y && wind->x_player >= w_x)
		return (check_south_west(w_y, w_x, wind));
	return (0);
}

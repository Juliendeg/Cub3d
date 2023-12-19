/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:22 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/13 13:33:33 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	config_view(t_data *data, char map)
{
	if (map == 'S')
		data->player_view = 90.0;
	else if (map == 'N')
		data->player_view = 270.0;
	else if (map == 'W')
		data->player_view = 180.0;
	else if (map == 'E')
		data->player_view = 360.0;
}

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
			{
				config_view(data, data->map[i][j]);
				data->map[i][j] = '0';
				data->y_player = i * 64.0 + 32.0;
				data->x_player = j * 64.0 + 32.0;
				break ;
			}
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:05 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/20 14:07:35 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	moove_c_left(t_data *data)
{
	data->player_view -= 2.0;
	if (data->player_view > 360.0)
		data->player_view = 0;
	if (data->player_view < 0)
		data->player_view = 360.0;
}

void	moove_c_right(t_data *data)
{
	data->player_view += 2.0;
	if (data->player_view > 360.0)
		data->player_view = 0;
	if (data->player_view < 0)
		data->player_view = 360.0;
}

void	free_all(t_data *data, t_data_pars	*pars)
{
	int	i;

	i = -1;
	while (pars->maze[++i])
		free(pars->maze[i]);
	free(pars);
	free(data->map);
	free(data->mlx);
}

int	key(int key, t_data *data)
{
	if (key == XK_Escape)
		mlx_loop_end(data->mlx);
	if (key == XK_w)
		moove_front(data);
	if (key == XK_s)
		moove_back(data);
	if (key == XK_a)
		moove_left(data);
	if (key == XK_d)
		moove_right(data);
	if (key == XK_Left)
		moove_c_left(data);
	if (key == XK_Right)
		moove_c_right(data);
	if (data->my_mlx.img)
		mlx_destroy_image(data->mlx, data->my_mlx.img);
	put_wall(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
		return (ft_putstr_fd("Error\nIl faut un argument.\n", 2), 1);
	data.pars = malloc(sizeof(t_data_pars));
	data.mlx = mlx_init();
	if (parsing(av, data.pars, &data) == 1)
		return (1);
	data.map = data.pars->maze;
	data.win = mlx_new_window(data.mlx, 1920, 1080, "cub3d");
	player_position(&data);
	put_wall(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key, &data);
	mlx_hook(data.win, 17, 0L, mlx_loop_end, data.mlx);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.my_mlx.img);
	mlx_destroy_image(data.mlx, data.pars->no);
	mlx_destroy_image(data.mlx, data.pars->so);
	mlx_destroy_image(data.mlx, data.pars->we);
	mlx_destroy_image(data.mlx, data.pars->ea);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free_all(&data, data.pars);
	return (0);
}

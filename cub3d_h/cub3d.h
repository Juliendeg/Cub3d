/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:33:58 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/20 11:57:32 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <X11/keysym.h>

# define M_PI 3.14159265358979323846

typedef struct s_my_mlx
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		bpp_n;
	int		l_len_n;
	int		endian_n;
	int		bpp_s;
	int		l_len_s;
	int		endian_s;
	int		bpp_w;
	int		l_len_w;
	int		endian_w;
	int		bpp_e;
	int		l_len_e;
	int		endian_e;
	int		bpp_c;
	int		l_len_c;
	int		endian_c;
	char	*addr_n;
	char	*addr_s;
	char	*addr_w;
	char	*addr_e;
	char	*addr_c;
}	t_my_mlx;

typedef struct s_data_pars
{
	void	*no;
	void	*ea;
	void	*so;
	void	*we;
	int		c;
	int		f;
	char	**maze;
	int		nbr_line;
	void	*mlx;
}	t_data_pars;

typedef struct s_data
{
	double		px;
	double		py;
	double		corrected_distance;
	int			width;
	double		dst_to_projection;
	double		projection_3d;
	double		flo_cei;
	double		distance;
	double		where;
	int			y;
	int			x;
	double		xfoot;
	double		yfoot;
	char		dir;
	int			height;
	double		player_view;
	double		x_player;
	double		y_player;
	void		*mlx;
	void		*win;
	char		**map;
	int			size;
	int			size2;
	char		*color_c;
	char		*parsing;
	t_my_mlx	my_mlx;
	t_data_pars	*pars;
}t_data;

typedef struct s_index {
	int	n_derc;
	int	n_color;
	int	n_texture;
	int	maze_index;
	int	new_line;
}	t_index;

int		parsing(char **av, t_data_pars *pars, t_data *data);

double	fix_view(t_data *data, double angle);

char	*e_texture(t_data *mlx, int i);
char	*s_texture(t_data *mlx, int i);
char	*n_texture(t_data *mlx, int i);
char	*w_texture(t_data *mlx, int i);
char	set_directions(double w_y, double w_x, t_data *wind);

void	err_map(t_data *data);
void	put_wall(t_data *data);
void	moove_back(t_data *data);
void	moove_left(t_data *data);
void	moove_front(t_data *data);
void	moove_right(t_data *data);
void	print_map(t_data_pars *pars);
void	player_position(t_data *data);
void	print_err(char *str, t_data *data);
void	error_color(t_data *data, char *line);
void	error_texture(t_data *data, char *line);
void	read_map(char *av, t_data_pars *pars, t_data *data);
void	get_colors(t_data_pars *pars, char *line, t_index *index);
void	my_mlx_pixel_put(t_my_mlx *data, int x, int y, int color);
void	check_map(t_data_pars *pars, int len_maze, t_data *data);
void	get_textures(char *line, t_index *index,
			t_data *data, t_data_pars *pars);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:53:51 by pduhamel          #+#    #+#             */
/*   Updated: 2023/12/19 17:58:57 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

void	err_map(t_data_pars *pars)
{
	free(pars);
	print_err("Wrong map format.\n");
	exit(1);
}

void	error_texture(t_data_pars *pars)
{
	free(pars);
	print_err("Loading textures failed.\n");
	exit(1);
}

void	print_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, "Error\n", 6);
	write(2, str, i);
}

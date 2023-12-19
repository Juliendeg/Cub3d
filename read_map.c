/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:41:22 by jdegluai          #+#    #+#             */
/*   Updated: 2023/12/12 13:53:15 by jdegluai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_h/cub3d.h"
#include "libft/libft.h"

// if (pars->no == 0 || pars->so == 0
// 	|| pars->we == 0 || pars->ea == 0)
// {
// 	printf(" error texture  %d \n", index->n_derc);
// 	exit(0);
// }

void	aff_line(t_data_pars *pars, t_index *index, char *line)
{
	if (pars->c == -1 || pars->f == -1 || pars->no == -1
		|| pars->so == -1 || pars->we == -1 || pars->ea == -1
		|| index->n_color != 6)
		error_color(pars);
	pars -> maze[index->maze_index] = ft_strdup(line);
	index -> maze_index++;
}

void	err_map(t_data_pars *pars)
{
	free(pars);
	printf("error map\n");
	exit (1);
}

void	get_map(t_data_pars *pars, char *line, t_index *i, int *index)
{
	char	*ptr;

	(void)index;
	ptr = ft_strtrim(line, " ");
	if (!ft_strncmp(ptr, "so ", 3) || !ft_strncmp(ptr, "no ", 3)
		|| !ft_strncmp(ptr, "we ", 3) || !ft_strncmp(ptr, "ea ", 3)
		|| !ft_strncmp(ptr, "f ", 2) || !ft_strncmp(ptr, "c ", 2))
		get_colors(pars, ptr, i);
	else if ((ptr[0] == '1' || ptr[0] == '0' || i->maze_index != 0))
	{
		if (ptr[0] == '1' || ptr[0] == '0')
			aff_line(pars, i, line);
		free(ptr);
		ptr = 0;
	}
	else
		free(ptr);
	free(line);
}

void	init_index(t_index *i)
{
	i->maze_index = 0;
	i->n_color = 0;
	i->n_derc = 0;
	i->new_line = 0;
}

void	read_map(char *av, t_data_pars *pars)
{
	char	*line;
	int		fd;
	char	*ptr;
	int		index;
	t_index	i;

	index = 0;
	line = 0;
	init_index(&i);
	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		ptr = line;
		if (line == 0)
			break ;
		if (line[0] == '\n' && i.maze_index != 0)
			err_map(pars);
		line = ft_strtrim(line, "\n");
		get_map(pars, line, &i, &index);
		free(ptr);
	}
	pars->maze[i.maze_index] = 0;
}

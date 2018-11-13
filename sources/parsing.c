/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:02:34 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/02 14:14:14 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	READ_FILE1 function:
**	Counts the number of items in the config file line by line
*/

int		read_file1(char *av, t_env *e)
{
	int		fd;
	char	*line;
	int		nbs[7];
	int		i;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = -1;
	while (++i < 8)
		nbs[i] = 0;
	while (get_next_line(fd, &line) == 1)
	{
		count_param_control(line, nbs);
		free(line);
	}
	free(line);
	if (nbs[MAT] == 0 || nbs[LIGHT] == 0 || nbs[CAM] != 1)
		ft_printerror("No material, no light or not one cam in the file");
	build_struct(e, nbs);
	close(fd);
	return (1);
}

/*
**	READ_FILE2 function:
**	Fulfills the environment structure with items
*/

int		read_file2(char *av, t_env *e)
{
	int		fd;
	char	*line;
	int		i;
	int		index[7];

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = -1;
	while (++i < 7)
		index[i] = 0;
	while (get_next_line(fd, &line) == 1)
	{
		fill_struct(e, line, index);
		free(line);
	}
	e->hit[SPHERE] = &hitsphere;
	e->hit[PLANE] = &hitplane;
	e->hit[I_CYL] = &hitcylinder;
	e->hit[I_CONE] = &hitcone;
	e->hit[DISK] = &hitdisk;
	e->hit[F_CYL] = &hitfcylinder;
	e->hit[F_CONE] = &hitfcone;
	e->hit[BOX] = &hitbox;
	free(line);
	close(fd);
	return (1);
}

/*
**	COUNT_PARAM_CONTROL function:
**	Controls if the line of the file is correct, then increments parameters
*/

void	count_param_control(char *line, int nbs[6])
{
	char	**s;
	int		l;

	s = ft_strsplit((char const*)line, ' ');
	l = table_len(s);
	if (!s[0])
		ft_printerror("Invalid file");
	else if (!ft_strcmp(s[0], "//"))
	{
		ft_freesplit(s);
		return ;
	}
	count_param(nbs, s, l);
	ft_freesplit(s);
}

/*
**	COUNT_PARAM function:
**	Adds one item according to the parameters of the line
*/

void	count_param(int nbs[6], char **s, int l)
{
	if (!ft_strcmp(s[0], "CAM") && (l == 9 || l == 13 || l == 17))
		nbs[CAM]++;
	else if (!ft_strcmp(s[0], "MAT") && l == 13)
		nbs[MAT]++;
	else if (!ft_strcmp(s[0], "LIGHT") && (l == 9 || l == 13 || l == 17))
		nbs[LIGHT]++;
	else if (!ft_strcmp(s[0], "SPHERE"))
		nbs[3]++;
	else if (!ft_strcmp(s[0], "PLANE"))
		nbs[3]++;
	else if (!ft_strcmp(s[0], "CYLINDER"))
		nbs[3]++;
	else if (!ft_strcmp(s[0], "CONE"))
		nbs[3]++;
	else if (!ft_strcmp(s[0], "DISK"))
		nbs[3]++;
	else if (!ft_strcmp(s[0], "F_CYLINDER"))
		nbs[3]++;
	else if (!ft_strcmp(s[0], "F_CONE"))
		nbs[3]++;
	else if (!ft_strcmp(s[0], "BOX"))
		nbs[3]++;
	else
		ft_printerror("Invalid file");
}

/*
**	BUILD_STRUCTURE function:
**	Builds the items structures inside the environment structure
*/

void	build_struct(t_env *e, int nbs[7])
{
	int	a;

	if (!(e->cam = (t_cam*)malloc(sizeof(t_cam))))
		ft_printerror("Error malloc");
	if (!(e->mat = (t_mat*)malloc(nbs[MAT] * sizeof(t_mat))))
		ft_printerror("Error malloc");
	if (!(e->light = (t_light*)malloc(nbs[LIGHT] * sizeof(t_light))))
		ft_printerror("Error malloc");
	if (!(e->item = (t_item*)malloc(nbs[ITEM] * sizeof(t_item))))
		ft_printerror("Error malloc");
	a = 0;
	while (a < 4)
	{
		e->nbs[a] = nbs[a];
		a++;
	}
}

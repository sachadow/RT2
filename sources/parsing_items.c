/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:02:34 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/16 18:03:51 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	PARSING_LIGHT function:
**	Parses the light parameters in the structure
*/

void	parsing_light(char **s, t_env *e, int *k)
{
	int	i;

	if (ft_strcmp(s[0], "LIGHT"))
		return ;
	i = 0;
	if (table_len(s) != 9 && table_len(s) != 13 && table_len(s) != 17)
		ft_printerror("Invalid file");
	e->light[*k].pos = newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]),
		ft_atoi(s[4]));
	e->light[*k].intensity = newcolor(ft_atoi(s[6] + 1), ft_atoi(s[7]),
			ft_atoi(s[8]));
	while (table_len(s) - i > 9)
	{
		if (*(s[9 + i] + 1) == 'T')
			e->light[*k].pos = add(e->light[*k].pos,
				newvec(ft_atoi(s[10 + i] + 1), ft_atoi(s[11 + i]),
					ft_atoi(s[12 + i])));
		i += 4;
	}
	(*k)++;
}

/*
**	PARSING_CONE function:
**	Parses the cone parameters in the structure
*/

void	parsing_item(char **s, t_env *e, int *k)
{
	t_item	co;

	if (ft_strcmp(s[0], "CONE") && ft_strcmp(s[0], "CYLINDER")
		&& ft_strcmp(s[0], "SPHERE") && ft_strcmp(s[0], "PLANE")
		&& ft_strcmp(s[0], "DISK") && ft_strcmp(s[0], "F_CYLINDER")
		&& ft_strcmp(s[0], "F_CONE") && ft_strcmp(s[0], "BOX"))
		return ;
	co = e->item[*k];
	if (!(ft_strcmp(s[0], "CONE")))
		co = newcone(newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]), ft_atoi(s[4])),
			newvec(ft_atoi(s[6] + 1), ft_atoi(s[7]), ft_atoi(s[8])),
			ft_atoi(s[10]), ft_atoi(s[12]), 0);
	else if (!(ft_strcmp(s[0], "CYLINDER")))
		co = newcyl(newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]), ft_atoi(s[4])),
			newvec(ft_atoi(s[6] + 1), ft_atoi(s[7]), ft_atoi(s[8])),
			ft_atoi(s[10]), ft_atoi(s[12]), 0);
	else if (!(ft_strcmp(s[0], "SPHERE")))
		co = newsph(newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]), ft_atoi(s[4])),
			ft_atoi(s[6]), ft_atoi(s[8]), ft_atoi(s[9]));
	else if (!(ft_strcmp(s[0], "PLANE")))
		co = newplane(newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]), ft_atoi(s[4])),
			ft_atoi(s[6]), ft_atoi(s[8]));
	else if (!(ft_strcmp(s[0], "DISK")))
		co = newdisk(newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]), ft_atoi(s[4])),
			newvec(ft_atoi(s[6] + 1), ft_atoi(s[7]), ft_atoi(s[8])),
			ft_atoi(s[10]), ft_atoi(s[12]));
	else if (!(ft_strcmp(s[0], "F_CYLINDER")))
		co = newfcyl(newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]), ft_atoi(s[4])),
		newvec(ft_atoi(s[6] + 1), ft_atoi(s[7]), ft_atoi(s[8])),
		ft_atoi(s[10]), ft_atoi(s[12]), ft_atoi(s[14]), 0);
	else if (!(ft_strcmp(s[0], "F_CONE")))
		co = newfcone(newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]), ft_atoi(s[4])),
		newvec(ft_atoi(s[6] + 1), ft_atoi(s[7]), ft_atoi(s[8])),
		ft_atoi(s[10]), ft_atoi(s[12]), ft_atoi(s[14]), ft_atoi(s[15]));
	else if (!(ft_strcmp(s[0], "BOX")))
		co = newbox(newvec(ft_atoi(s[2] + 1), ft_atoi(s[3]), ft_atoi(s[4])),
		newvec(ft_atoi(s[6] + 1), ft_atoi(s[7]), ft_atoi(s[8])),
		ft_atoi(s[10]));
	if (ft_strcmp(s[0], "SPHERE"))
		co.dir = normalize(co.dir);
	e->item[*k] = co;
	(*k)++;
}

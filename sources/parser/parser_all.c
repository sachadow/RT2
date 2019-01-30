/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:23:27 by asarasy           #+#    #+#             */
/*   Updated: 2019/01/23 17:29:53 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

t_env		*parser_all(char *file, t_env *e)
{
	t_element	elem;

	elem.nbr_attr = 0;
	elem = parser_xml(file, elem);
	e = recup_env(e, elem);
	e->cam->dir = normalize(e->cam->dir);
	e->nbs[0] = 1;
	return (e);
}

void		open_textures_mat(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nbs[MAT])
	{
		if (e->mat[i].type == TEXTURE)
			open_texture(e, &(e->mat[i].tex), e->mat[i].path_text);
		i++;
	}
}

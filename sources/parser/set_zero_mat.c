/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:12:13 by asarasy           #+#    #+#             */
/*   Updated: 2018/12/12 14:35:44 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

void		clean_texture_value(t_env *e, int i)
{
	e->mat[i].tex.bpp = 0;
	e->mat[i].tex.s_line = 0;
	e->mat[i].tex.ed = 0;
	e->mat[i].tex.w = 0;
	e->mat[i].tex.h = 0;
	e->mat[i].tex.realw = 0;
	e->mat[i].tex.realh = 0;
	e->mat[i].tex.angle = 0;
	e->mat[i].tex.center.x = 0;
	e->mat[i].tex.center.y = 0;
	e->mat[i].tex.center.z = 0;
	e->mat[i].tex.direction.x = 0;
	e->mat[i].tex.direction.y = 0;
	e->mat[i].tex.direction.z = 0;
}

void		clean_value_mat(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nbs[1])
	{
		e->mat[i].type = 0;
		e->mat[i].path_text = NULL;
		e->mat[i].reflection = 0;
		e->mat[i].transparency = 0;
		e->mat[i].specvalue = 0;
		e->mat[i].specpower = 0;
		e->mat[i].n = 0;
		e->mat[i].bump = 0;
		e->mat[i].diffuse.red = 0;
		e->mat[i].diffuse.green = 0;
		e->mat[i].diffuse.blue = 0;
		e->mat[i].diffuse2.red = 0;
		e->mat[i].diffuse2.green = 0;
		e->mat[i].diffuse2.blue = 0;
		e->mat[i].scale = 0;
		clean_texture_value(e, i);
		i++;
	}
}

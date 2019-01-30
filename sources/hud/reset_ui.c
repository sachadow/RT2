/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:57:38 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 18:37:14 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	RESET_VALUES function:
**	Reset values for the next item to modify
*/

void		reset_values(t_env *e)
{
	ft_memset(&e->itf.mat, 0, sizeof(t_mat) * 1);
	ft_memset(&e->itf.item, 0, sizeof(t_item) * 1);
	ft_memset(&e->itf.param, 0, sizeof(double *) * 7);
	e->itf.pick.button = -1;
	e->itf.mouse.button = -1;
	e->itf.nb_texture = 0;
	e->apply = 0;
}

/*
**	RESET_UI function:
**	Apply all the changes and reset the values for the next item
*/

void		reset_ui(t_env *e)
{
	if (e->itf.pick.button != -1)
	{
		if (e->itf.nb_texture && e->itf.mat.type != QUADRIC)
			apply_texture(e);
		apply_mat(e->itf.mat.type, e);
	}
	reset_values(e);
}

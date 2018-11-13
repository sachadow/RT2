/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:34:11 by qsebasti          #+#    #+#             */
/*   Updated: 2018/11/05 17:58:08 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"

void	show_mouse(t_env *e)
{
	if (e->key[KEY_TAB])
		mlx_do_mouse_relativeon(e->win);
	else
		mlx_do_mouse_relativeoff(e->win);
}

void	move_cam(t_env *e)
{
	t_vec	i;
	t_vec	j;
	t_vec	k;

	k = (e->cam->dir.x == 0.0f && e->cam->dir.y == 1.0f
		&& e->cam->dir.z == 0.0f) ? newvec(0, 0, 1) : newvec(0, 1, 0);
	i = crossproduct(e->cam->dir, k);
	j = crossproduct(i, e->cam->dir);
	if (e->key[KEY_LEFT] || e->key[KEY_A])
		e->cam->pos = add(e->cam->pos, scale(50, i));
	if (e->key[KEY_RIGHT] || e->key[KEY_D])
		e->cam->pos = add(e->cam->pos, scale(-50, i));
	if (e->key[KEY_UP] || e->key[KEY_W])
		e->cam->pos = add(e->cam->pos, scale(50, j));
	if (e->key[KEY_DOWN] || e->key[KEY_S])
		e->cam->pos = add(e->cam->pos, scale(-50, j));
	if (e->key[KEY_Q])
		e->cam->dir = rotate_axis(e->cam->dir, e->j, -10);
	if (e->key[KEY_E])
		e->cam->dir = rotate_axis(e->cam->dir, e->j, 10);
}

void	create_axis(t_env *e)
{
	t_vec	k;

	k = (e->cam->dir.x == 0.0f && e->cam->dir.y == 1.0f
		&& e->cam->dir.z == 0.0f) ? newvec(0, 0, 1) : newvec(0, 1, 0);
	e->i = crossproduct(e->cam->dir, k);
	e->j = crossproduct(e->i, e->cam->dir);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:34:11 by qsebasti          #+#    #+#             */
/*   Updated: 2018/10/22 14:42:34 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"

void	move_cam(t_env *e)
{
	t_vec	pos;

	pos = e->cam->pos;
	if (e->key[KEY_LEFT] || e->key[NUM_1])
		pos = newvec(pos.x - 50, pos.y, pos.z);
	if (e->key[KEY_RIGHT] || e->key[NUM_3])
		pos = newvec(pos.x + 50, pos.y, pos.z);
	if (e->key[KEY_UP])
		pos = newvec(pos.x, pos.y, pos.z + 50);
	if (e->key[KEY_DOWN])
		pos = newvec(pos.x, pos.y, pos.z - 50);
	if (e->key[NUM_5])
		pos = newvec(pos.x, pos.y + 50, pos.z);
	if (e->key[NUM_2])
		pos = newvec(pos.x, pos.y - 50, pos.z);
	e->cam->pos = pos;
}

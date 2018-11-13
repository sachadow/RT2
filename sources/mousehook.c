/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:29:16 by qsebasti          #+#    #+#             */
/*   Updated: 2018/10/25 21:13:26 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"

int		mousemove(int x, int y, t_env *e)
{
	if (e->key[KEY_SPC] == 0)
		if (e->key[KEY_TAB])
		{
			e->cam->dir = rotate_y(e->cam->dir, x * M_PI / 8);
			e->cam->dir = rotate_x(e->cam->dir, y * M_PI / 8);
		}
	return (0);
}

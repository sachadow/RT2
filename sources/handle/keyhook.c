/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:19:16 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/14 16:43:29 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "rt.h"

int		keypress(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		quit();
	else if (keycode == KEY_TAB)
		e->key[KEY_TAB] = (e->key[KEY_TAB] == 1 ? 0 : 1);
	else if (keycode == KEY_SPC)
		e->key[KEY_SPC] = (e->key[KEY_SPC] == 1 ? 0 : 1);
	else
	{
		e->loading = 0;
		e->key[keycode] = 1;
	}
	move_cam(e);
	show_mouse(e);
	return (0);
}

int		keyrelease(int keycode, t_env *e)
{
	if (keycode == KEY_TAB || keycode == KEY_SPC)
		return (keycode);
	e->key[keycode] = 0;
	return (0);
}

void	key_hook(t_env *e)
{
	move_cam(e);
	show_mouse(e);
	hud(e);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:19:16 by qsebasti          #+#    #+#             */
/*   Updated: 2018/10/22 14:42:21 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "rt.h"

int		keypress(int keycode, t_env *e)
{
	e->key[keycode] = 1;
	if (keycode == KEY_ESC)
		escape(e);
	key_hook(e);
	return (keycode);
}

int		keyrelease(int keycode, t_env *e)
{
	e->key[keycode] = 0;
	key_hook(e);
	return (keycode);
}

void	key_hook(t_env *e)
{
	move_cam(e);
	reload(e);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:38:44 by qsebasti          #+#    #+#             */
/*   Updated: 2019/02/01 18:42:01 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	LOAD function:
**	Display the loading screen
*/

void			load(t_env *e)
{
	t_img	load;

	if (e->antialiasing > 0)
	{
		mlx_clear_window(e->mlx, e->win);
		open_texture(e, &load, "resources/3_hours_later.xpm");
		mlx_put_image_to_window(e->mlx, e->win, load.img, 0, 0);
		mlx_destroy_image(e->mlx, load.img);
	}
	e->loading = 1;
}

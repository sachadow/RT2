/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:38:44 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 18:18:33 by qsebasti         ###   ########.fr       */
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
//	int		i;
//	int		j;
//	t_pix	pt;
	t_img	load;

	if (e->antialiasing > 0)
	{
		mlx_clear_window(e->mlx, e->win);
		open_texture(e, &load, "resources/3_hours_later.xpm");
		mlx_put_image_to_window(e->mlx, e->win, load.img, 0, 0);
		/*i = -1;
		while (++i < 27)
		{
			j = -1;
			while (++j < 120)
			{
				pt.x = IMG_W - 125 + j;
				pt.y = IMG_H - 30 + i;
				mlx_pixel_put(e->mlx, e->win, pt.x, pt.y, GREY);
			}
		}
		mlx_string_put(e->mlx, e->win, IMG_W - 120, IMG_H - 25,
				WHITE, "Loading ...");*/
		//mlx_string_put(e->mlx, e->win, WIN_W / 2, WIN_H / 3, WHITE, "Loading ...");
		mlx_destroy_image(e->mlx, load.img);
	}
	e->loading = 1;
	//	mlx_clear_window(e->mlx, e->win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:38:44 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/12 15:38:39 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

void			load(t_env *e)
{
	t_img	load;

	mlx_clear_window(e->mlx, e->win);
	open_texture(e, &load, "resources/3_hours_later.xpm");
	//if (!(load.img = mlx_new_image(e->mlx, WIN_W, WIN_H))
	//		|| !(load.pixel_img = (unsigned char *)mlx_get_data_addr(load.img,
	//				&load.bpp, &load.s_line, &load.ed)))
	//	ft_printerror("Error mlx");
	mlx_put_image_to_window(e->mlx, e->win, load.img, 0, 0);
	//mlx_string_put(e->mlx, e->win, 450, WIN_H / 2, WHITE, "Loading ...");
	//mlx_string_put(e->mlx, e->win, WIN_W / 2, WIN_H / 3, WHITE, "Loading ...");
	mlx_destroy_image(e->mlx, load.img);
	e->loading = 1;
	return ;
//	mlx_clear_window(e->mlx, e->win);
}

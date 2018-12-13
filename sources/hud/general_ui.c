/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:17:53 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/12 21:01:09 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <stdio.h>

static void		top_right(t_env *e)
{
	t_rect	rect;

	rect = init_rect(0, 0, (RIGHT_SPC) / 3, 2 * MARGE);
	draw_rect(RIGHT, rect, LIGHT_GREY, e);
	rect = init_rect((RIGHT_SPC) / 3 + 1, 0, rect.width, rect.height);
	draw_rect(RIGHT, rect, LIGHT_GREY, e);
	rect = init_rect(2 * ((RIGHT_SPC) / 3 + 1), 0, rect.width, rect.height);
	draw_rect(RIGHT, rect, LIGHT_GREY, e);
}

static void		ui_writting(t_env *e)
{
	int color;

	color = e->interface.onglet;
	mlx_string_put(e->mlx, e->win, 829, 2, (color == 1 ? RED : BLACK), "1");
	mlx_string_put(e->mlx, e->win, 895, 2, (color == 2 ? RED : BLACK), "2");
	mlx_string_put(e->mlx, e->win, 961, 2, (color == 3 ? RED : BLACK), "3");
	if (e->interface.onglet == 1)
	{
		picked_item(e);
		mlx_string_put(e->mlx, e->win, 5, IMG_H + 5, BLACK, "Filters:");
		color_val(e);
	}
}

void			tab(t_env *e)
{
	top_right(e);
	if (e->interface.onglet == 1)
		ui1(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img[RIGHT], IMG_W, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img[BOTTOM], 0, IMG_H);
	ui_writting(e);
	mlx_destroy_image(e->mlx, e->img[RIGHT]);
	mlx_destroy_image(e->mlx, e->img[BOTTOM]);
}

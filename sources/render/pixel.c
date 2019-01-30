/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:45:04 by squiquem          #+#    #+#             */
/*   Updated: 2019/01/28 16:18:57 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	DRAW_POINT function:
**	Puts the color in the unsigned char * image of the environment
*/

void	draw_point(t_env *e, int x, int y, t_color c)
{
	e->pixel_img[CENTER][y * e->s_line[CENTER] + x * e->bpp[CENTER]
		/ 8] = (unsigned char)ft_min(c.blue * 255.0f, 255.0f);
	e->pixel_img[CENTER][y * e->s_line[CENTER] + x * e->bpp[CENTER]
		/ 8 + 1] = (unsigned char)ft_min(c.green * 255.0f, 255.0f);
	e->pixel_img[CENTER][y * e->s_line[CENTER] + x * e->bpp[CENTER]
		/ 8 + 2] = (unsigned char)ft_min(c.red * 255.0f, 255.0f);
	if (e->debug == 1)
	{
		e->pixel_img[CENTER][y * e->s_line[CENTER] + x * e->bpp[CENTER]
			/ 8 + 2] = 255;
		e->pixel_img[CENTER][y * e->s_line[CENTER] + x * e->bpp[CENTER]
			/ 8] = 0;
		e->pixel_img[CENTER][y * e->s_line[CENTER] + x * e->bpp[CENTER]
			/ 8 + 1] = 0;
	}
}

/*
**	GET_PT_COLOR function:
**	Gets the color of the point in the img
*/

t_color	get_pt_color(int x, int y, t_env *e)
{
	t_color	c;

	x = (int)ft_clamp(0, IMG_W - 1, x);
	y = (int)ft_clamp(0, IMG_H - 1, y);
	c.blue = e->pixel_img[CENTER][y * e->s_line[CENTER]
		+ x * e->bpp[CENTER] / 8];
	c.green = e->pixel_img[CENTER][y * e->s_line[CENTER]
		+ x * e->bpp[CENTER] / 8 + 1];
	c.red = e->pixel_img[CENTER][y * e->s_line[CENTER]
		+ x * e->bpp[CENTER] / 8 + 2];
	return (c);
}

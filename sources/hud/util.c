/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:21:01 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/29 16:22:59 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

/*
**	GET_COLOR function:
**	Get the color for a pixel from an img, used with the insert_xpm function
*/

static int	get_color(int x, int y, t_img img)
{
	int color;

	if (x < img.w && x >= 0 && y < img.h && y >= 0)
	{
		color = *(int *)&img.pixel_img[x * (img.bpp / 8) + y * img.s_line];
		return (color);
	}
	return (0);
}

/*
**	INSERT_XPM function:
**	Insert and xpm file to the image, if one of the mlx function fail, exit
*/

void		insert_xpm(int nb, t_pix pt, char *name, t_env *e)
{
	t_img	img;
	int		i;
	int		j;
	t_colo	c;
	t_pix	tmp;

	if (!(img.img = mlx_xpm_file_to_image(e->mlx, name, &img.w, &img.h))
	|| !(img.pixel_img = (unsigned char*)mlx_get_data_addr(img.img, &img.bpp,
			&img.s_line, &img.ed)))
		ft_printerror("Error mlx");
	c.val = 0;
	j = -1;
	while (++j < img.h)
	{
		i = -1;
		while (++i < img.w)
		{
			tmp.x = i + pt.x;
			tmp.y = j + pt.y;
			c.val = get_color(i, j, img);
			color_point(nb, tmp, c.val, e);
		}
	}
}

/*
**	COLOR_POINT function:
**	Color a pixel at coordinates pt with the color
*/

void		color_point(int nb, t_pix pt, int color, t_env *e)
{
	int width;
	int height;

	width = 0;
	height = 0;
	if (nb == RIGHT)
	{
		width = RIGHT_SPC;
		height = IMG_H;
	}
	else if (nb == BOTTOM)
	{
		width = WIN_W;
		height = BOTTOM_SPC;
	}
	if (pt.x < width && pt.x >= 0 && pt.y < height && pt.y >= 0)
		*(int *)&e->pixel_img[nb][(int)pt.x * (e->bpp[nb] / 8)
			+ (int)pt.y * e->s_line[nb]] = color;
}

/*
**	COLOR_PICKER function:
**	Get the color for a pixel from coordinates pt
*/

int			color_picker(int nb, t_pix pt, t_env *e)
{
	int width;
	int height;
	int color;

	width = 0;
	height = 0;
	if (nb == RIGHT)
	{
		width = RIGHT_SPC;
		height = IMG_H;
	}
	else if (nb == BOTTOM)
	{
		width = WIN_W;
		height = BOTTOM_SPC;
	}
	if (pt.x < width && pt.x >= 0 && pt.y < height && pt.y >= 0)
	{
		color = *(int *)&e->pixel_img[nb][(int)pt.x * (e->bpp[nb] / 8)
			+ (int)pt.y * e->s_line[nb]];
		return (color);
	}
	return (0);
}

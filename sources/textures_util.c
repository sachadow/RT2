/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:12:07 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/23 14:08:40 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	open_texture(t_env *e, t_img *tex, char *name)
{
	if (!(tex->img = mlx_xpm_file_to_image(e->mlx, name, &tex->w, &tex->h)))
		ft_printerror("Error mlx");
	if (!(tex->pixel_img = (unsigned char *)mlx_get_data_addr(tex->img, &tex->bpp,
					&tex->s_line, &tex->ed)))
		ft_printerror("Error mlx");
}

void	get_img_color(t_img tex, t_pix p, t_color *c)
{
	if (p.x >= 0 && p.x < tex.w && p.y >= 0 && p.y < tex.h)
	{
		c->blue = tex.pixel_img[p.y * tex.s_line + p.x * (tex.bpp / 8)];
		c->green = tex.pixel_img[p.y * tex.s_line + p.x * (tex.bpp / 8) + 1];
		c->red = tex.pixel_img[p.y * tex.s_line + p.x * (tex.bpp / 8) + 2];
	}
}

t_pix	rotate_pix(double angle, t_pix p)
{
	t_pix	res;

	if (!angle)
		return (p);
	angle = angle * M_PI / 180;
	res.x = (int)round(p.x * cos(angle) - p.y * sin(angle));
	res.y = (int)round(p.x * sin(angle) + p.y * cos(angle));
	return (res);
}

t_pix	adjust_pix(t_pix p, int w, int h)
{
	t_pix	res;

	res.x = p.x % w;
	res.y = p.y % h;
	if (res.x < 0)
		res.x += w;
	if (res.y < 0)
		res.y += h;
	return (res);
}
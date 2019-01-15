/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ui1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:55:02 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/15 16:07:09 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

static void	double_diffuse_type(t_env *e)
{
	e->mat[e->itf.item.mat] = e->itf.mat;
	e->mat[e->itf.item.mat].diffuse.red =
		(double)e->itf.spec_shade[1].argb[R];
	e->mat[e->itf.item.mat].diffuse.green =
		(double)e->itf.spec_shade[1].argb[G];
	e->mat[e->itf.item.mat].diffuse.blue =
		(double)e->itf.spec_shade[1].argb[B];
	if (e->itf.mat.type == WAVES)
		waves_tex_build(&e->mat[e->itf.item.mat].tex,
				e->mat[e->itf.item.mat].diffuse);
	else
	{
		e->mat[e->itf.item.mat].diffuse2.red =
			(double)e->itf.spec_shade[2].argb[R];
		e->mat[e->itf.item.mat].diffuse2.green =
			(double)e->itf.spec_shade[2].argb[G];
		e->mat[e->itf.item.mat].diffuse2.blue =
			(double)e->itf.spec_shade[2].argb[B];
	}
	if (e->itf.mat.type == CHECKER)
		checker_tex_build(&e->mat[e->itf.item.mat].tex,
				e->mat[e->itf.item.mat].diffuse,
				e->mat[e->itf.item.mat].diffuse2);
}

static void	apply_mat(int type, t_env *e)
{
	if (type == UNIFORM && e->itf.spec[0].val)
	{
		e->mat[e->itf.item.mat] = e->itf.mat;
		e->mat[e->itf.item.mat].diffuse.red =
			(double)e->itf.spec_shade[0].argb[R];
		e->mat[e->itf.item.mat].diffuse.green =
			(double)e->itf.spec_shade[0].argb[G];
		e->mat[e->itf.item.mat].diffuse.blue =
			(double)e->itf.spec_shade[0].argb[B];
	}
	else if ((type == CHECKER || type == MARBLE || type == PERTURB
			|| type == WOOD || type == WAVES)
			&& (e->itf.spec[1].val || e->itf.spec[2].val))
		double_diffuse_type(e);
}

static void	fill_texture(char **s)
{
	s[0] = "textures/redbrick.xpm";
	s[1] = "textures/bluestone.xpm";
	s[2] = "textures/colorstone.xpm";
	s[3] = "textures/wood.xpm";
	s[4] = NULL;
}

static void	apply_texture(t_env *e)
{
	t_img	img;
	char	*s[5];

	fill_texture(s);
	if (!(img.img = mlx_xpm_file_to_image(e->mlx, s[e->itf.nb_texture - 1],
					&img.w, &img.h))
			|| !(img.pixel_img = (unsigned char *)mlx_get_data_addr(img.img,
					&img.bpp, &img.s_line, &img.ed)))
		ft_printerror("Error mlx");
	e->mat[e->itf.item.mat] = e->itf.mat;
	e->mat[e->itf.item.mat].tex = img;
	e->mat[e->itf.item.mat].tex.realw = 100;
	e->mat[e->itf.item.mat].tex.realh = 100;
	e->mat[e->itf.item.mat].type = TEXTURE;
	e->mat[e->itf.item.mat].path_text = s[e->itf.nb_texture - 1];
	e->mat[e->itf.item.mat].diffuse.red = 0;
	e->mat[e->itf.item.mat].diffuse.green = 0;
	e->mat[e->itf.item.mat].diffuse.blue = 0;
}

void		reset_ui(t_env *e)
{
	e->apply = 0;
	if (e->itf.pick.button != -1)
	{
		if (e->itf.nb_texture)
			apply_texture(e);
		apply_mat(e->itf.mat.type, e);
	}
	ft_memset(&e->itf.mat, 0, sizeof(t_mat) * 1);
	ft_memset(&e->itf.item, 0, sizeof(t_item) * 1);
	e->itf.pick.button = -1;
	e->itf.nb_texture = 0;
}

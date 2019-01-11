/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ui1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:55:02 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/10 19:25:29 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

static void	apply_texture(char **s, t_env *e)
{
	t_img	img;

	if (!(img.img = mlx_xpm_file_to_image(e->mlx, s[e->itf.nb_texture - 1],
					&img.w, &img.h))
			|| !(img.pixel_img = (unsigned char *)mlx_get_data_addr(img.img,
					&img.bpp, &img.s_line, &img.ed)))
		ft_printerror("Error mlx");
	e->mat[e->itf.item.mat].tex = img;
	e->mat[e->itf.item.mat].tex.realw = 100;
	e->mat[e->itf.item.mat].tex.realh = 100;
	e->mat[e->itf.item.mat].type = TEXTURE;
	e->mat[e->itf.item.mat].path_text = s[e->itf.nb_texture - 1];
	e->mat[e->itf.item.mat].diffuse.red = 0;
	e->mat[e->itf.item.mat].diffuse.green = 0;
	e->mat[e->itf.item.mat].diffuse.blue = 0;
}

static void	fill_texture(char **s)
{
	s[0] = "textures/redbrick.xpm";
	s[1] = "textures/bluestone.xpm";
	s[2] = "textures/colorstone.xpm";
	s[3] = "textures/wood.xpm";
	s[4] = NULL;
}

void		reset_ui(t_env *e)
{
	char	*s[5];

	fill_texture(s);
	e->apply = 0;
	if (e->itf.pick.button != -1)
	{
		e->mat[e->itf.item.mat] = e->itf.mat;
		if (e->itf.nb_texture)
			apply_texture(s, e);
	}
	ft_memset(&e->itf.mat, 0, sizeof(t_mat) * 1);
	ft_memset(&e->itf.item, 0, sizeof(t_item) * 1);
	e->itf.pick.button = -1;
	e->itf.nb_texture = 0;
}

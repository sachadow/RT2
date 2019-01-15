/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:27:07 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/11 17:28:21 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

static void	find_texture(t_env *e)
{
	if (e->itf.mat.type == 1)
	{
		if (!ft_strcmp(e->itf.mat.path_text, "textures/redbrick.xpm"))
			e->itf.nb_texture = 1;
		if (!ft_strcmp(e->itf.mat.path_text, "textures/bluestone.xpm"))
			e->itf.nb_texture = 2;
		if (!ft_strcmp(e->itf.mat.path_text, "textures/colorstone.xpm"))
			e->itf.nb_texture = 3;
		if (!ft_strcmp(e->itf.mat.path_text, "textures/wood.xpm"))
			e->itf.nb_texture = 4;
	}
}

static void	write_item(char *s, t_env *e)
{
	mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 50, BLACK, s);
	free(s);
	s = ft_itoa(e->itf.item.mat);
	mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 100, BLACK, s);
	free(s);
}

static void	item_selector(t_env *e)
{
	char	*s;

	if (e->itf.item.item_type == SPHERE)
		s = ft_strdup("Sphere");
	if (e->itf.item.item_type == PLANE)
		s = ft_strdup("Plane");
	if (e->itf.item.item_type == I_CONE)
		s = ft_strdup("Inf. Cone");
	if (e->itf.item.item_type == I_CYL)
		s = ft_strdup("Inf. Cylinder");
	if (e->itf.item.item_type == DISK)
		s = ft_strdup("Disk");
	if (e->itf.item.item_type == F_CYL)
		s = ft_strdup("Fin. Cylinder");
	if (e->itf.item.item_type == F_CONE)
		s = ft_strdup("Fin. Cone");
	if (e->itf.item.item_type == BOX)
		s = ft_strdup("Box");
	if (e->itf.item.item_type == QUADRIC)
		s = ft_strdup("Quadric");
	if (e->itf.item.item_type == TORUS)
		s = ft_strdup("Torus");
	write_item(s, e);
}

void		picked_item(t_env *e)
{
	t_rect	rect;

	mlx_string_put(e->mlx, e->win, IMG_W + 5, 50, BLACK, "Item:");
	rect = init_rect(IMG_W + 7, 72, 42, 2);
	draw_line(rect, BLACK, e);
	if (e->itf.pick.button == -1)
	{
		mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 50, BLACK,
				"None");
		mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 100, BLACK,
				"None");
	}
	else
		item_selector(e);
	mlx_string_put(e->mlx, e->win, IMG_W + 5, 100, BLACK, "Mat.:");
	rect = init_rect(IMG_W + 7, 122, 42, 2);
	draw_line(rect, BLACK, e);
}

int			pick_item(t_mouse mouse, t_env *e)
{
	t_ray	r;
	t_vec	impact;
	int		nb;

	if (mouse.x > 0 && mouse.x < IMG_W && mouse.y > 0 && mouse.y < IMG_H)
	{
		r.start = e->cam->pos;
		r.dir = set_ray_dir(mouse.x, mouse.y, e);
		nb = find_closest_item(r, e, &impact) % (e->nbs[ITEM] + 1);
		if (nb != e->itf.pick.button)
		{
			e->itf.pick.button = nb;
			e->itf.pick.x = mouse.x;
			e->itf.pick.y = mouse.y;
			e->itf.mat = e->mat[e->item[nb].mat];
			e->itf.item = e->item[nb];
			find_texture(e);
			conv_all_param(e);
//			printf("nb = %d, item_type %d, nb_mat %d, mat type %d, reflection %f, transparency %f, specvalue %f, specpower %f, n %f, bump %f, scale %f, color = r %f g %f b %f, pick button %d\n", nb, e->item[nb].item_type, e->itf.item.mat, e->mat[e->item[nb].mat].type, e->mat[e->item[nb].mat].reflection, e->mat[e->item[nb].mat].transparency, e->mat[e->item[nb].mat].specvalue, e->mat[e->item[nb].mat].specpower, e->mat[e->item[nb].mat].n, e->mat[e->item[nb].mat].bump, e->mat[e->item[nb].mat].scale, e->mat[e->item[nb].mat].diffuse.red, e->mat[e->item[nb].mat].diffuse.green, e->mat[e->item[nb].mat].diffuse.blue, e->itf.pick.button);
			printf("nb = %d, item_type %d, nb_mat %d, mat type %d, reflection %f, transparency %f, specvalue %f, specpower %f, n %f, bump %f, scale %f, color = r %f g %f b %f, pick.button %d\n", nb, e->itf.item.item_type, e->itf.item.mat, e->itf.mat.type, e->itf.mat.reflection, e->itf.mat.transparency, e->itf.mat.specvalue, e->itf.mat.specpower, e->itf.mat.n, e->itf.mat.bump, e->itf.mat.scale, e->itf.mat.diffuse.red, e->itf.mat.diffuse.green, e->itf.mat.diffuse.blue, e->itf.pick.button);
		}
		else
		{
			e->itf.pick.button = -1;
			ft_memset(&e->itf.item, 0, sizeof(t_item));
			ft_memset(&e->itf.mat, 0, sizeof(t_mat));
			e->itf.nb_texture = 0;
		}
	}
	return (0);
}

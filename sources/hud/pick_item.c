/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:27:07 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/20 20:44:32 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

static void	item_selector(t_env *e)
{
	char	*s;

	if (e->itf.item.item_type == 1)
		s = ft_strdup("Sphere");
	if (e->itf.item.item_type == 2)
		s = ft_strdup("Plane");
	if (e->itf.item.item_type == 3)
		s = ft_strdup("Inf. Cone");
	if (e->itf.item.item_type == 4)
		s = ft_strdup("Inf. Cylinder");
	if (e->itf.item.item_type == 5)
		s = ft_strdup("Disk");
	if (e->itf.item.item_type == 6)
		s = ft_strdup("Fin. Cylinder");
	if (e->itf.item.item_type == 7)
		s = ft_strdup("Fin. Cone");
	if (e->itf.item.item_type == 8)
		s = ft_strdup("Box");
	mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 50, BLACK, s);
	free(s);
	s = ft_itoa(e->itf.item.mat);
	mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 100, BLACK, s);
	free(s);
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
		if (e->debug)
			printf("hud\n");
		if (nb > -1)
		{
			e->itf.pick.button = nb;
			e->itf.pick.x = mouse.x;
			e->itf.pick.y = mouse.y;
			e->itf.mat = e->mat[e->item[nb].mat];
			e->itf.item = e->item[nb];
			printf("nb = %d, item_type %d, nb_mat %d, mat type %d, reflection %f, transparency %f, specvalue %f, specpower %f, n %f, bump %f, scale %f, color = r %f g %f b %f\n", nb, e->item[nb].item_type, e->itf.item.mat, e->mat[e->item[nb].mat].type, e->mat[e->item[nb].mat].reflection, e->mat[e->item[nb].mat].transparency, e->mat[e->item[nb].mat].specvalue, e->mat[e->item[nb].mat].specpower, e->mat[e->item[nb].mat].n, e->mat[e->item[nb].mat].bump, e->mat[e->item[nb].mat].scale, e->mat[e->item[nb].mat].diffuse.red, e->mat[e->item[nb].mat].diffuse.green, e->mat[e->item[nb].mat].diffuse.blue);
		}
		else
		{
			e->itf.pick.button = -1;
			ft_memset(&e->itf.item, 0, sizeof(t_item));
			ft_memset(&e->itf.mat, 0, sizeof(t_mat));
		}
	}
	return (0);
}

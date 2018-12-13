/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:27:07 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/12 19:47:26 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

static void	item_selector(int nb, t_env *e)
{
	char	*s;

	if (e->item[nb].item_type == 1)
		s = ft_strdup("Sphere");
	if (e->item[nb].item_type == 2)
		s = ft_strdup("Plane");
	if (e->item[nb].item_type == 3)
		s = ft_strdup("Inf. Cone");
	if (e->item[nb].item_type == 4)
		s = ft_strdup("Inf. Cylinder");
	if (e->item[nb].item_type == 5)
		s = ft_strdup("Disk");
	if (e->item[nb].item_type == 6)
		s = ft_strdup("Fin. Cylinder");
	if (e->item[nb].item_type == 7)
		s = ft_strdup("Fin. Cone");
	if (e->item[nb].item_type == 8)
		s = ft_strdup("Box");
	mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 50, BLACK, s);
	free(s);
	s = ft_itoa(e->item[nb].mat);
	mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 100, BLACK, s);
	free(s);
}

void		draw_line(t_pix pt, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 42)
		{
			tmp = init_point(pt.x + j, pt.y + i);
			mlx_pixel_put(e->mlx, e->win, tmp.x, tmp.y, BLACK);
		}
	}
}

void		picked_item(t_env *e)
{
	t_pix	pt;

	mlx_string_put(e->mlx, e->win, IMG_W + 5, 50, BLACK, "Item:");
	pt = init_point(IMG_W + 5, 72);
	draw_line(pt, e);
	if (e->interface.item.button == -1)
	{
		mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 50, BLACK,
				"None");
		mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, 100, BLACK,
				"None");
	}
	else
		item_selector(e->interface.item.button, e);
	mlx_string_put(e->mlx, e->win, IMG_W + 5, 100, BLACK, "Mat.:");
	pt = init_point(IMG_W + 5, 122);
	draw_line(pt, e);
}

int			pick_item(int button, int x, int y, t_env *e)
{
	t_ray	r;
	t_vec	impact;
	int		nb;

	if (x > 0 && x < IMG_W && y > 0 && y < IMG_H)
	{
		r.start = e->cam->pos;
		r.dir = set_ray_dir(x, y, e);
		nb = find_closest_item(r, e, &impact);
		if (nb > -1)
		{
			e->interface.item.button = nb;
			e->interface.item.x = x;
			e->interface.item.y = y;
			printf("nb = %d, item_type %d, nb_mat %d, reflection %f, transparency %f, specvalue %f, specpower %f, n %f, bump %f, scale %f, color = r %f g %f b %f\n", nb, e->item[nb].item_type, e->item[nb].mat, e->mat[e->item[nb].mat].reflection, e->mat[e->item[nb].mat].transparency, e->mat[e->item[nb].mat].specvalue, e->mat[e->item[nb].mat].specpower, e->mat[e->item[nb].mat].n, e->mat[e->item[nb].mat].bump, e->mat[e->item[nb].mat].scale, e->mat[e->item[nb].mat].diffuse.red, e->mat[e->item[nb].mat].diffuse.green, e->mat[e->item[nb].mat].diffuse.blue);
		}
		else
			e->interface.item.button = -1;
	}
	(void)button;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:27:08 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/15 16:17:34 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

static void	init_str(char **s)
{
	s[0] = "Reflection";
	s[1] = "Transparency";
	s[2] = "Spec. value";
	s[3] = "Spec. power";
	s[4] = "Refractive index";
	s[5] = "Bump";
	s[6] = "Scale";
	s[7] = NULL;
}

void		ui3_writting(t_env *e)
{
	char	*s[8];

	if (e->itf.pick.button != -1)
	{
		init_str(s);
		mlx_string_put(e->mlx, e->win, WIN_W / 8 - WIN_W / 8 / 3, IMG_H, BLACK,
			s[0]);
		mlx_string_put(e->mlx, e->win, 2 * WIN_W / 8 - WIN_W / 8 / 2,
			IMG_H + 5 * (BOTTOM_SPC) / 6, BLACK, s[1]);
		mlx_string_put(e->mlx, e->win, 3 * WIN_W / 8 - WIN_W / 8 / 2 + 10,
			IMG_H, BLACK, s[2]);
		mlx_string_put(e->mlx, e->win, 4 * WIN_W / 8 - WIN_W / 8 / 2 + 10,
			IMG_H + 5 * (BOTTOM_SPC) / 6, BLACK, s[3]);
		mlx_string_put(e->mlx, e->win, 5 * WIN_W / 8 - 2 * WIN_W / 8 / 3 + 10,
			IMG_H, BLACK, s[4]);
		mlx_string_put(e->mlx, e->win, 6 * WIN_W / 8 - WIN_W / 8 / 4 + 10,
			IMG_H + 5 * (BOTTOM_SPC) / 6, BLACK, s[5]);
		if (e->itf.mat.type == MARBLE || e->itf.mat.type == PERTURB
				|| e->itf.mat.type == WOOD)
			mlx_string_put(e->mlx, e->win, 7 * WIN_W / 8 - WIN_W / 8 / 4 + 10,
				IMG_H, BLACK, s[6]);
	}
}

void		ui3(t_env *e)
{
	t_rect	r;

	r = init_rect(MARGE, CIRCLE, BOTTOM_SPC - 2 * MARGE, 4 * MARGE);
	draw_rect(RIGHT, r, WHITE, e);
	ui3_bottom(e);
}

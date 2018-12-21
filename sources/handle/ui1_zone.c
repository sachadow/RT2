/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:51:34 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/20 20:29:57 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

static void	ui_texture(t_mouse m, t_env *e)
{
	if (m.x >= TEXT1_XS && m.x < TEXT1_XE && m.y >= TEXT1_YS && m.y < TEXT1_YE)
		e->itf.nb_texture = (e->itf.nb_texture == 1 ? 0 : 1);
	if (m.x >= TEXT2_XS && m.x < TEXT2_XE && m.y >= TEXT1_YS && m.y < TEXT1_YE)
		e->itf.nb_texture = (e->itf.nb_texture == 2 ? 0 : 2);
	if (m.x >= TEXT1_XS && m.x < TEXT1_XE && m.y >= TEXT2_YS && m.y < TEXT2_YE)
		e->itf.nb_texture = (e->itf.nb_texture == 3 ? 0 : 3);
	if (m.x >= TEXT2_XS && m.x < TEXT2_XE && m.y >= TEXT2_YS && m.y < TEXT2_YE)
		e->itf.nb_texture = (e->itf.nb_texture == 4 ? 0 : 4);
}

static void	filters(t_mouse m, t_env *e)
{
	if (m.x >= SEPIA_XS && m.x < SEPIA_XE && m.y >= SEPIA_YS && m.y < SEPIA_YE)
		e->filter = (e->filter == SEPIA ? 0 : SEPIA);
	if (m.x >= GSCAL_XS && m.x < GSCAL_XE && m.y >= GSCAL_YS && m.y < GSCAL_YE)
		e->filter = (e->filter == GREYSCALE ? 0 : GREYSCALE);
	if (m.x >= SATUR_XS && m.x < SATUR_XE && m.y >= SATUR_YS && m.y < SATUR_YE)
		e->filter = (e->filter == SATURATE ? 0 : SATURATE);
	if (m.x >= REVER_XS && m.x < REVER_XE && m.y >= REVER_YS && m.y < REVER_YE)
		e->filter = (e->filter == REVERSE ? 0 : REVERSE);
	if (m.x >= CARTO_XS && m.x < CARTO_XE && m.y >= CARTO_YS && m.y < CARTO_YE)
		e->cartoon = (e->cartoon == 1 ? 0 : 1);
	if (m.x >= ALIAS0XS && m.x < ALIAS0XE && m.y >= ALIAS_YS && m.y < ALIAS_YE)
		e->antialiasing = 0;
	if (m.x >= ALIAS1XS && m.x < ALIAS1XE && m.y >= ALIAS_YS && m.y < ALIAS_YE)
		e->antialiasing = 1;
	if (m.x >= ALIAS2XS && m.x < ALIAS2XE && m.y >= ALIAS_YS && m.y < ALIAS_YE)
		e->antialiasing = 2;
}

void		ui1_zones(int nb, t_mouse mouse, t_env *e)
{
	if (nb == 1)
	{
		if (mouse.x >= APPLY_XS && mouse.x < APPLY_XE && mouse.y >= APPLY_YS
				&& mouse.y < APPLY_YE)
		{
			e->loading = 0;
			e->apply = 1;
			reload(e);
		}
		filters(mouse, e);
		ui_texture(mouse, e);
	}
}

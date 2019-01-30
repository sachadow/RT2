/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui3_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:26:53 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 20:43:21 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	UI3_ZONE function:
**	Select the new lvl of refraction for the scene if the user click on the lvl
**	tab or set to 0 the 3 e->itf.spectrum to reset the 3 color spectrum value
*/

void		ui3_zone(t_mouse m, t_env *e)
{
	if (m.x >= IMG_W + RIGHT_SPC / 2 - 45 && m.x <= IMG_W + RIGHT_SPC / 2 + 45
			&& m.y >= IMG_H / 2 - 5 && m.y <= IMG_H / 2 + 5)
		e->lvl = (m.x - (IMG_W + RIGHT_SPC / 2 - 45)) / 3;
	else if (m.x >= IMG_W + 30 && m.x <= WIN_W - 2 * MARGE
			&& m.y >= M_IMG_H + 50 && m.y <= M_IMG_H + 70)
		ft_memset(e->itf.spectrum, 0, sizeof(e->itf.spectrum));
}

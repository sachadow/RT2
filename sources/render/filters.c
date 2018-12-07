/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:48:17 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/07 15:13:49 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	add_sepia_filter(t_color c)
{
	t_color	k;

	k.red = c.red * 0.189 + c.green * 0.769 + c.blue * 0.393;
	k.green = c.red * 0.168 + c.green * 0.686 + c.blue * 0.349;
	k.blue = c.red * 0.131 + c.green * 0.534 + c.blue * 0.272;
	return (k);
}

t_color	add_greyscale_filter(t_color c)
{
	t_color	k;

	k.red = c.red * 0.2989 + c.green * 0.5870 + c.blue * 0.1140;
	k.green = c.red * 0.2989 + c.green * 0.5870 + c.blue * 0.1140;
	k.blue = c.red * 0.2989 + c.green * 0.5870 + c.blue * 0.1140;
	return (k);
}

t_color	add_reverse_filter(t_color c)
{
	t_color	k;

	k.red = 1.0f - c.red;
	k.green = 1.0f - c.green;
	k.blue = 1.0f - c.blue;
	return (k);
}

t_color	add_saturate_filter(t_color c)
{
	t_hsv	hsv;

	hsv = color_to_hsv(c);
	hsv.s += (hsv.s > 0.20 ? (1.0f - hsv.s) * 0.30f : 0.0f);
	hsv.s = (hsv.s > 1.0f ? 1.0f : hsv.s);
	hsv.v += (1.0f - hsv.v) * 0.10f;
	hsv.v = (hsv.v > 1.0f ? 1.0f : hsv.v);
	return (hsv_to_color(hsv));
}

void	add_cartoon_effect(t_pix p, t_env *e)
{
	t_color	c;
	short	sum;

	c = get_pt_color(p.x, p.y, e);
	sum = 255 - sqrt(x_g(e, p, 'X') * x_g(e, p, 'X') + x_g(e, p, 'Y')
			* x_g(e, p, 'Y'));
	sum = ft_clamp(0, 255, sum);
	if (sum > 100)
	{
		c.red = limit_clr(c.red);
		c.green = limit_clr(c.green);
		c.blue = limit_clr(c.blue);
	}
	draw_point(e, p.x, p.y, c);
}

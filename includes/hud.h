/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:17:02 by qsebasti          #+#    #+#             */
/*   Updated: 2018/11/23 19:04:59 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "rt.h"

# define B		0
# define G		1
# define R		2
# define A		3

# define BLACK	0x000000
# define GREY	0xd2d0d2
# define WHITE	0xffffff
# define RED	0xff0000

# define ZONE1_XS	800
# define ZONE1_XE	866
# define ZONE1_YS	0
# define ZONE1_YE	830

# define ZONE2_XS	867
# define ZONE2_XE	933
# define ZONE2_YS	0
# define ZONE2_YE	830

# define ZONE3_XS	934
# define ZONE3_XE	1000
# define ZONE3_YS	0
# define ZONE3_YE	830

typedef struct		s_size
{
	int				width;
	int				length;
}					t_size;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

void				color_point(int num, t_point pt, int color, t_env *e);
void				draw_rect(int num, t_point pt, t_size rect, int color, t_env *e);
void				tab(t_env *e);
void				insert_xpm(int num, t_point pt, char *name, t_env *e);

#endif

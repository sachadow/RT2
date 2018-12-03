/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:17:02 by qsebasti          #+#    #+#             */
/*   Updated: 2018/11/30 21:19:31 by qsebasti         ###   ########.fr       */
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
# define GREEN	0x00ff00
# define BLUE	0x0000ff

# define ZONE1_XS	IMG_W
# define ZONE1_XE	IMG_W + (RIGHT_SPC) / 3
# define ZONE1_YS	0
# define ZONE1_YE	30

# define ZONE2_XS	IMG_W + (RIGHT_SPC) / 3 + 1
# define ZONE2_XE	IMG_W +  2 * ((RIGHT_SPC) / 3 + 1)
# define ZONE2_YS	0
# define ZONE2_YE	30

# define ZONE3_XS	IMG_W +  2 * ((RIGHT_SPC) / 3 + 1)
# define ZONE3_XE	WIN_W
# define ZONE3_YS	0
# define ZONE3_YE	30

typedef struct		s_size
{
	int				width;
	int				length;
}					t_size;

t_size				init_size(int width, int length);
t_pix				init_point(int x, int y);
void				color_point(int num, t_pix pt, int color, t_env *e);
int					color_picker(int num, t_pix pt, t_env *e);
void				draw_rect(int num, t_pix pt, t_size rect, int color,
					t_env *e);

void				tab(t_env *e);

void				ui1(t_env *e);
void				ui1_spectrum(int x, int y, t_env *e);
void				cursor_spectrum(t_env *e);

void				insert_xpm(int num, t_pix pt, char *name, t_env *e);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:17:02 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/06 17:37:37 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "rt.h"

# define B		0
# define G		1
# define R		2
# define A		3

# define BLACK		0x000000
# define LIGHT_GREY	0xd2d0d2
# define GREY		0xb0b0b0
# define DARK_GREY	0x454545
# define WHITE		0xffffff
# define RED		0xff0000
# define GREEN		0x00ff00
# define BLUE		0x0000ff

# define MARGE		15
# define CIRCLE_W	(RIGHT_SPC) - 2 * MARGE
# define CIRCLE_H	(RIGHT_SPC) - 2 * MARGE

# define Z1_XS		IMG_W
# define Z1_XE		IMG_W + (RIGHT_SPC) / 3
# define Z1_YS		0
# define Z1_YE		2 * MARGE

# define Z2_XS		IMG_W + (RIGHT_SPC) / 3 + 1
# define Z2_XE		IMG_W +  2 * ((RIGHT_SPC) / 3 + 1)
# define Z2_YS		0
# define Z2_YE		2 * MARGE

# define Z3_XS		IMG_W +  2 * ((RIGHT_SPC) / 3 + 1)
# define Z3_XE		WIN_W
# define Z3_YS		0
# define Z3_YE		2 * MARGE

# define Z4_XS		MARGE + IMG_W
# define Z4_XE		IMG_W + RIGHT_SPC - MARGE
# define Z4_YS		M_IMG_H + RIGHT_SPC - 2 * MARGE + MARGE
# define Z4_YE		M_IMG_H + RIGHT_SPC - 2 * MARGE + MARGE + MARGE


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
void				draw_tri(int num, t_pix pt, t_size base, int color,
					t_env *e);
void				draw_rev_tri(int num, t_pix pt, t_size base, int color,
					t_env *e);
void				frame(int num, t_pix pt, t_size rect, int color, t_env *e);

void				tab(t_env *e);

void				ui1(t_env *e);
void				ui1_bottom(t_env *e);
int					ui1_spectrum(int button, int x, int y, t_env *e);
void				cursor_spectrum(t_env *e);
void				ui1_shade(int button, int x, int y, t_env *e);
void				cursor_shade(t_env *e);
void				shade_bar(t_env *e);
void				color_val(t_env *e);

void				insert_xpm(int num, t_pix pt, char *name, t_env *e);
void				load(t_env *e);

#endif

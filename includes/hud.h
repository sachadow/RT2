/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:17:02 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/12 20:56:37 by qsebasti         ###   ########.fr       */
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

# define TAB1_XS	IMG_W
# define TAB1_XE	IMG_W + (RIGHT_SPC) / 3
# define TAB1_YS	0
# define TAB1_YE	2 * MARGE

# define TAB2_XS	IMG_W + (RIGHT_SPC) / 3 + 1
# define TAB2_XE	IMG_W +  2 * ((RIGHT_SPC) / 3 + 1)
# define TAB2_YS	0
# define TAB2_YE	2 * MARGE

# define TAB3_XS	IMG_W +  2 * ((RIGHT_SPC) / 3 + 1)
# define TAB3_XE	WIN_W
# define TAB3_YS	0
# define TAB3_YE	2 * MARGE

# define SHAD1_XS	MARGE + IMG_W
# define SHAD1_XE	IMG_W + RIGHT_SPC - MARGE
# define SHAD1_YS	M_IMG_H + RIGHT_SPC - 2 * MARGE + MARGE
# define SHAD1_YE	M_IMG_H + RIGHT_SPC - 2 * MARGE + MARGE + MARGE

typedef struct		s_size
{
	int				width;
	int				height;
}					t_size;

typedef struct		s_rect
{
	int				x;
	int				y;
	int				width;
	int				height;
}					t_rect;

t_size				init_size(int width, int height);
t_pix				init_point(int x, int y);
t_rect				init_rect(int x, int y, int width, int height);
void				color_point(int nb, t_pix pt, int color, t_env *e);
int					color_picker(int nb, t_pix pt, t_env *e);
void				draw_rect(int nb, t_rect rect, int color,
					t_env *e);
void				draw_tri(int nb, t_rect base, int color,
					t_env *e);
void				draw_rev_tri(int nb, t_rect base, int color,
					t_env *e);
void				frame(int nb, t_rect rect, int color, t_env *e);
void				draw_line(t_pix pt, t_env *e);

void				tab(t_env *e);

void				ui1(t_env *e);
void				ui1_bottom(t_env *e);
int					ui1_spectrum(int button, int x, int y, t_env *e);
void				cursor_spectrum(t_env *e);
void				ui1_shade(int button, int x, int y, t_env *e);
void				cursor_shade(t_env *e);
void				shade_bar(t_env *e);
void				color_val(t_env *e);
void				ui1_bottom_strokes(t_env *e);

void				insert_xpm(int num, t_pix pt, char *name, t_env *e);
void				load(t_env *e);
int					pick_item(int button, int x, int y, t_env *e);
void				picked_item(t_env *e);
void				right_ruler(t_env *e);
void				bottom_ruler(t_env *e);

#endif

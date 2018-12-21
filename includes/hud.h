/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:17:02 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/20 20:42:46 by qsebasti         ###   ########.fr       */
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
# define MIDGREY	0x999999
# define DARK_GREY	0x454545
# define WHITE		0xffffff
# define RED		0xff0000
# define GREEN		0x00ff00
# define BLUE		0x0000ff
# define C_GREEN	0x038403

# define MARGE		15
# define CIRCLE		(RIGHT_SPC) - 2 * MARGE

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

# define APPLY_XS	IMG_W + MARGE
# define APPLY_XE	WIN_W - MARGE
# define APPLY_YS	2 * (M_IMG_H) / 3
# define APPLY_YE	2 * (M_IMG_H) / 3 + 100

# define SHAD1_XS	MARGE + IMG_W
# define SHAD1_XE	IMG_W + RIGHT_SPC - MARGE
# define SHAD1_YS	M_IMG_H + CIRCLE + MARGE
# define SHAD1_YE	M_IMG_H + CIRCLE + MARGE + MARGE

# define SEPIA_XS	WIN_W / 5 + WIN_W / 5 / 4
# define SEPIA_XE	WIN_W / 5 + WIN_W / 5 / 4 + 100
# define SEPIA_YS	IMG_H + (BOTTOM_SPC) / 8
# define SEPIA_YE	IMG_H + (BOTTOM_SPC) / 8 + 60

# define GSCAL_XS	2 * WIN_W / 5 + WIN_W / 5 / 4
# define GSCAL_XE	2 * WIN_W / 5 + WIN_W / 5 / 4 + 100
# define GSCAL_YS	IMG_H + (BOTTOM_SPC) / 8
# define GSCAL_YE	IMG_H + (BOTTOM_SPC) / 8 + 60

# define SATUR_XS	WIN_W / 5 / 4
# define SATUR_XE	WIN_W / 5 / 4 + 100
# define SATUR_YS	IMG_H + 3 * (BOTTOM_SPC) / 5
# define SATUR_YE	IMG_H + 3 * (BOTTOM_SPC) / 5 + 60

# define REVER_XS	WIN_W / 5 + WIN_W / 5 / 4
# define REVER_XE	WIN_W / 5 + WIN_W / 5 / 4 + 100
# define REVER_YS	IMG_H + 3 * (BOTTOM_SPC) / 5
# define REVER_YE	IMG_H + 3 * (BOTTOM_SPC) / 5 + 60

# define CARTO_XS	2 * WIN_W / 5 + WIN_W / 5 / 4
# define CARTO_XE	2 * WIN_W / 5 + WIN_W / 5 / 4 + 100
# define CARTO_YS	IMG_H + 3 * (BOTTOM_SPC) / 5
# define CARTO_YE	IMG_H + 3 * (BOTTOM_SPC) / 5 + 60

# define ALIAS0XS	4 * (WIN_W) / 5 + WIN_W / 7 / 4 - 14
# define ALIAS0XE	4 * (WIN_W) / 5 + WIN_W / 5 / 3
# define ALIAS_YS	IMG_H + 5 * (BOTTOM_SPC) / 8 + 9
# define ALIAS_YE	IMG_H + 5 * (BOTTOM_SPC) / 8 + 59

# define ALIAS1XS	4 * (WIN_W) / 5 + WIN_W / 5 / 3 + 1
# define ALIAS1XE	4 * (WIN_W) / 5 + 2 * WIN_W / 5 / 3 + 12

# define ALIAS2XS	4 * (WIN_W) / 5 + 2 * WIN_W / 5 / 3 + 13
# define ALIAS2XE	ALIAS0XS + 159

# define TEXT1_XS	3 * WIN_W / 5 + (WIN_W / 5) / 10
# define TEXT1_XE	3 * WIN_W / 5 + (WIN_W / 5) / 10 + 64
# define TEXT1_YS	IMG_H + 20
# define TEXT1_YE	IMG_H + 84

# define TEXT2_XS	3 * WIN_W / 5 + ((WIN_W / 5) / 10) * 6
# define TEXT2_XE	3 * WIN_W / 5 + ((WIN_W / 5) / 10) * 6 + 64
# define TEXT2_YS	IMG_H + (BOTTOM_SPC) / 2 + 20
# define TEXT2_YE	IMG_H + (BOTTOM_SPC) / 2 + 84

# define UNIF_XS	4 * WIN_W / 5 + (WIN_W / 5) / 6 - 7
# define UNIF_XE	4 * WIN_W / 5 + (WIN_W / 5) / 6 + 133
# define UNIF_YS	IMG_H + (BOTTOM_SPC) / 8
# define UNIF_YE	IMG_H + (BOTTOM_SPC) / 8 + 2 * MARGE

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
void				draw_line(t_rect rect, int color, t_env *e);

void				tab(t_env *e);

void				ui1(t_env *e);
void				ui1_bottom(t_env *e);
int					ui_spectrum(int nb, t_pix pix, t_mouse mouse, t_env *e);
void				cursor_spectrum(int nb, t_env *e);
void				ui_shade(int nb, t_pix pix, t_mouse mouse, t_env *e);
void				cursor_shade(int nb, t_env *e);
void				shade_bar(int y, int color, t_env *e);
void				color_val(t_env *e);
void				ui1_bottom_strokes(t_env *e);
void				ui1_zones(int nb, t_mouse mouse, t_env *e);

void				ui2(t_env *e);
void				ui2_bottom(t_env *e);
int					ui2_spectrum(int button, int x, int y, t_env *e);
void				ui2_shade(int button, int x, int y, t_env *e);

void				insert_xpm(int num, t_pix pt, char *name, t_env *e);
void				load(t_env *e);
int					pick_item(t_mouse mouse, t_env *e);
void				picked_item(t_env *e);
void				right_ruler(t_env *e);
void				bottom_ruler(t_env *e);

void				reset_ui(t_env *e);
#endif

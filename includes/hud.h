/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:17:02 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/11 21:05:55 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "rt.h"

# define B		0
# define G		1
# define R		2
# define A		3

# define REFLECTION		1
# define TRANSPARENCY	2
# define SPECVALUE		3
# define SPECPOWER		4
# define N				5
# define BUMP			6
# define SCALE			7

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
# define CIRCLE		170

const int			g_shad_xs;
const int			g_shad_xe;
const int			g_shad_ys;
const int			g_shad_ye;

const int			g_filter1_xs;
const int			g_filter1_xe;
const int			g_filter2_xs;
const int			g_filter2_xe;
const int			g_filter3_xs;
const int			g_filter3_xe;

const int			g_filter1_ys;
const int			g_filter1_ye;
const int			g_filter2_ys;
const int			g_filter2_ye;

const int			g_text1_xs;
const int			g_text1_xe;
const int			g_text1_ys;
const int			g_text1_ye;

const int			g_text2_xs;
const int			g_text2_xe;
const int			g_text2_ys;
const int			g_text2_ye;

const int			g_unif_xs;
const int			g_unif_xe;
const int			g_unif_ys;
const int			g_unif_ye;

const int			g_checker_xs;
const int			g_marble_xs;
const int			g_perturb_xs;
const int			g_wood_xs;
const int			g_waves_xs;

const int			g_mat_ys;

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
void				draw_tri_left(int nb, t_rect base, int color,
					t_env *e);
void				draw_tri_right(int nb, t_rect base, int color,
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
void				ui_zones(int nb, t_mouse mouse, t_env *e);
void				param_zone(t_mouse mouse, t_env *e);

void				ui2(t_env *e);
void				ui2_bottom(t_env *e);
int					ui2_spectrum(int button, int x, int y, t_env *e);
void				ui2_shade(int button, int x, int y, t_env *e);

void				ui3(t_env *e);
void				ui3_bottom(t_env *e);
void				ui3_param(t_env *e);
void				ui3_writting(t_env *e);

void				insert_xpm(int num, t_pix pt, char *name, t_env *e);
void				load(t_env *e);
int					pick_item(t_mouse mouse, t_env *e);
void				picked_item(t_env *e);
void				right_ruler(t_env *e);
void				bottom_ruler(t_env *e);

void				reset_ui(t_env *e);

int					int_to_pos(int val, int min, int max);
int					pos_to_int(int pos, int min, int max);
void				conv_all_param(t_env *e);
#endif

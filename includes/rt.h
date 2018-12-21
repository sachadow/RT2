/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:09:49 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/21 15:54:25 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>

# define WIN_H		800
# define WIN_W		1000
# define IMG_H		600
# define IMG_W		800
# define M_IMG_W	400
# define M_IMG_H	IMG_H / 2
# define RIGHT_SPC	WIN_W - IMG_W
# define BOTTOM_SPC	WIN_H - IMG_H
# define NB_THR		8
# define FOV		2.0
# define REFRINCL	4

# define EMPTY		-1
# define CAM		0
# define MAT		1
# define LIGHT		2
# define ITEM		3

# define SPHERE		1
# define PLANE		2
# define I_CONE		3
# define I_CYL		4
# define DISK		5
# define F_CYL		6
# define F_CONE		7
# define BOX		8
# define QUADRIC	9

# define UNIFORM	0
# define TEXTURE	1
# define CHECKER	2
# define MARBLE		3
# define PERTURB	4
# define WAVES		5
# define WOOD		6

# define SEPIA		1
# define GREYSCALE	2
# define REVERSE	3
# define SATURATE	4

# define KPRESSMASK			1L << 0
# define KRELEASEMASK		1L << 1
# define BPRESSMASK			1L << 2
# define BRELEASEMASK		1L << 3
# define PTR_MOTION_MASK	1L << 6
# define SNOTIFYMASK		1L << 17
# define KPRESS				2
# define KRELEASE			3
# define BPRESS				4
# define BRELEASE			5
# define MOTION_NOTIFY		6
# define DESTROY			17

# define CENTER				0
# define RIGHT				1
# define BOTTOM				2

typedef union		u_colo
{
	int				val;
	unsigned char	argb[4];
}					t_colo;

typedef	struct		s_mouse
{
	int				button;
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_sgmt
{
	int				start;
	int				end;
}					t_sgmt;

typedef struct		s_pix
{
	int				x;
	int				y;
}					t_pix;

typedef struct		s_curr
{
	double			t;
	int				ncurr;
	int				curr;
}					t_curr;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_matrix
{
	t_vec			colvec1;
	t_vec			colvec2;
	t_vec			colvec3;
}					t_matrix;

typedef struct		s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_hsv
{
	double			h;
	double			s;
	double			v;
}					t_hsv;

typedef struct		s_ray
{
	t_vec			start;
	t_vec			dir;
}					t_ray;

typedef struct		s_light
{
	t_vec			pos;
	t_color			intensity;
	double			radius;
}					t_light;

typedef struct		s_img
{
	void			*img;
	unsigned char	*pixel_img;
	int				bpp;
	int				s_line;
	int				ed;
	int				w;
	int				h;
	double			realw;
	double			realh;
	double			angle;
	t_vec			center;
	t_vec			direction;
}					t_img;

typedef struct		s_mat
{
	int				type;
	char			*path_text;
	t_img			tex;
	t_color			diffuse;
	t_color			diffuse2;
	double			reflection;
	double			transparency;
	double			specvalue;
	double			specpower;
	double			n;
	double			bump;
	double			scale;
}					t_mat;

typedef struct		s_cam
{
	t_vec			pos;
	t_vec			dir;
}					t_cam;

typedef struct		s_item
{
	int				item_type;
	t_vec			center;
	t_vec			dir;
	t_vec			end;
	double			d;
	double			height;
	double			radius;
	double			angle;
	t_vec			param;
	int				paraboloid;
	int				mat;
	int				isnega;
}					t_item;

typedef struct		s_work
{
	t_ray			r;
	t_color			c;
	t_vec			n_vec;
	double			n;
	double			coef;
	int				item_hit;
	int				id[REFRINCL];
}					t_work;

typedef struct		s_interface
{
	int				onglet;
	t_colo			spec[3];
	t_colo			spec_shade[3];
	t_mouse			spectrum[3];
	t_mouse			shade[3];
	t_mouse			pick;
	t_mat			mat;
	t_item			item;
	int				nb_texture;
}					t_interface;

typedef struct		s_perlin
{
	int				x;
	int				y;
	int				z;
	int				a;
	int				b;
	int				aa;
	int				ab;
	int				ba;
	int				bb;
	double			fx;
	double			fy;
	double			fz;
}					t_perlin;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img[3];
	unsigned char	*pixel_img[3];
	int				bpp[3];
	int				s_line[3];
	int				ed[3];
	int				nbs[4];
	int				key[300];
	int				(*hit[10])(t_ray, t_item, double *);
	int				hit_negative;
	int				curr;
	int				ncurr;
	t_color			backgroundcolor;
	int				lvl;
	int				antialiasing;
	t_cam			*cam;
	t_vec			i;
	t_vec			j;
	t_item			*item;
	t_mat			*mat;
	t_light			*light;
	pthread_t		thr[NB_THR];
	int				debug;
	int				loading;
	int				filter;
	int				cartoon;
	int				apply;
	t_interface		itf;
}					t_env;

int					reload(t_env *e);
int					debug(t_env *e);

int					quit(void);

double				magnitude2(t_vec v);
double				magnitude(t_vec v);
t_vec				normalize(t_vec v);
t_vec				add(t_vec u, t_vec v);
t_vec				sub(t_vec u, t_vec v);

t_vec				crossproduct(t_vec u, t_vec v);
double				dotproduct(t_vec u, t_vec v);
t_vec				scale(double k, t_vec u);
t_vec				opposite(t_vec v);
t_vec				newvec(double x, double y, double z);

int					hitplane(t_ray r, t_item p, double *t);
int					hitdisk(t_ray r, t_item p, double *t);
int					hitsphere(t_ray r, t_item s, double *t);
int					hitcylinder(t_ray r, t_item c, double *t);
int					hitcone(t_ray r, t_item c, double *t);
int					hitfcylinder(t_ray r, t_item cy, double *t);
int					hitfcone(t_ray r, t_item cy, double *t);
int					hitbox(t_ray r, t_item bo, double *t);
int					calc_discr(double a, double b, double c, double *t);

t_vec				calc_h1(t_ray r, t_vec dir);
t_vec				calc_h2(t_vec dist, t_vec dir);

t_color				color_calc(double x, double y, t_env *e);
t_vec				set_ray_dir(double x, double y, t_env *e);
t_color				get_light_value(t_work w, t_vec newstart, t_mat currmat,
					t_env *e);

void				color_lambert(t_color *c, double l, t_light currl,
					t_color matdiff);
double				lambert(t_ray lightray, t_vec n);
void				color_blinnphong(t_color *c, double b, t_light currl);
double				blinnphong(t_ray lightray, t_ray *r, t_vec n,
					t_mat currm);
t_color				lens_flaring(t_ray r, t_env *e);

int					find_closest_item(t_ray r, t_env *e, t_vec *newstart);
int					get_closest_item(t_ray r, t_env *e);
int					find_post_nega(t_ray r, t_env *e, t_vec *newstart,
					t_curr *t);
int					is_empty(int *hit, int count, int *id, t_env *e);
int					get_hits(int* hit, int *id, int last);
void				hit_mod(int* id, int nb, int* hit, t_env *e);
void				init_int_tab(int* tab, int size, int value);
int					got_out(int count, int *nb_hit, int *id, t_env *e);
int					count_items(t_ray r, t_env *e);
t_vec				find_newstart(t_env *e, t_ray r);
t_mat				find_material(int curr, t_env *e);

t_vec				find_normal_vec_if_not_plane(int curr, t_vec newstart,
					t_env *e);
t_vec				find_cone_normal(t_vec newstart, t_item cone);
t_vec				find_cylinder_normal(t_vec newstart, t_item cyl);
t_vec				find_h(t_vec cd, t_vec cc, t_vec n);
t_vec				find_normal_vec(t_ray r, int curr, t_env *e);

t_vec				rotate_x(t_vec u, double angle);
t_vec				rotate_y(t_vec u, double angle);
t_vec				rotate_z(t_vec u, double angle);
t_vec				rotate(t_vec u, double anglex, double angley,
					double anglez);
t_vec				rotate_axis(t_vec u, t_vec r, double angle);

t_color				newcolor(double r, double g, double b);
t_item				newsph(t_vec center, double radius, int mat, int isnega);
t_item				newplane(t_vec dir, double d, int mat);
t_item				newcyl(t_vec dir, t_vec center, double radius, int mat,
					int isnega);
t_item				newdisk(t_vec dir, t_vec center, double radius, int mat);
t_item				newcone(t_vec dir, t_vec center, double angle, int mat,
					int isnega);
t_item				newfcyl(t_vec dir, t_vec center, double radius, int mat,
					double height, int isnega);
t_item				newfcone(t_vec dir, t_vec center, double radius, int mat,
					double height, int isnega);
t_item				newbox(t_vec center, t_vec end, int mat);

t_ray				refracted_ray(t_vec i, t_vec nm, double n, t_vec newstart);
t_ray				reflected_ray(t_vec i, t_vec n, t_vec newstart);
double				fresnel(t_vec i, t_vec n, double n1, double n2);
double				find_nrefr(t_work w, t_mat mat, int item_hit, t_env *e);

t_color				ft_resolve(t_env *e, t_work w, int lvl);
t_work				newwork(t_work oldwork, t_ray newray, int r, t_env *e);
int					itemtype(int curr, t_env *e);

t_color				multiply_color(t_color c, double k);
t_color				add_2colors(t_color a, t_color b);
t_color				add_3colors(t_color a, t_color b, t_color c);
t_color				add_4colors(t_color a, t_color b, t_color c, t_color d);

void				escape(t_env *e);
int					keypress(int keycode, t_env *e);
int					keyrelease(int keycode, t_env *e);
void				key_hook(t_env *e);

void				move_cam(t_env *e);
void				create_axis(t_env *e);
void				show_mouse(t_env *e);
int					mousemove(int x, int y, t_env *e);
int					mousepress(int button, int x, int y, t_env *e);
int					mouserelease(int button, int x, int y, t_env *e);

void				refr_enter_or_exit(t_work *w, int id, int k, t_env *e);
int					position_in_tab(int *tab, int id, int size);
int					add_to_tab(int *tab, int id, int size);
int					remove_from_tab(int *tab, int id, int size);
double				find_max_ior(int *tab, int size, t_env *e);

void				open_texture(t_env *e, t_img *tex, char *name);
void				get_img_color(t_img tex, t_pix p, t_color *c);
t_pix				rotate_pix(t_pix p, int w, int h, double angle);
t_pix				adjust_pix(t_pix p, int w, int h);

t_color				find_texture_color(t_vec newstart, t_work w, t_env *e);
t_color				texture_plane(t_img tex, t_item item, t_vec impact);
t_color				texture_sphere(t_img tex, t_item item, t_work w);
t_color				texture_cylinder(t_img tex, t_item item, t_vec impact);
t_color				texture_cone(t_img tex, t_item item, t_vec impact);

void				checker_tex_build(t_img *tex, t_color c1, t_color c2);
void				waves_tex_build(t_img *tex, t_color c);

double				grad(int hash, double x, double y, double z);
void				perlin(int *p, int *permutation);
double				noise(double x, double y, double z);

t_color				color_marble(t_color c1, t_color c2, t_vec impact,
					double s);
t_color				color_turbulence(t_color c1, t_color c2, t_vec impact,
					double s);
t_color				color_wood(t_color c1, t_color c2, t_vec impact, double s);
t_vec				bumpmapping(t_vec n, t_vec impact, t_mat m);

int					in_shadow(t_ray lightray, t_env *e, double t);
int					negative_shadow(int k, t_ray r, t_env *e);
double				shadow_from_sphere(t_light light, t_vec impact, t_work w,
					t_env *e);
double				shadow_from_point(t_ray lray, t_vec dist, t_env *e);

void				supersamplingx4(t_pix p, t_env *e);
void				supersampling(int k, t_pix p, t_env *e);
void				aliasing(int k, t_pix p, t_env *e);

t_hsv				color_to_hsv(t_color c);
t_color				hsv_to_color(t_hsv hsv);

size_t				limit_clr(size_t color);
int					x_g(t_env *e, t_pix p, char type);

void				draw_point(t_env *e, int x, int y, t_color c);
t_color				get_pt_color(int x, int y, t_env *e);

t_color				add_sepia_filter(t_color c);
t_color				add_greyscale_filter(t_color c);
t_color				add_reverse_filter(t_color c);
t_color				add_saturate_filter(t_color c);
void				add_cartoon_effect(t_env *e);

int					hitquadric(t_ray r, t_item q, double *t);
t_vec				find_quadric_normal(t_vec impact, t_item q);

void				hud(t_env *e);
void				new_image(int num, int width, int height, t_env *e);

#endif

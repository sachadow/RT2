/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:09:49 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/13 15:49:59 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define WIN_H		800
# define WIN_W		1000
# define IMG_H		600
# define IMG_W		800
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

typedef struct		s_sgmt
{
	int				start;
	int				end;
}					t_sgmt;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_color
{
	double			red;
	double			green;
	double			blue;
}					t_color;

typedef struct		s_ray
{
	t_vec			start;
	t_vec			dir;
}					t_ray;

typedef struct		s_light
{
	t_vec			pos;
	t_color			intensity;
}					t_light;

typedef struct		s_mat
{
	t_color			diffuse;
	double			reflection;
	double			transparency;
	double			specvalue;
	double			specpower;
	double			n;
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
	t_vec			signs;
	t_vec			end;
	int				isNega;
	double			d;
	double			height;
	double			radius;
	double			angle;
	int				mat;
}					t_item;

typedef struct		s_work
{
	t_ray			r;
	t_color			c;
	t_vec			n_vec;
	double			n;
	double			coef;
	int				id[REFRINCL];
}					t_work;

typedef struct		s_img
{
	void			*img;
	char			*pixel_img;
	int				bpp;
	int				s_line;
	int				ed;
	int				w;
	int				h;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*pixel_img;
	int				bpp;
	int				s_line;
	int				ed;
	t_img			tex[1];
	int				nbs[4];
	int				key[300];
	int				(*hit[10])(t_ray, t_item, double *);
	int				hit_negative;
	int				ncurr;
	t_color			backgroundcolor;
	int				lvl;
	t_cam			*cam;
	t_vec			i;
	t_vec			j;
	t_item			*item;
	t_mat			*mat;
	t_light			*light;
	pthread_t		thr[NB_THR];
	int				debug;
}					t_env;

int					reload(t_env *e);
int					debug(t_env *e);

int					quit(void);

double				magnitude2(t_vec v);
t_vec				normalize(t_vec v);
t_vec				opposite(t_vec v);
t_vec				add(t_vec u, t_vec v);
t_vec				sub(t_vec u, t_vec v);

t_vec				crossproduct(t_vec u, t_vec v);
double				dotproduct(t_vec u, t_vec v);
t_vec				scale(double k, t_vec u);
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

t_color				color_calc(int x, int y, t_env *e);
t_vec				set_ray_dir(int x, int y, t_env *e);
t_color				get_light_value(t_work w, t_vec newstart, t_mat currmat,
					t_env *e);

void				color_lambert(t_color *c, double l, t_light currl,
					t_mat currm);
double				lambert(t_ray lightray, t_vec n);
void				color_blinnphuong(t_color *c, double b, t_light currl);
double				blinnphuong(t_ray lightray, t_ray *r, t_vec n,
					t_mat currm);
int					in_shadow(t_ray lightray, t_env *e, double t);

int					find_closest_item(t_ray r, t_env *e, t_vec *newstart);
int					find_post_nega(t_ray r, t_env *e, t_vec *newstart, int *curr);
t_vec				find_newstart(t_env *e, t_ray r);
t_mat				find_material(int curr, t_vec newstart, t_env *e);

t_vec				find_normal_vec_if_not_plane(int curr, t_vec newstart,
					t_env *e);
t_vec				find_cone_normal(t_vec newstart, t_item cone);
t_vec				find_cylinder_normal(t_vec newstart, t_item cyl);
t_vec				find_h(t_vec cd, t_vec cc, t_vec n);
t_vec				find_normal_vec(t_ray r, int curr, t_env *e);

int					read_file1(char *av, t_env *e);
int					read_file2(char *av, t_env *e);
void				count_param_control(char *line, int nbs[6]);
void				count_param(int nbs[6], char **s, int l);
void				build_struct(t_env *e, int nbs[6]);

void				parsing_cam(char **s, t_env *e);
void				fill_struct(t_env *e, char *line, int index[6]);
int					table_len(char **s);

void				parsing_light(char **s, t_env *e, int *k);
void				parsing_item(char **s, t_env *e, int *k);

t_vec				rotate_x(t_vec u, double angle);
t_vec				rotate_y(t_vec u, double angle);
t_vec				rotate_z(t_vec u, double angle);
t_vec				rotate(t_vec u, double anglex, double angley,
					double anglez);
t_vec				rotate_axis(t_vec u, t_vec r, double angle);

t_color				newcolor(double r, double g, double b);
t_item				newsph(t_vec center, double radius, int mat, int isNega);
t_item				newplane(t_vec dir, double d, int mat);
t_item				newcyl(t_vec dir, t_vec center, double radius, int mat, int isNega);
t_item				newdisk(t_vec dir, t_vec center, double radius, int mat);
t_item				newcone(t_vec dir, t_vec center, double angle, int mat, int isNega);
t_item				newfcyl(t_vec dir, t_vec center, double radius, int mat, double height,
					int isNega);
t_item				newfcone(t_vec dir, t_vec center, double radius, int mat, double height,
					int isNega);
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

void				escape(t_env *e);
int					keypress(int keycode, t_env *e);
int					keyrelease(int keycode, t_env *e);
void				key_hook(t_env *e);

void				move_cam(t_env *e);
void				create_axis(t_env *e);
void				show_mouse(t_env *e);
int					mousemove(int x, int y, t_env *e);

void				refr_enter_or_exit(t_work *w, int id, int k, t_env *e);
int					position_in_tab(int *tab, int id, int size);
int					add_to_tab(int *tab, int id, int size);
int					remove_from_tab(int *tab, int id, int size);
double				find_max_ior(int *tab, int size, t_env *e);

void				open_texture(t_env *e, t_img *tex, char *name);
void				load_textures(t_env *e);

#endif

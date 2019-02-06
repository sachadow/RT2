/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/01/31 15:34:49 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <string.h>
#include <errno.h>

/*
**	DRAW function:
**	For Multithreading
*/

static void	*draw(void *arg)
{
	t_sgmt			thread;
	t_pix			p;
	t_th			*th;

	th = (t_th *)arg;
	thread.start = 0;
	thread.end = (th->nb + 1) * IMG_W / NB_THR;
	thread.start = th->nb * IMG_W / NB_THR;
	p.y = IMG_H;
	while (--p.y > -1)
	{
		p.x = thread.start - 1;
		while (++p.x < thread.end)
		{
			if (th->env->antialiasing == 0)
				aliasing(10, p, th->env);
			else if (th->env->antialiasing == 1)
				aliasing(1, p, th->env);
			else if (th->env->antialiasing == 2)
				supersampling(2, p, th->env);
		}
	}
	pthread_exit(NULL);
}

/*
**	CREATE_THREADS function:
**	Creates threads in env
*/

static void	create_threads(t_env *e)
{
	int				i;
	int				rc;
	t_th			th[NB_THR];

	new_image(CENTER, IMG_W, IMG_H, e);
	i = -1;
	while (++i < NB_THR)
	{
		th[i].env = e;
		th[i].nb = i;
		if ((rc = pthread_create(&e->thr[i], NULL, draw, &th[i])))
			ft_putendl_fd(strerror(errno), 2);
	}
	i = -1;
	while (++i < NB_THR)
		if (pthread_join(e->thr[i], NULL))
			ft_putendl_fd(strerror(errno), 2);
}

/*
**	RELOAD function:
**	Sets image in the window
*/

int			reload(t_env *e)
{
	if (!e->loading)
		load(e);
	else if (e->loading == 1)
	{
		create_threads(e);
		if (e->cartoon == 1)
			add_cartoon_effect(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img[CENTER], 0, 0);
		mlx_destroy_image(e->mlx, e->img[CENTER]);
		e->loading = 2;
	}
	key_hook(e);
	hud(e);
	return (0);
}

int			debug(t_env *e)
{
	t_pix			p;

	key_hook(e);
	if (!(e->img[CENTER] = mlx_new_image(e->mlx, IMG_W, IMG_H))
			|| !(e->pixel_img[CENTER] =
				(unsigned char*)mlx_get_data_addr(e->img[CENTER], &e->bpp[CENTER],
					&e->s_line[CENTER], &e->ed[CENTER])))
		ft_printerror("Error mlx");
	p.y = IMG_H;
	while (--p.y > -1)
	{
		p.x = -1;
		while (++p.x < IMG_W)
		{
			e->debug = (p.x == 487 && p.y == 237) ? 1 : 0;
			if (((t_env*)e)->antialiasing == 0)
				aliasing(10, p, (t_env*)e);
			else if (((t_env*)e)->antialiasing == 1)
				aliasing(1, p, (t_env*)e);
			else if (((t_env*)e)->antialiasing == 2)
				supersampling(2, p, (t_env*)e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img[CENTER], 0, 0);
	mlx_destroy_image(e->mlx, e->img[CENTER]);
	return (0);
}

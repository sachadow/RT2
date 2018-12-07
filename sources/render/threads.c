/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/07 15:18:08 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <string.h>
#include <errno.h>

/*
**	DRAW function:
**	For Multithreading
*/

static void	*draw(void *e)
{
	t_sgmt			thread;
	t_pix			p;
	pthread_t		s;

	thread.start = 0;
	s = pthread_self();
	while (s != ((t_env*)e)->thr[thread.start])
		thread.start++;
	thread.end = (thread.start + 1) * IMG_W / NB_THR;
	thread.start = thread.start * IMG_W / NB_THR;
	p.y = IMG_H;
	while (--p.y > -1)
	{
		p.x = thread.start - 1;
		while (++p.x < thread.end)
		{
			if (((t_env*)e)->antialiasing == 0)
				aliasing(10, p, (t_env*)e);
			else if (((t_env*)e)->antialiasing == 1)
				aliasing(1, p, (t_env*)e);
			else if (((t_env*)e)->antialiasing == 2)
				supersampling(2, p, (t_env*)e);
		}
	}
	pthread_exit(NULL);
}

static int	bypass(unsigned char *s, int len)
{
	static unsigned char *tmp;

	if (!s || !len || !tmp)
	{
		tmp = (unsigned char *)ft_memalloc(sizeof(s) * len);
		tmp = (unsigned char *)ft_memcpy(tmp, s, sizeof(s) * len);
		return (0);
	}
	else if (ft_memcmp(tmp, s, sizeof(s) * len))
	{
		free(tmp);
		tmp = (unsigned char *)ft_memalloc(sizeof(s) * len);
		tmp = (unsigned char *)ft_memcpy(tmp, s, sizeof(s) * len);
		return (0);
	}
	else
		return (1);
}

static int	veccmp(t_vec veca, t_vec vecb)
{
	if (veca.x != vecb.x || veca.y != vecb.y || veca.z != vecb.z)
		return (0);
	return (1);
}

/*
**	RELOAD function:
**	Sets image in the window
*/

int			reload(t_env *e)
{
	int				i;
	int				rc;
	static t_vec	tmp;

	//key_hook(e);
/*	if (!(e->img = mlx_new_image(e->mlx, WIN_W, WIN_H))
		|| !(e->pixel_img = (unsigned char*)mlx_get_data_addr(e->img, &e->bpp,
			&e->s_line, &e->ed)))
		ft_printerror("Error mlx");*/
	if (!(bypass(e->pixel_img[CENTER], e->s_line[CENTER]))
			|| !veccmp(tmp, e->cam->pos))
	{
		load(e);
		new_image(CENTER, IMG_W, IMG_H, e);
		i = -1;
		while (++i < NB_THR)
			if ((rc = pthread_create(&e->thr[i], NULL, draw, e)))
				ft_putendl_fd(strerror(errno), 2);
		i = -1;
		while (++i < NB_THR)
			if (pthread_join(e->thr[i], NULL))
				ft_putendl_fd(strerror(errno), 2);
		e->loading = 1;
		mlx_put_image_to_window(e->mlx, e->win, e->img[CENTER], 0, 0);
		mlx_destroy_image(e->mlx, e->img[CENTER]);
		tmp = newvec(e->cam->pos.x, e->cam->pos.y, e->cam->pos.z);
	}
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
			e->debug = (p.x == 400 && p.y == 300) ? 1 : 0;
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

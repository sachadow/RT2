/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:07:15 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/13 15:49:42 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "parser.h"

/*
**	QUIT function:
**	Quits when clicking on the red cross
*/

int			quit(void)
{
	exit(1);
	return (0);
}

/*
**	FILENAME_CONTROL function:
**	Controls if the filename ends with ".rt"
*/

static void	filename_control(char *av)
{
	if (ft_strcmp(av + ft_strlen(av) - 4, ".xml"))
		ft_printerror("Please use valid file");
}

/*
**	INIT function:
**	Feeds some env variables
*/

static void	init(t_env *e)
{
	e->hit[SPHERE] = &hitsphere;
	e->hit[PLANE] = &hitplane;
	e->hit[I_CYL] = &hitcylinder;
	e->hit[I_CONE] = &hitcone;
	e->hit[DISK] = &hitdisk;
	e->hit[F_CYL] = &hitfcylinder;
	e->hit[F_CONE] = &hitfcone;
	e->hit[BOX] = &hitbox;
	e->backgroundcolor = newcolor(0, 0, 0);
	e->lvl = 4;
	create_axis(e);
	load_textures(e);
}

/*
**	MAIN function:
*/

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		ft_printerror("Only 1 argument");
	filename_control(av[1]);
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		ft_printerror("Error malloc");
	parser_all(av[1], e);
	if (!(e->mlx = mlx_init()))
		ft_printerror("Error mlx init");
	ft_memset(e->key, 0, sizeof(int) * 300);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "RT");
	mlx_centertop_window(e->win);
	init(e);
	//mlx_expose_hook(e->win, debug, e);
	mlx_loop_hook(e->mlx, reload, e);
	mlx_hook(e->win, KPRESS, KPRESSMASK, keypress, e);
	mlx_hook(e->win, KRELEASE, KRELEASEMASK, keyrelease, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, mousemove, e);
	mlx_hook(e->win, DESTROY, SNOTIFYMASK, quit, e);
	mlx_loop(e->mlx);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:07:51 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/09 10:59:04 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_camera2(t_element elem, t_env *e, int i)
{
	if (ft_strcmp(elem.attribut[i].name, "pos") == 0)
	{
		e->cam->pos = ft_getpos(elem.attribut[i].content);
		return (1);
	}
	else if (ft_strcmp(elem.attribut[i].name, "dir") == 0)
	{
		e->cam->dir = ft_getpos(elem.attribut[i].content);
		if (e->cam->dir.x == 0 && e->cam->dir.y == 0 && e->cam->dir.z == 0)
			std_err(0);
		return (2);
	}
	else
		std_err(0);
	return (0);
}

int		get_camera(t_element elem, t_env *e)
{
	int i;
	int j;
	int f;

	i = 0;
	j = 0;
	f = 0;
	if (!(e->cam = (t_cam*)malloc(sizeof(t_cam) * 1)))
		std_err(0);
	if (elem.nbr_element != 0 || elem.nbr_attr != 2)
		std_err(0);
	while (i < 2)
	{
		if (get_camera2(elem, e, i) == 1)
			j = 1;
		else
			f = 1;
		i++;
	}
	if (j != 1 || f != 1)
		std_err(0);
	return (0);
}

t_env	*recup_camera(t_env *e, t_element elem)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "camera") == 0)
		{
			if (j == 1)
				std_err(0);
			get_camera(elem.elem[i], e);
			j++;
		}
		i++;
	}
	if (j == 0)
		std_err(0);
	return (e);
}

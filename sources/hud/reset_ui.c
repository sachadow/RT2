/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ui1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:55:02 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/20 20:20:52 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

void		reset_ui(t_env *e)
{
	e->apply = 0;
	e->itf.nb_texture = 0;
	ft_memset(&e->itf.mat, 0, sizeof(t_mat) * 1);
	ft_memset(&e->itf.item, 0, sizeof(t_item) * 1);
}

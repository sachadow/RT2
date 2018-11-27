/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:07:06 by qsebasti          #+#    #+#             */
/*   Updated: 2018/11/16 19:59:08 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	new_image(int num, int width, int height, t_env *e)
{
	if (!(e->img[num] = mlx_new_image(e->mlx, width, height))
		|| !(e->pixel_img[num] = (unsigned char*)mlx_get_data_addr(e->img[num],
		&(e->bpp[num]), &(e->s_line[num]), &(e->ed[num]))))
		ft_printerror("Error mlx");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:12:07 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/13 15:19:48 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	open_texture(t_env *e, t_img *tex, char *name)
{
	if (!(tex->img = mlx_xpm_file_to_image(e->mlx, name, &tex->w, &tex->h)))
		ft_printerror("Error mlx");
	if (!(tex->pixel_img = mlx_get_data_addr(tex->img, &tex->bpp, &tex->s_line,
					&tex->ed)))
		ft_printerror("Error mlx");
}

void	load_textures(t_env *e)
{
	open_texture(e, &e->tex[0], "textures/redbrick.xpm");
}

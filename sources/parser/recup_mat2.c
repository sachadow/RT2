/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_mat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:34:46 by asarasy           #+#    #+#             */
/*   Updated: 2019/01/10 15:18:53 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

int			recup_checker_mat(t_mat *mat, t_element elem, int i, char *name)
{
	int nb;

	nb = 0;
	if (elem.nbr_attr < 10)
		std_err(0);
	recup_value_mat(mat, elem, i);
	recup_value_checker(mat, elem, i);
	if (ft_strcmp(name, "checker") == 0)
	{
		mat[i].type = 2;
		recup_value_text(mat, elem, i);
		checker_tex_build(&mat[i].tex, mat[i].diffuse, \
				mat[i].diffuse2);
	}
	else
	{
		mat[i].type = 5;
		recup_value_text(mat, elem, i);
		waves_tex_build(&mat[i].tex, mat[i].diffuse);
	}
	nb = get_bump(mat, elem, i);
	if (elem.nbr_attr - nb != 10)
		std_err(0);
	return (0);
}

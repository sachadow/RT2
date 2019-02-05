/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui3_writting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:13:48 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 20:07:25 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	N_PARAM function:
**	Proper write of the n parameter value
*/

static char	*n_param(double n)
{
	char	*tmp;
	char	*tmp2;
	char	tmp3[2];

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
			return (ft_itoa((int)n));
		tmp = ft_strjoin(ft_itoa((int)n), ".");
		tmp3[0] = (int)(n * 10) % 10 + '0';
		tmp3[1] = '\0';
		tmp2 = ft_strjoin(tmp, tmp3);
		free(tmp);
		return (tmp2);
	}
}

/*
**	SCALE_PARAM function:
**	Simplier display for the scale parameter value
*/

static char	*scale_param(double scale)
{
	if (scale == 10)
		return (ft_itoa(1));
	else if (scale == 1)
		return (ft_itoa(0));
	else if (scale == 0.1)
		return (ft_itoa(-1));
	else if (scale == 0.01)
		return (ft_itoa(-2));
	else
		return (ft_itoa(-3));
}

/*
**	WRITE_PARAM_VAL function:
**	Write the value for the selected parameter
*/

static void	write_param_val(t_env *e)
{
	char	*s;

	s = NULL;
	if (e->itf.mouse.button != -1)
	{
		if (e->itf.mouse.button != N && e->itf.mouse.button != SCALE)
		{
			s = ft_itoa((int)(e->itf.param[e->itf.mouse.button]));
			mlx_string_put(e->mlx, e->win, 2 * WIN_W / 5,
					IMG_H + 3 * BOTTOM_SPC / 8, BLACK, s);
			free(s);
		}
		else
		{
			if (e->itf.mouse.button == N)
				s = n_param(e->itf.param[N]);
			else
				s = scale_param(e->itf.param[SCALE]);
			mlx_string_put(e->mlx, e->win, 2 * WIN_W / 5,
					IMG_H + 3 * BOTTOM_SPC / 8, BLACK, s);
			free(s);
		}
	}
}

/*
**	FILL_STR function:
**	Fill the table with parameters name for display
*/

static void	fill_str(char **s)
{
	s[0] = "Reflection";
	s[1] = "Transparency";
	s[2] = "Spec. value";
	s[3] = "Spec. power";
	s[4] = "Refractive index";
	s[5] = "Bump";
	s[6] = "Scale";
	s[7] = NULL;
}

/*
**	UI3_WRITTING function:
**	Put on the image all the writtings for tab 3
*/

void		ui3_writting(t_env *e)
{
	char	*s[8];
	int		i;

	if (e->itf.pick.button != -1 && e->itf.mat.type != TEXTURE)
	{
		fill_str(s);
		i = -1;
		while (++i < 6)
			mlx_string_put(e->mlx, e->win, 30, IMG_H + 5 + i * 25, BLACK, s[i]);
		if (e->itf.mat.type == MARBLE || e->itf.mat.type == WOOD
				|| e->itf.mat.type == PERTURB)
			mlx_string_put(e->mlx, e->win, 30, IMG_H + 5 + i * 25, BLACK, s[i]);
		write_param_val(e);
	}
	mlx_string_put(e->mlx, e->win, IMG_W + 15, M_IMG_H - 30, BLACK,
			"Reflection number");
	s[0] = ft_itoa(e->lvl);
	mlx_string_put(e->mlx, e->win, IMG_W + RIGHT_SPC / 2 - 5, M_IMG_H + 10,
			BLACK, s[0]);
	free(s[0]);
	mlx_string_put(e->mlx, e->win, IMG_W + 30, M_IMG_H + 50, BLACK,
			"Reset spectrum");
}
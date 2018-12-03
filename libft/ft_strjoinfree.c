/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:58:05 by sderet            #+#    #+#             */
/*   Updated: 2018/06/28 16:58:08 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2, int n)
{
	char	*dst;

	dst = ft_strjoin(s1, s2);
	if (n == 1 || n == 3)
		free(s1);
	if (n == 2 || n == 3)
		free(s2);
	return (dst);
}

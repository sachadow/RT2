/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/13 18:23:29 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	FIND_CLOSEST_ITEM function:
**	Finds the closest item hit by the ray
*/

int			find_closest_item(t_ray r, t_env *e, t_vec *newstart)
{
	double	t;
	int		curr;

	e->ncurr = -1;
	curr = get_closest_item(r, e);
	if (curr < 0)
		return (curr);
	t = -1;
	e->hit[e->item[curr].item_type](r, e->item[curr], &t);
	if (curr > -1 && e->item[curr].isnega == 0)
		*newstart = add(scale(t, r.dir), r.start);
	else if (e->item[curr].isnega == 1)
		curr = find_post_nega(r, e, newstart);
	return (curr);
}

int			find_post_nega(t_ray r, t_env *e, t_vec *newstart)
{
	int		item_count;
	int		*items_id;
	int		*hit_items;
	int		last_hit;
	double	t;

	e->ncurr = -1;
	e->curr = -1;
	item_count = count_items(r, e);
	hit_items = (int*)malloc(sizeof(int) * item_count);
	items_id = (int*)malloc(sizeof(int) * item_count);
	init_int_tab(hit_items, item_count, 0);
	init_int_tab(items_id, item_count, -1);
	last_hit = get_closest_item(r, e);
	hit_id(items_id, last_hit, hit_items, e);
	t = -1;
	e->hit[e->item[last_hit].item_type](r, e->item[last_hit], &t);
	r.start = add(scale(t, r.dir), r.start);
	while (got_out(item_count, hit_items, items_id, e) == 0)
	{
		last_hit = get_closest_item(r, e);
		if (last_hit == -1)
			return (last_hit);
		hit_id(items_id, last_hit, hit_items, e);
		t = -1;
		e->hit[e->item[last_hit].item_type](r, e->item[last_hit], &t);
		r.start = add(scale(t, r.dir), r.start);
		if (e->item[last_hit].isnega == 0 &&
				get_hits(hit_items, items_id, last_hit) % 2 != 0)
			e->curr = last_hit;
	}
	if (is_empty(hit_items, item_count, items_id, e) == 0)
	{
		free(hit_items);
		free(items_id);
		return (find_closest_item(r, e, newstart));
	}
	*newstart = r.start;
	if (e->item[last_hit].isnega == 1)
		e->ncurr = last_hit;
	free(hit_items);
	free(items_id);
	return (e->curr);
}

int			is_empty(int *hit, int count, int *id, t_env *e)
{
	int a;
	int	b;

	a = 0;
	b = 0;
	while (a < count)
	{
		if (hit[a] % 2 != 0 && e->item[id[a]].isnega == 0)
			b++;
		a++;
	}
	return (b);
}

int			get_hits(int* hit, int *id, int last)
{
	int a;

	a = 0;
	while (id[a] != last)
		a++;
	return (hit[a]);
}

void		hit_id(int* id, int nb, int* hit, t_env *e)
{
	int a;

	if (e->item[nb].item_type == DISK ||
			e->item[nb].item_type == PLANE)
		return ;
	a = 0;
	while (id[a] != -1 && id[a] != nb)
		a++;
	id[a] = nb;
	hit[a]++;
}

void		init_int_tab(int* tab, int size, int value)
{
	int a;

	a = 0;
	while (a < size)
	{
		tab[a] = value;
		a++;
	}
}

int			got_out(int count, int *nb_hit, int *id, t_env *e)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (a < count)
	{
		if (e->item[id[a]].isnega == 1 && nb_hit[a] % 2 == 0)
			b++;
		a++;
	}
	return (b);
}

int			count_items(t_ray r, t_env *e)
{
	double	t;
	int		i;
	int		count;

	if (!magnitude2(r.dir))
		return (-1);
	t = -1;
	i = -1;
	count = 0;
	while (++i < e->nbs[ITEM])
		if (e->hit[e->item[i].item_type](r, e->item[i], &t) != -1)
			count++;
	return (count);
}

int			get_closest_item(t_ray r, t_env *e)
{
	double	t;
	double	before;
	int		i;
	int		curr;

	if (!magnitude2(r.dir))
		return (-1);
	t = -1;
	before = -1;
	curr = -1;
	i = -1;
	while (++i < e->nbs[ITEM])
	{
		if (e->hit[e->item[i].item_type](r, e->item[i], &t)
			&& (before == -1 || (t < before && t > 0.001f)))
		{
			before = t;
			curr = i;
		}
	}
	return (curr);
}

/*
**	FIND_NEWSTART function:
**	Finds the hit point from a ray r
*/

t_vec		find_newstart(t_env *e, t_ray r)
{
	t_vec	newstart;
	int		curr;

	curr = find_closest_item(r, e, &newstart);
	return (newstart);
}

/*
**	FIND_MATERIAL function:
**	Finds material of the hit item thanks to the index stored in the structure
*/

t_mat		find_material(int id, t_env *e)
{
	t_mat	m;

	m.diffuse = newcolor(0, 0, 0);
	m.reflection = 0;
	m.specvalue = 0;
	m.specpower = 0;
	if (e->item[id].mat > e->nbs[MAT])
		return (m);
	else
		m = e->mat[e->item[id].mat];
	return (m);
}

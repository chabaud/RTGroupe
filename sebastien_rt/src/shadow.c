/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:16:39 by abara             #+#    #+#             */
/*   Updated: 2017/02/15 12:55:20 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RT.h"

double	shadow(t_light *l, t_ray ray, t_object *obj, int *nb)
{
	double	ret;
	int		i;
	int		n;
	t_ray	r;
	t_v		v;
	double	d;

	i = 0;
	n = 0;
	while (i < nb[1])
	{
		r.id = -1;
		r.t = -1;
		r.a = l[i].pos;
		r.dir = get_v(r.a, add_v(ray.a, mult_v(ray.dir, ray.t)));
		r.dir = normalize(r.dir);
		intersection(&r, obj, nb[0]);
		r.current = add_v(r.a, mult_v(r.dir, r.t));
		v = normalize(get_v(l[i].pos, r.current));
		d = dot(get_v(ray.a, r.current), v);
		if (r.id == ray.id && d >= 0)
			n++;
		else if (r.id == ray.id && obj[ray.id].type == 3)
			n++;
		i++;
	}
	ret = (double)(1 / (double)nb[1]) * n;
	if (nb[1] == 0)
		ret = 0;
	return (ret);
}

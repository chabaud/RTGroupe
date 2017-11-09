/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:37:38 by abara             #+#    #+#             */
/*   Updated: 2017/02/02 15:50:21 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RT.h"

t_ray	reflection(t_v dir, t_ray ray, t_object obj)
{
	t_ray	ref;
	t_v		n;
	t_v		tmp;

	ref.a = ray.current;
	n = obj.c;
	tmp = get_v(ray.a, ray.current);
	ref.dir = add_v(tmp, mult_v(mult_v(n, 2), dot(invert_v(n), tmp)));
	ref.dir = normalize(ref.dir);
	ref.id = -1;
	ref.t = -1;
	return (ref);
}

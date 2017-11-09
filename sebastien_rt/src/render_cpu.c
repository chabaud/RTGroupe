/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:57:30 by abara             #+#    #+#             */
/*   Updated: 2017/02/20 15:01:36 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RT.h"

void		set_vrep(t_v d, t_v v[3])
{
	v[2] = normalize(d);
	if (fabs(v[2].y) == 1)
	{
		v[0].x = 1;
		v[1].z = -v[2].y;
		return ;
	}
	v[0].x = v[2].z;
	v[0].z = -v[2].x;
	v[0] = normalize(v[0]);
	v[1].y = sqrt(v[2].x * v[2].x + v[2].z * v[2].z);
	v[1].x = -v[2].x / (fabs(v[2].x) + fabs(v[2].z)) * v[2].y;
	v[1].z = -v[2].z / (fabs(v[2].x) + fabs(v[2].z)) * v[2].y;
	v[1] = normalize(v[1]);
}

static t_v	render_loop(t_winfo *w)
{
	double	ret;
	int		*nb;

	nb = (int*)malloc(sizeof(int) * 2);
	nb[0] = w->file.nbobj;
	nb[1] = w->file.nblight;
	intersection(&w->ray, w->obj, w->file.nbobj);
	if (w->ray.id != -1)
	{
		ret = shadow(w->light, w->ray, w->obj, nb);
		check_light(w->light, &w->ray, &w->obj[w->ray.id], w->file.nblight);
		w->ray.color = limit_v(mult_v(w->ray.color, ret), 0, 255);
	}
	else
	{
		ft_memdel((void**)&nb);
		return (set_v(0, 0, 0));
	}
//	w->ray = reflection(w->ray.dir, w->ray, w->obj[w->ray.id]);
	ft_memdel((void**)&nb);
	return (w->ray.color);
}

void		render_cpu(t_winfo *w)
{
	int		x;
	int		y;
	t_v		v[3];

	printf("AAAAAAA\n");
	set_vrep(w->cam.dir, v);
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			w->ray.a = w->cam.pos;
			w->ray.dir = normalize(add_v(add_v(mult_v(v[0], x - W / 2), mult_v(v[1], H / 
			2 - y)), mult_v(v[2], W / 2)));
			w->ray.id = -1;
			w->ray.t = -1;
			if (w->opt.sepia == 0)
				put_pixel(w, x, y, render_loop(w));
			else
				put_pixel_sepia(w, x, y, render_loop(w));
			++x;
		}
		++y;
	}
	printf("BBBBBBB\n");
	if (w->opt.fxaa)
		ft_fxaa(w->img, W, H, w->opt.fxaa);
	printf("CCCCCCC\n");
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	printf("DDDDDDD\n");
}

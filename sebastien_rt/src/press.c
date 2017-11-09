/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:10:02 by abara             #+#    #+#             */
/*   Updated: 2017/02/20 16:30:29 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RT.h"

int		mouse_button(int key, int x, int y, void *param)
{
	t_winfo	*w;
	t_v		v[3];

	w = param;
	key = 0;
	if ((x >= 0 && x < W) && (y >= 0 && y < H))
	{
		set_vrep(w->cam.dir, v);
		w->ray.a = w->cam.pos;
		w->ray.dir = normalize(add_v(add_v(mult_v(v[0], x - W / 2), mult_v(v[1], H /
		2 - y)), mult_v(v[2], W / 2)));
		w->ray.id = -1;
		w->ray.t = -1;
		intersection(&w->ray, w->obj, w->file.nbobj);
		w->opt.oselect = w->ray.id;
		printf("Selected object's id: %d\n", w->opt.oselect);
		printf("CLICK! x: %d || y: %d\n", x, y);
	}
	return (0);
}

int		key_press(int key, void *param)
{
	t_winfo	*w;

	w = param;
	if (key == 53) //53
		exit(1);
	else if (w->opt.console == 0)
		press_noconsole(w, key);
	else if (w->opt.console == 1)
		press_console(w, key);
	printf("key: %d\n", key);
	return (0);
}

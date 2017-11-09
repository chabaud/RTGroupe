/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:56:02 by abara             #+#    #+#             */
/*   Updated: 2017/01/30 12:04:08 by cguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RT.h"

static void	get_arg(t_cam *cam, char **file, int x, int y)
{
	if (ft_strncmp("/pos:", &file[y][x], 5) == 0)
		get_split(&cam->pos, file, x + 5, y);
	else if (ft_strncmp("/dir:", &file[y][x], 5) == 0)
		get_split(&cam->dir, file, x + 5, y);
}

static int	get_camera_arg(t_cam *cam, char **file, int x, int y)
{
	y++;
	while (file[y] != NULL)
	{
		x = 0;
		while (file[y][x] != '\0' && file[y][x] != '.')
		{
			if (file[y][x] == '/')
				get_arg(cam, file, x, y);
			x++;
		}
		if (file[y][x] == '.')
			return (0);
		y++;
	}
	return (0);
}

int			get_camera(t_winfo *w)
{
	int	x;
	int	y;

	y = 0;
	while (y < w->file.size)
	{
		x = 0;
		while (w->file.file[y][x] != '\0')
		{
			if (ft_strcmp(".camera:", &w->file.file[y][x]) == 0)
			{
				get_camera_arg(&w->cam, w->file.file, x, y);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:37:01 by mmouhssi          #+#    #+#             */
/*   Updated: 2017/02/15 18:03:22 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RT.h"

void ft_modify(t_winfo *w, char *cmd)
{
    if (ft_strncmp("pos ", cmd, 4) == 0)
        get_nbr(&w->obj[w->opt.oselect].a, &cmd[4]);
    else if (ft_strncmp("dir ", cmd, 4) == 0)
        get_nbr(&w->obj[w->opt.oselect].b, &cmd[4]);
    else if (ft_strncmp("normal ", cmd, 7) == 0)
        get_nbr(&w->obj[w->opt.oselect].c, &cmd[7]);
	else if (ft_strncmp("r ", cmd, 2) == 0)
		w->obj[w->opt.oselect].r = ft_atod(&cmd[2]);
    else if (ft_strncmp("min ", cmd, 4) == 0)
    	w->obj[w->opt.oselect].min = ft_atod(&cmd[4]);
    else if (ft_strncmp("max ", cmd, 4) == 0)
        w->obj[w->opt.oselect].max = ft_atod(&cmd[4]);
    else
        exec3(w, cmd);
}

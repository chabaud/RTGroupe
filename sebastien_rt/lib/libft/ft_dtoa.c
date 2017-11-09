/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:34:08 by abara             #+#    #+#             */
/*   Updated: 2017/01/11 13:35:23 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa_get_dst(char *str, int power, int nbline)
{
	char	*dst;
	int		index;
	int		i;

	i = 0;
	index = 0;
	if (power == 0)
		dst = ft_strnew(nbline);
	else
		dst = ft_strnew(nbline + 1);
	while (index != nbline + 1)
	{
		if (index == (nbline - power))
		{
			dst[index] = '.';
			i--;
		}
		else
			dst[index] = str[i];
		i++;
		index++;
	}
	free(str);
	if (power == 0)
		dst[index - 1] = '\0';
	return (dst);
}

char	*ft_dtoa(double a)
{
	long long	nb;
	char		*str;
	int			power;

	nb = a;
	power = 0;
	while (a != (double)nb)
	{
		power += 1;
		a *= 10;
		nb = a;
	}
	str = ft_itoa(nb);
	return (ft_dtoa_get_dst(str, power, ft_strlen(str)));
}

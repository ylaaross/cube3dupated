/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:51:46 by asaber            #+#    #+#             */
/*   Updated: 2023/12/21 00:26:03 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_x_y_to_check(int y, int x, char **map, t_info *g_info)
{
	unsigned int	tmpx;
	unsigned int	tmpy;

	if (x < 0 || y < 0 || x > (int)ft_strlen(map[y])
		|| y > (int)g_info->map_num_rows)
		return (0);
	tmpx = floor(x);
	tmpy = floor(y);
	if (map[tmpy][tmpx] && tmpy != 0 && tmpx != 0)
		return (1);
	return (0);
}

int	map_len_colom(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_maxlen(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	ft_free(t_info *g_info)
{
	int				i;

	i = 0;
	while (g_info->map[i])
	{
		free(g_info->map[i]);
		i++;
	}
	free(g_info->map);
}

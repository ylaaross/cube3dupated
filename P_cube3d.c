/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_cube3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:23:57 by ylaaross          #+#    #+#             */
/*   Updated: 2023/12/20 22:10:35 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "P_CUBE3D.h"

void	init_convert(int *size, t_file *o, int *i, int *j)
{
	*i = 0;
	*j = 0;
	*size = strlen_2d_st(o);
}

void	free_pars(t_file *f, t_all_infos *all)
{
	t_file	*tmp;
	int		i;

	i = 0;
	while (f)
	{
		free(f->line);
		tmp = f->next;
		free(f);
		f = tmp;
	}
	while (all->map[i])
	{
		free(all->map[i]);
		i++;
	}
	free(all->map);
	i = 0;
	while (all->element_part[i])
	{
		free(all->element_part[i]);
		i++;
	}
	free(all->element_part);
}

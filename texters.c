/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:41:16 by asaber            #+#    #+#             */
/*   Updated: 2023/12/20 22:46:50 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_color(mlx_texture_t	*texture, int pix)
{
	uint32_t	color;
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		alpha;

	red = texture->pixels[pix++];
	green = texture->pixels[pix++];
	blue = texture->pixels[pix++];
	alpha = texture->pixels[pix];
	color = ft_pixel(red, green, blue, alpha);
	return (color);
}

void	assigne_texture(t_info *g_info)
{
	if (g_info->vdist == g_info->f_dist)
	{
		if (g_info->left == 1)
			g_info->texture = g_info->w;
		else if (g_info->right == 1)
			g_info->texture = g_info->e;
	}
	else
	{
		if (g_info->up == 1)
			g_info->texture = g_info->n;
		else if (g_info->down == 1)
			g_info->texture = g_info->s;
	}
}

void	init_derection(t_info *g_info)
{
	g_info->up = 0;
	g_info->down = 0;
	g_info->left = 0;
	g_info->right = 0;
}

void	direction(double angle, t_info *g_info)
{
	init_derection(g_info);
	if (angle > 0 && angle < M_PI)
		g_info->down = 1;
	else
		g_info->up = 1;
	if (angle < M_PI * 0.5 || angle > 1.5 * M_PI)
		g_info->right = 1;
	else
		g_info->left = 1;
	assigne_texture(g_info);
}

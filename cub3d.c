/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:20:53 by asaber            #+#    #+#             */
/*   Updated: 2023/12/20 22:15:12 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_init(t_info *g_info)
{
	g_info->map_num_colom = get_maxlen(g_info->map);
	g_info->map_num_rows = map_len_colom(g_info->map);
	g_info->hight = g_info->map_num_rows * SQUIR_SIZE;
	g_info->wight = g_info->map_num_colom * SQUIR_SIZE;
	g_info->player.raduis = 3.0;
	g_info->player.walkdir = 0;
	g_info->player.turndir = 0;
	g_info->player.move_speed = 15.0;
	g_info->fov_angle = 60.0 * (M_PI / 180);
	g_info->player.turndir = 0;
	g_info->player.walkdir = 0;
	g_info->ray_x = 0;
	g_info->ray_y = 0;
	g_info->minimap = 0.2;
	find_player(g_info);
	if (g_info->hight > 1800 || g_info->wight > 3100)
	{
		printf("\nFor better experience we recommended you to use a small map\n");
		exit(1);
	}
}

int	mlx_checks(mlx_t **mlx, t_info *g_info)
{
	*mlx = mlx_init(g_info->wight, g_info->hight, "cub3d", true);
	if (!*mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	g_info->image = mlx_new_image(*mlx, g_info->wight, g_info->hight);
	if (!g_info->image)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(*mlx, g_info->image, 0, 0) == -1)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	parsing(int argc, char **argv, t_info *g_info)
{
	int			fd;
	t_file		*f;
	t_all_infos	all;

	init_vars(&f, &all);
	if (argc == 2)
	{
		if (file_check(argv[1]))
		{
			fd = file_d(argv[1]);
			if (fd > 0)
			{
				file_read(&f, fd);
				convert_check(f, &all);
				g_info->map = all.map_only;
				g_info->paths = all.map_struct;
				g_info->rgb = all.range;
				free_pars(f, &all);
			}
			else
				print_err();
		}
		else
			print_err();
	}
}

char	*path(t_info *g_info, char *part)
{
	t_map_struct	*map_structtmp;

	map_structtmp = g_info->paths;
	while (ft_strcmp(map_structtmp->element_type, part))
		map_structtmp = map_structtmp->next;
	return (map_structtmp->path);
}

int	main(int ac, char **av)
{
	mlx_t	*mlx;
	t_info	*g_info;

	if (ac == 2)
	{
		g_info = malloc(sizeof(t_info));
		if (!g_info)
			return (EXIT_FAILURE);
		parsing(ac, av, g_info);
		pre_init(g_info);
		g_info->n = mlx_load_png(path(g_info, "NO"));
		g_info->s = mlx_load_png(path(g_info, "SO"));
		g_info->w = mlx_load_png(path(g_info, "WE"));
		g_info->e = mlx_load_png(path(g_info, "EA"));
		if (!g_info->n || !g_info->s || !g_info->w || !g_info->e)
			return (EXIT_FAILURE);
		if (mlx_checks(&mlx, g_info) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		g_info->mlx = &mlx;
		mlx_loop_hook(mlx, draw_map, g_info);
		mlx_loop_hook(mlx, mlx_moves, g_info);
		mlx_loop(mlx);
		ft_free(g_info);
	}
}

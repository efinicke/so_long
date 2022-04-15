/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:17:27 by efinicke          #+#    #+#             */
/*   Updated: 2022/04/05 20:15:51 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_struct(t_datas *datas)
{
	datas->map.map = 0;
	datas->map.collectibles = 0;
	datas->map.moves = 0;
	datas->map.p_x = 0;
	datas->map.p_y = 0;
	datas->map.x_size = 0;
	datas->map.y_size = 0;
	datas->mlx = NULL;
	datas->win = NULL;
	datas->img.img = NULL;
	datas->img.addr = NULL;
}

void	init_img_window_and_sprites(t_datas *datas)
{
	datas->mlx = mlx_init();
	datas->win = mlx_new_window(datas->mlx,
			datas->map.x_size * PXL_NB,
			datas->map.y_size * PXL_NB, "so_long");
	datas->img.img = mlx_new_image(datas->mlx,
			datas->map.x_size * PXL_NB, datas->map.x_size * PXL_NB);
	datas->sprites.exi.img = mlx_xpm_file_to_image(datas->mlx,
			"sprites/E.xpm",
			&datas->sprites.exi.width, &datas->sprites.exi.height);
	datas->sprites.pos.img = mlx_xpm_file_to_image(datas->mlx,
			"sprites/P.xpm",
			&datas->sprites.pos.width, &datas->sprites.pos.height);
	datas->sprites.col.img = mlx_xpm_file_to_image(datas->mlx,
			"sprites/C.xpm",
			&datas->sprites.col.width, &datas->sprites.col.height);
	datas->sprites.wal.img = mlx_xpm_file_to_image(datas->mlx,
			"sprites/1.xpm",
			&datas->sprites.wal.width, &datas->sprites.wal.height);
	datas->sprites.spc.img = mlx_xpm_file_to_image(datas->mlx,
			"sprites/0.xpm",
			&datas->sprites.spc.width, &datas->sprites.spc.height);
}

int	key_hook(int key, t_datas *datas)
{
	events(datas->map.p_x, datas->map.p_y, datas, key);
	generate_window_map(datas);
	return (0);
}

int	main(int argc, char **argv)
{
	t_datas	datas;

	if (argc == 2)
	{
		init_struct(&datas);
		if (parse_map_file(argv[1], &datas))
		{
			init_img_window_and_sprites(&datas);
			generate_window_map(&datas);
			mlx_hook(datas.win, 2, 1L << 0, key_hook, &datas);
			mlx_hook(datas.win, 33, 131072, &close_window, &datas);
			mlx_loop(datas.mlx);
			//mlx_key_hook(datas.win, key_hook, &datas);
		}		
	}
	return (0);
}

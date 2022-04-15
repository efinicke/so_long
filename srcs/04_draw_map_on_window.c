/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_draw_map_on_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:17:55 by efinicke          #+#    #+#             */
/*   Updated: 2022/04/05 20:11:21 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_img_to_window(int x, int y, t_datas *datas)
{
	if (datas->map.map[y][x] == '1')
		mlx_put_image_to_window(datas->mlx, datas->win,
			datas->sprites.wal.img,
			(x * PXL_NB), (y * PXL_NB));
	if (datas->map.map[y][x] == '0')
		mlx_put_image_to_window(datas->mlx, datas->win,
			datas->sprites.spc.img,
			(x * PXL_NB), (y * PXL_NB));
	if (datas->map.map[y][x] == 'P')
	{
		mlx_put_image_to_window(datas->mlx, datas->win,
			datas->sprites.pos.img,
			(x * PXL_NB), (y * PXL_NB));
		datas->map.p_x = x;
		datas->map.p_y = y;
	}
	if (datas->map.map[y][x] == 'C')
		mlx_put_image_to_window(datas->mlx, datas->win,
			datas->sprites.col.img,
			(x * PXL_NB), (y * PXL_NB));
	if (datas->map.map[y][x] == 'E')
		mlx_put_image_to_window(datas->mlx, datas->win,
			datas->sprites.exi.img,
			(x * PXL_NB), (y * PXL_NB));
}

void	generate_window_map(t_datas *datas)
{
	int	x;
	int	y;

	y = 0;
	while ((y * PXL_NB) < (datas->map.y_size * PXL_NB) && datas->map.map[y])
	{
		x = 0;
		while ((x * PXL_NB) < (datas->map.x_size * PXL_NB)
			&& datas->map.map[y][x])
		{
			put_img_to_window(x, y, datas);
			x += 1;
		}
		y += 1;
	}
}

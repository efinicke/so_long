/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:18:07 by efinicke          #+#    #+#             */
/*   Updated: 2022/04/05 20:12:06 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* ft_split and free_map*/
void	free_map(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}

/*free images, window, mlx && display*/
int	close_window(t_datas *datas)
{
	mlx_destroy_image(datas->mlx, datas->sprites.exi.img);
	mlx_destroy_image(datas->mlx, datas->sprites.pos.img);
	mlx_destroy_image(datas->mlx, datas->sprites.col.img);
	mlx_destroy_image(datas->mlx, datas->sprites.wal.img);
	mlx_destroy_image(datas->mlx, datas->sprites.spc.img);
	mlx_destroy_image(datas->mlx, datas->img.img);
	mlx_destroy_window(datas->mlx, datas->win);
	mlx_destroy_display(datas->mlx);
	free(datas->mlx);
	free_map(datas->map.map);
	exit (0);
}

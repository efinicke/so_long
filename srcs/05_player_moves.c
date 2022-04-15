/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:18:03 by efinicke          #+#    #+#             */
/*   Updated: 2021/12/09 23:35:35 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	events(int x, int y, t_datas *datas, int key)
{
	if (key == ESC)
		close_window(datas);
	else if (key == RIGHT)
		move_player_x(x, y, x + 1, datas);
	else if (key == LEFT)
		move_player_x(x, y, x - 1, datas);
	else if (key == UP)
		move_player_y(x, y, y - 1, datas);
	else if (key == DOWN)
		move_player_y(x, y, y + 1, datas);
	if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		print_moves(datas->map.moves);
}

void	move_player_x(int x, int y, int mov, t_datas *datas)
{
	if (datas->map.map[y][mov] == '0' || datas->map.map[y][mov] == 'C')
	{
		if (datas->map.map[y][mov] == 'C')
			datas->map.collectibles -= 1;
		datas->map.map[y][x] = '0';
		datas->map.map[y][mov] = 'P';
		datas->map.moves++;
	}
	else if (datas->map.map[y][mov] == 'E' && datas->map.collectibles == 0)
	{
		datas->map.moves++;
		print_moves(datas->map.moves);
		close_window(datas);
	}
}

void	move_player_y(int x, int y, int mov, t_datas *datas)
{
	if (datas->map.map[mov][x] == '0' || datas->map.map[mov][x] == 'C')
	{
		if (datas->map.map[mov][x] == 'C')
			datas->map.collectibles -= 1;
		datas->map.map[y][x] = '0';
		datas->map.map[mov][x] = 'P';
		datas->map.moves++;
	}
	else if (datas->map.map[mov][x] == 'E' && datas->map.collectibles == 0)
	{
		datas->map.moves++;
		print_moves(datas->map.moves);
		close_window(datas);
	}
}

void	print_moves(int moves)
{
	printf("moves number : %d\n", moves);
}

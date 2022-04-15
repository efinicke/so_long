/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:17:45 by efinicke          #+#    #+#             */
/*   Updated: 2021/12/10 00:00:01 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_map_rectagular(char **map, t_datas *datas)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if (j != len)
			return (0);
		i++;
	}
	datas->map.y_size = i;
	datas->map.x_size = j;
	return (1);
}

int	is_good_wall(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(map[0]) - 1;
	while (map[++i])
	{
		if ((map[i][0] != '1') || (map[i][j] != '1'))
			return (0);
	}
	i -= 1;
	j = -1;
	while (map[0][++j] && map[i][j])
	{
		if (map[0][j] != '1' || map[i][j] != '1')
			return (0);
	}
	return (1);
}

static int	is_valid_c(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E');
}

int	is_valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_c(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_good_map(char **map, t_datas *datas)
{
	if (!is_map_rectagular(map, datas))
	{
		send_error("map detected as no rectangular");
		return (0);
	}
	if (!is_good_wall(map))
	{
		send_error("bad walls");
		return (0);
	}
	if (!is_valid_char(map))
	{
		send_error("invalid char detected on the map");
		return (0);
	}
	if (!is_good_char_nb(datas))
	{
		return (0);
	}
	return (1);
}

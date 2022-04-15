/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_map_parsing2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:17:50 by efinicke          #+#    #+#             */
/*   Updated: 2021/12/10 00:47:55 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	send_error(char *error_message)
{
	char	*error_form;

	error_form = "Error\n";
	write(2, &(*error_form), ft_strlen(error_form));
	write(2, &(*error_message), ft_strlen(error_message));
	write(2, "\n", 2);
}

static void	init_tab(void *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		((int *)tab)[i] = '\0';
		i++;
	}
}

static int	*fill_tab(int *tab, t_datas *datas)
{
	int	i;
	int	j;

	i = 0;
	while (datas->map.map && datas->map.map[i])
	{
		j = 0;
		while (datas->map.map[i][j])
		{
			if (datas->map.map[i][j] == '1')
				tab[0] += 1;
			if (datas->map.map[i][j] == '0')
				tab[1] += 1;
			if (datas->map.map[i][j] == 'P')
				tab[2] += 1;
			if (datas->map.map[i][j] == 'C')
				tab[3] += 1;
			if (datas->map.map[i][j] == 'E')
				tab[4] += 1;
			tab[5] = '\0';
			j++;
		}
		i++;
	}
	return (tab);
}

static void	check_char_nb_errors(int *tab)
{
	if (tab[0] == 0)
		send_error("no walls");
	if (tab[1] == 0)
		send_error("no spaces");
	if (tab[2] > 1)
		send_error("too many player position on the map");
	if (tab[2] == 0)
		send_error("no player position on the map");
	if (tab[3] == 0)
		send_error("no collectible detected on the map");
	if (tab[4] == 0)
		send_error("no exit detected on the map");
}

int	is_good_char_nb(t_datas *datas)
{
	int	*tab;

	tab = malloc(sizeof(tab) * 5 + 1);
	if (!tab)
		return (0);
	init_tab(tab, 6);
	tab = fill_tab(tab, datas);
	datas->map.collectibles = tab[3];
	check_char_nb_errors(tab);
	if (tab[0] > 0 && tab[1] > 0 && tab[2] == 1 && tab[3] > 0 && tab[4] > 0)
	{
		free(tab);
		return (1);
	}
	free(tab);
	return (0);
}

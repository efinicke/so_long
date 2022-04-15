/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map_extraction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:17:40 by efinicke          #+#    #+#             */
/*   Updated: 2021/12/09 22:02:14 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*parse and extract map*/
int	parse_map_file(char *file, t_datas *datas)
{
	if (is_ber_file(file))
	{
		datas->map.map = extract_map(file, datas);
		if (!datas->map.map)
		{
			send_error("non-existent map");
			return (0);
		}
		if (is_good_map(datas->map.map, datas))
			return (1);
		free_map(datas->map.map);
		return (0);
	}
	else
	{
		send_error("the file is not a .ber file");
		return (0);
	}
}

/*generate map*/
static void	if_file(char *file, t_datas *datas)
{
	if (!file)
		return ;
	if (file)
	{
		datas->map.map = ft_split(file, '\n');
		free(file);
	}
}

char	**extract_map(char *file_name, t_datas *datas)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*file;
	int			ret;
	int			fd;

	file = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret != 0)
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		file = ft_strjoin_free(file, buf);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if_file(file, datas);
	if (!datas->map.map)
		return (NULL);
	close(fd);
	return (datas->map.map);
}

/*map parsing*/
void	display_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map)
	{
		while (map[i])
		{
			printf("map line number %d : %c\n", i - 1, map[i][j]);
			i++;
		}
	}
}

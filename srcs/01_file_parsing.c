/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_file_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:17:33 by efinicke          #+#    #+#             */
/*   Updated: 2021/12/09 19:21:49 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*check if the given file as an argument is a ".ber" file*/
int	is_ber_file(char *filename)
{
	int	i;

	i = ft_strlen(filename) - 1;
	if (filename[i] == 'r'
		&& filename[i - 1] == 'e'
		&& filename[i - 2] == 'b'
		&& filename[i - 3] == '.')
		return (1);
	return (0);
}

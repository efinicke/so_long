/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinicke <efinicke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:19:15 by efinicke          #+#    #+#             */
/*   Updated: 2021/12/09 19:27:36 by efinicke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/*split */
static int	count_words(char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

/*strjoin_free*/
char	*ft_strjoin_free(char *bigstring, char *buf)
{
	char	*tab;
	int		len;
	int		j;
	int		i;

	i = 0;
	j = 0;
	len = ft_strlen(bigstring) + ft_strlen(buf);
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	while (bigstring && bigstring[i])
	{
		tab[i] = bigstring[i];
		i++;
	}
	while (buf && buf[j])
	{
		tab[i + j] = buf[j];
		j++;
	}
	if (bigstring)
		free(bigstring);
	tab[i + j] = '\0';
	return (tab);
}

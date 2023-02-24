/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/24 17:06:56 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (c && set && set[i])
	{
		if (set[i++] == c)
			return (true);
	}
	return (false);
}

int	ft_charcmp(unsigned char a, unsigned char b)
{
	if (a == b)
		return (true);
	return (false);
}

void	ft_replace_or_load(char **texture, char *temp)
{
	if (*texture)
		ft_free(*texture);
	*texture = ft_strdup(ft_trim_token(temp, ' '));
}

bool	ft_str_is_num(char *str)
{
	int	i;

	if (!str || !*str || ft_is_only(str, ' ', ft_strlen(str)))
		return (false);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || str[ft_strlen(str)] == '\n')
			return (false);
		i++;
	}
	return (true);
}

void	map_size(t_game *game)
{
	game->ct.map_size = 0;
	game->ct.i = -1;
	while (game->tmp[++game->ct.i])
	{
		game->ct.k = -1;
		while (game->tmp[game->ct.i][++game->ct.k])
			game->ct.map_size += 1;
	}
}

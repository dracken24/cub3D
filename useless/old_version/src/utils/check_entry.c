/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:49:33 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	check_entry(int entry, char **name, t_game *game)
{
	if (entry != 2)
	{
		perror("Error, Wrong arguments numbers\n");
		exit(0);
	}
	if (check_name(game, name[1]) == 0)
	{
		perror("Error, Invalid files <name>.cub\n");
		exit(0);
	}
	map_read(game, name[1]);
	map_size(game);
	save_map(game);
	check_board(game);
}

int	check_name(t_game *game, char *name)
{
	game->len.len = ft_strlen(name);
    if (name == 0)
        return (0);
    if (game->len.len < 5)
        return (0);
    if (ft_strncmp(name + game->len.len - 4, ".cub", game->len.len) != 0)
        return (0);
    return (1);
}

void	map_read(t_game *game, char *name)
{
	int	fd;

	game->tmp = ft_calloc(sizeof(char), 4096);
	if (!game->tmp)
	{
		free(game->tmp);
		perror("Error, wrong malloc <map_0>");
		exit(0);
	}
	fd = open(name, O_RDONLY);
	game->ct.i = -1;
	while (++game->ct.i >= 0)
	{
		game->tmp[game->ct.i] = get_next_line(fd);
		if (!game->tmp[game->ct.i])
			break ;
	}
	game->len.len_y = game->ct.i;
}

void	map_size(t_game *game)
{
	game->ct.map_size = 0;
	game->ct.i = -1;
	while (game->tmp[++game->ct.i])
	{
		game->ct.k = -1;
		while (game->tmp[game->ct.i][++game->ct.k])
			game->ct.map_size +=1;
	}
}

void	save_map(t_game *game)
{
	int	len;
	
	game->map = ft_calloc(sizeof(char), game->ct.map_size + game->len.len_y);
	if (!game->map)
	{
		free(game->map);
		free(game->tmp);
		perror("Error, wrong malloc <map>\n");
		exit(0);
	}
	game->ct.i = -1;
	while (++game->ct.i < game->len.len_y)
	{
		len = ft_strlen(game->tmp[game->ct.i]);
		game->map[game->ct.i] = game->tmp[game->ct.i];
		game->map[game->ct.i][len - 1] = '\0';
		if (len > game->len.max_len_x)
			game->len.max_len_x = len - 1;
		
		// printf("%s\n", game->map[game->ct.i]);
		// printf("%d\n", game->len.max_len_x);
	}
	free(game->tmp);
}

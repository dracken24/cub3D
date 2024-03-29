/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:59:59 by nadesjar          #+#    #+#             */
/*   Updated: 2023/01/17 16:05:13 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

void	ft_check_enemy_hit(t_game *game)
{
	t_vector2	pos;
	static int	ct;

	if (!ct || ct > 10)
		ct = 0;
	pos.x = 0;
	pos.y = 0;
	if (game->world_map[(int)game->enemy0.pos.y][(int)game->enemy0.pos.x] ==
		game->world_map[(int)game->player->pos.x][(int)game->player->pos.y]
			&& ct == 0)
	{
		if (game->player->life > 0)
			game->player->life -= 80;
		ft_print_sprite(game, &game->imgs.hit, pos, -16777216);
		game->ct_hit = 1;
		ct++;
	}
	if (game->player->life < 0)
		game->player->life = 0;
	if (ct > 0)
		ct++;
}

void	ft_open_door(t_game *game)
{
	if (game->mus_ct == 24)
	{
		system("killall afplay");
		game->mus_ct = 3;
	}
	if (game->world_map[(int)game->player->pos.x + 1]
		[(int)game->player->pos.y] == '2'
		|| game->world_map[(int)game->player->pos.x - 1]
		[(int)game->player->pos.y] == '2'
		|| game->world_map[(int)game->player->pos.x]
		[(int)game->player->pos.y + 1] == '2'
		|| game->world_map[(int)game->player->pos.x]
		[(int)game->player->pos.y - 1] == '2'
		|| game->world_map[(int)game->player->pos.x]
		[(int)game->player->pos.y] == '2')
		game->door_ct = 1;
	else
		game->door_ct = 0;
	if (game->door_ct == 1 && game->door_open_ct < 14)
		game->door_open_ct++;
	else if (game->door_ct == 0 && game->door_open_ct > 0
		&& game->door_open_ct != 14)
		game->door_open_ct--;
}

void	ft_music(t_game *game)
{
	if (game->mus_ct == 1)
	{
		system("afplay ./music/Intermission.mp3 &");
	}
	if (game->mus_ct == 2)
	{
		game->mus_ct = 24;
		system("afplay ./music/menu.mp3 &");
	}
	if (game->mus_ct == 3)
	{
		game->mus_ct = 23;
		system("afplay ./music/blade.mp3 &");
	}
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

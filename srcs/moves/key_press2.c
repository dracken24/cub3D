/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:41:31 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 19:01:44 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/control.h"

void	ft_move_w(t_game *game)
{
	t_vector2	pos;

	if (game->move_w == 1)
	{
		pos.x = (int)(game->player->pos.x + game->player->dir.x
				* game->move_speed);
		pos.y = (int)(game->player->pos.y);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.x += game->player->dir.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y
				+ game->player->dir.y * game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.y += game->player->dir.y * game->move_speed;
	}
}

void	ft_move_s(t_game *game)
{
	t_vector2	pos;

	if (game->move_s == 1)
	{
		pos.x = (int)(game->player->pos.x - game->player->dir.x
				* game->move_speed);
		pos.y = (int)(game->player->pos.y);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.x -= game->player->dir.x * game->move_speed;
		pos.x = (int)(game->player->pos.x);
		pos.y = (int)(game->player->pos.y
				- game->player->dir.y * game->move_speed);
		if (game->world_map[pos.x][pos.y] != '1')
			game->player->pos.y -= game->player->dir.y * game->move_speed;
	}
}

void	ft_move_a(t_game *game)
{
	// t_vector2	pos;
	double		olddirx;
	double		oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (game->move_a == 1)
	{
		game->player->dir.x = game->player->dir.x * cos(game->rot_speed)
			- game->player->dir.y * sin(game->rot_speed);
		game->player->dir.y = olddirx * sin(game->rot_speed)
			+ game->player->dir.y * cos(game->rot_speed);
		game->player->plane.x = game->player->plane.x * cos(game->rot_speed)
			- game->player->plane.y * sin(game->rot_speed);
		game->player->plane.y = oldplanex * sin(game->rot_speed)
			+ game->player->plane.y * cos(game->rot_speed);
	}
}

void	ft_move_d(t_game *game)
{
	double		olddirx;
	double		oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (game->move_d == 1)
	{
		game->player->dir.x = game->player->dir.x * cos(-game->rot_speed)
			- game->player->dir.y * sin(-game->rot_speed);
		game->player->dir.y = olddirx * sin(-game->rot_speed)
			+ game->player->dir.y * cos(-game->rot_speed);
		game->player->plane.x = game->player->plane.x * cos(-game->rot_speed)
			- game->player->plane.y * sin(-game->rot_speed);
		game->player->plane.y = oldplanex * sin(-game->rot_speed)
			+ game->player->plane.y * cos(-game->rot_speed);
	}
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_W)
		game->move_w = 0;
	else if (key == KEY_A)
		game->move_a = 0;
	else if (key == KEY_S)
		game->move_s = 0;
	else if (key == KEY_D)
		game->move_d = 0;
	return (0);
}

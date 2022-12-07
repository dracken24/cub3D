/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/02 01:11:08 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube3d_bonus.h"

int	ft_shoot(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1 && game->ct.start != 1)
	{
		game->fire = 1;
		game->imgs.handgun.i = 0;
	}
	// printf("SHOOT: x: %d y: %d button: %d\n", x, y, button);
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	// mlx_mouse_hide(game->mlx, game->win);
	if (game->ct.start != 1)
		move_mouse_x(game, x);
	game->last.x = x;
	game->last.y = y;
	return (0);
}

void	ft_mouse_move_x_suite(t_game *game, int x,
	double olddirx, double oldplanex)
{
	if (x > game->last.x)
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

void	move_mouse_x(t_game *game, int x)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (x < game->last.x)
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
	ft_mouse_move_x_suite(game, x, olddirx, oldplanex);
}
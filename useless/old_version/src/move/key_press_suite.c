/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:25:36 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	key_w(t_game *game)
{
	float	x;
	float	y;
	float	pi;
	float	angle;
	
	pi = game->utils.pi;
	angle = game->ray.angle;
	game->move_mini.x -= cosf(angle * pi / 180 + 0.5) / 5.3333 * 2;
	game->move_mini.y -= sinf(angle * pi / 180 + 0.5) / 5.3333 * 2;
	game->pos_real_p1.x += cosf(angle * pi / 180 + 0.5) * 2;
	game->pos_real_p1.y += sinf(angle * pi / 180 + 0.5) * 2;
	x = game->pos_real_p1.x;
	y =  game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x + 32) / 32] == '1'
			|| game->map[(int)y / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1')
	{
		game->move_mini.x += cosf(angle * pi / 180 + 0.5) / 5.3333 * 2;
		game->move_mini.y += sinf(angle * pi / 180 + 0.5) / 5.3333 * 2;
		game->pos_real_p1.x -= cosf(angle * pi / 180 + 0.5) * 2;
		game->pos_real_p1.y -= sinf(angle * pi / 180 + 0.5) * 2;
	}
	printf("W\n");
}

void	key_a(t_game *game)
{
	float	x;
	float	y;
	float	pi;
	float	angle;
	
	pi = game->utils.pi;
	angle = game->ray.angle;
	game->move_mini.x += cosf(angle * pi / 180 + 2.11) / 5.3333 * 2;
	game->move_mini.y += sinf(angle * pi / 180 + 2.11) / 5.3333 * 2;
	game->pos_real_p1.x -= cosf(angle * pi / 180 + 2.11) * 2;
	game->pos_real_p1.y -= sinf(angle * pi / 180 + 2.11) * 2;
	x = game->pos_real_p1.x;
	y =  game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x + 32) / 32] == '1'
			|| game->map[(int)y / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1')
	{
		game->move_mini.x -= cosf(angle * pi / 180 + 2.11) / 5.3333 * 2;
		game->move_mini.y -= sinf(angle * pi / 180 + 2.11) / 5.3333 * 2;
		game->pos_real_p1.x += cosf(angle * pi / 180 + 2.11) * 2;
		game->pos_real_p1.y += sinf(angle * pi / 180 + 2.11) * 2;
	}
	printf("A\n");
}

void	key_s(t_game *game)
{
	float	x;
	float	y;
	float	pi;
	float	angle;
	
	pi = game->utils.pi;
	angle = game->ray.angle;
	game->move_mini.x += cosf(angle * pi / 180 + 0.5) / 5.3333 * 2;
	game->move_mini.y += sinf(angle * pi / 180 + 0.5) / 5.3333 * 2;
	game->pos_real_p1.x -= cosf(angle * pi / 180 + 0.5) * 2;
	game->pos_real_p1.y -= sinf(angle * pi / 180 + 0.5) * 2;
	x = game->pos_real_p1.x;
	y =  game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x + 32) / 32] == '1'
			|| game->map[(int)y / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1')
	{
		game->move_mini.x -= cosf(angle * pi / 180 + 0.5) / 5.3333 * 2;
		game->move_mini.y -= sinf(angle * pi / 180 + 0.5) / 5.3333 * 2;
		game->pos_real_p1.x += cosf(angle * pi / 180 + 0.5) * 2;
		game->pos_real_p1.y += sinf(angle * pi / 180 + 0.5) * 2;
	}
	printf("S\n");
}

void	key_d(t_game *game)
{
	float	x;
	float	y;
	float	pi;
	float	angle;
	
	pi = game->utils.pi;
	angle = game->ray.angle;
	game->move_mini.x -= cosf(angle * pi / 180 + 2.11) / 5.3333 * 2;
	game->move_mini.y -= sinf(angle * pi / 180 + 2.11) / 5.3333 * 2;
	game->pos_real_p1.x += cosf(angle * pi / 180 + 2.11) * 2;
	game->pos_real_p1.y += sinf(angle * pi / 180 + 2.11) * 2;
	x = game->pos_real_p1.x;
	y =  game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x + 32) / 32] == '1'
			|| game->map[(int)y / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1')
	{
		game->move_mini.x += cosf(angle * pi / 180 + 2.11) / 5.3333 * 2;
		game->move_mini.y += sinf(angle * pi / 180 + 2.11) / 5.3333 * 2;
		game->pos_real_p1.x -= cosf(angle * pi / 180 + 2.11) * 2;
		game->pos_real_p1.y -= sinf(angle * pi / 180 + 2.11) * 2;
	}
	printf("D\n");
}

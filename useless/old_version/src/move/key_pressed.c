/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:29:24 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	key_pressed(int key, t_game *game)
{
	if (key == KEY_ESC_LINUX || key == KEY_ESC_MAC)
		kill_game(game, "Why did you kill me !#*@**#?");	
	else if (key == KEY_R_LINUX)
		key_r(game);
	else if (key == KEY_W_LINUX || key == KEY_W_MAC)
		key_w(game);
	else if (key == KEY_D_LINUX || key == KEY_D_MAC)
		key_d(game);
	else if (key == KEY_A_LINUX || key == KEY_A_MAC)
		key_a(game);
	else if (key == KEY_S_LINUX || key == KEY_S_MAC)
		key_s(game);
	printf("KEY: %d\n", key);
	// game->pos_real_p1.x = game->pos_p1.x * game->utils.tile_size + game->ct.move_x;
	// game->pos_real_p1.y = game->pos_p1.y * game->utils.tile_size + game->ct.move_y;
	printf("X: %f  Y: %f\n", game->pos_real_p1.x, game->pos_real_p1.y);
	return (0);
}

void	key_r(t_game *game)
{
	float	x;
	float	y;
	float	pi;
	float	angle;
	
	pi = game->utils.pi;
	angle = game->ray.angle;
	game->move_mini.x -= cosf(angle * pi / 180 + 0.5) / 5.3333 * 3.5;
	game->move_mini.y -= sinf(angle * pi / 180 + 0.5) / 5.3333 * 3.5;
	game->pos_real_p1.x += cosf(angle * pi / 180 + 0.5) * 3.5;
	game->pos_real_p1.y += sinf(angle * pi / 180 + 0.5) * 3.5;
	x = game->pos_real_p1.x;
	y =  game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x + 32) / 32] == '1'
			|| game->map[(int)y / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1')
	{
		game->move_mini.x += cosf(angle * pi / 180 + 0.5) / 5.3333 * 3.5;
		game->move_mini.y += sinf(angle * pi / 180 + 0.5) / 5.3333 * 3.5;
		game->pos_real_p1.x -= cosf(angle * pi / 180 + 0.5) * 3.5;
		game->pos_real_p1.y -= sinf(angle * pi / 180 + 0.5) * 3.5;
	}
	printf("W\n");
}

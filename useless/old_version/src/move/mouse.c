/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:09:40 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int mouse_move(int x, int y, t_game *game)
{
	if (x < game->ct.last_x)
		game->ray.angle -= 1;
	if (x > game->ct.last_x)
		game->ray.angle += 1;
	// printf("Mouse_Key: %f X: %d Y: %d\n", game->ray.angle, x, y);
	game->ct.last_x = x;
	game->ct.last_y = y;
	return (0);
}

// int	mouse_key(int key, int x, int y, t_game *game)
// {
// 	// mlx_mouse_move(game->win, x, y);

// 	if (key == KEY_M_L_LINUX)
// 	{
// 		game->ray.angle -= 6;
// 	}
// 	if (key == KEY_M_R_LINUX)
// 	{
// 		game->ray.angle += 6;
// 	}
// 	game->test = 0;
// 	printf("Mouse_Key: %f X: %d Y: %d\n", game->ray.angle, x, y);
// 	return (0);
// }

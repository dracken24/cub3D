/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/12/09 12:58:59 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/control.h"

int	key_press(int key, t_game *game)
{
	// dprintf(1, "KEY: %d\n", key);

	if (key == KEY_W)
		game->move_w = 1;
	else if (key == KEY_S)
		game->move_s = 1;
	else if (key == KEY_A)
		game->move_a = 1;
	else if (key == KEY_D)
		game->move_d = 1;
	else if (key == KEY_RIGHT)
		game->move_ri = 1;
	else if (key == KEY_LEFT)
		game->move_lft = 1;
	else if (key == KEY_ESC)
		x_quit(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:22:57 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	draw_env(t_game *game)
{
	
	game->ct.i = -1;
	while (++game->ct.i < game->len.len_y)
	{
		game->ct.k = -1;
		while (++game->ct.k < game->len.max_len_x)
		{
			if (game->map[game->ct.i][game->ct.k] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall.wall_01, game->ct.k
						* game->utils.tile_size, game->ct.i * game->utils.tile_size);
				draw_square(game, (game->utils.whide - game->utils.x_case * 6)
						+ (game->ct.k * 6) + game->move_mini.x,
						game->ct.i * 6 + game->move_mini.y, 777744);
			}
			// if (game->map[game->ct.i][game->ct.k] == '0')
			// 	draw_square(game, (game->utils.whide - game->utils.x_case * 6)
			// 			+ (game->ct.k * 6) + game->move_mini.x,
			// 			game->ct.i * 6 + game->move_mini.y, 663544);
			// if (game->map[game->ct.i][game->ct.k] == 'N')
			// 	draw_square(game, imgs, game->ct.k * game->utils.tile_size,
			// 			game->ct.i * game->utils.tile_size, 000000);
			// if (game->map[game->ct.i][game->ct.k] == 'S')
			// 	draw_square(game, imgs, game->ct.k * game->utils.tile_size,
			// 			game->ct.i * game->utils.tile_size, 557744);
			if (game->map[game->ct.i][game->ct.k] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall.circle,
						game->pos_real_p1.x, game->pos_real_p1.y);
				draw_square(game, game->ct.xx , game->ct.yy, 999333);
			}
			// if (game->map[game->ct.i][game->ct.k] == 'W')
			// 	draw_square(game, imgs, game->ct.k * game->utils.tile_size,
			// 			game->ct.i * game->utils.tile_size, 337744);
			
		}
		// draw_grid(game);
	}
	// draw_square(game, game->pos_real_p1.x,
	// 			game->pos_real_p1.y, 667744);
}

void	draw_square(t_game *game, int x, int y, int color)
{
	color--;
	game->ct.ii = -1;
	if (x > (int)(game->utils.whide - game->utils.x_case * 6)
			&& y < (int)game->utils.y_case * 6)
	{
		while (++game->ct.ii < 6)
		{
			game->ct.kk = -1;
			while (++game->ct.kk < 6)
			{
				if (mlx_pixel_put(game->mlx, game->win, x + game->ct.kk,
							y + game->ct.ii, color) == 1)
					game->test = 0;
				else
					mlx_pixel_put(game->mlx, game->win, x + game->ct.kk,
								y + game->ct.ii, color);
			}
		}
	}
}

void draw_cursor(t_game *game)
{
	int x;
	int y;
	int i;

	x = game->ct.last_x;
	y = game->ct.last_y;
	i = -1;
	while (++i < 20)
	{
		mlx_pixel_put(game->mlx, game->win, x - 10,
					  y, 0xff1493);
		x++;
	}
	x = game->ct.last_x;
	i = -1;
	while (++i < 20)
	{
		mlx_pixel_put(game->mlx, game->win, x,
					  y - 10, 0xff1493);
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:44:43 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	draw_grid(t_game *game)
{
	printf("DRAW_GRID_-0\n");
	game->ct.i = 0;
	while (game->ct.i <= (int)game->utils.whide)
	{
		game->ct.k = -1;
		while (++game->ct.k <= (int)game->utils.height)
		{
			mlx_pixel_put(game->mlx, game->win, game->ct.i, game->ct.k, 229922);
		}
		game->ct.i += game->utils.tile_size;
	}
	game->ct.i = -1;
	while (++game->ct.i <= (int)game->utils.whide)
	{
		game->ct.k = 0;
		while (game->ct.k <= (int)game->utils.height)
		{
			mlx_pixel_put(game->mlx, game->win, game->ct.i, game->ct.k, 229922);
			game->ct.k += game->utils.tile_size;
		}
	}
	game->ct.i = -1;
	game->ct.k = -1;
	while (++game->ct.i <= (int)game->utils.height)
		mlx_pixel_put(game->mlx, game->win, game->utils.whide - 1, game->ct.i, 229922);
	while (++game->ct.k <= (int)game->utils.whide)
		mlx_pixel_put(game->mlx, game->win, game->ct.k, game->utils.height - 1, 229922);
	mlx_pixel_put(game->mlx, game->win, (int)game->ray.mouse_pos.x, (int)game->ray.mouse_pos.y, 229922);
	printf("P1_x: %f P1_y: %f\n", game->pos_p1.x, game->pos_p1.y);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:19:51 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	update(t_game *game)
{
	wait_time(game, 1);
	check_angle(game);
	draw_cursor(game);
	// mlx_clear_window(game->mlx, game->win);
	// draw_raycast(game);
	// draw_grid(game);
	draw_env(game);
	raycast_01(game);
	// printf("TEST: %p\n", game->imgs.wall.wall_01);
	// pos(game);
	return (0);
}


void	pos(t_game *game)
{
	mlx_mouse_get_pos(game->mlx, game->win, (int *)&game->ray.mouse_pos.x, (int *)&game->ray.mouse_pos.y);
	// printf("Mouse_x: %f Mouse_y: %f\n", game->ray.mouse_pos.x, game->ray.mouse_pos.y);
}

void	wait_time(t_game *game, int i)
{
	while (i > 0)
	{
		if (game->ct.time < 10.0f)
		{
			game->ct.time += 0.1f;;
		}
		if (game->ct.time > 1.0f)
		{
			mlx_clear_window(game->mlx, game->win);
			game->ct.time = 0.0f;
		}
		i--;
	}
}

void	find_player(t_game *game)
{
	printf("FIND 1\n");
	game->ct.i = -1;
	while (game->map[++game->ct.i])
	{
		game->ct.k = -1;
		while (game->map[game->ct.i][++game->ct.k])
		{
			if (game->map[game->ct.i][game->ct.k] == 'N'
					|| game->map[game->ct.i][game->ct.k] == 'S'
					|| game->map[game->ct.i][game->ct.k] == 'E'
					|| game->map[game->ct.i][game->ct.k] == 'W')
			{
				game->pos_p1.x = game->ct.k;
				game->pos_p1.y = game->ct.i;
				game->pos_p1_min_map.x = (game->utils.whide - game->utils.x_case * 6) + (game->ct.k * 6);
				game->pos_p1_min_map.y = (game->ct.i * 6);
				game->ct.xx = game->pos_p1_min_map.x;
				game->ct.yy = game->pos_p1_min_map.y;
			}
		}
	}
	game->pos_real_p1.x = game->pos_p1.x * game->utils.tile_size + game->ct.move_x;
	game->pos_real_p1.y = game->pos_p1.y * game->utils.tile_size + game->ct.move_y;
	printf("P1_x: %f  p1_y: %f\n", game->pos_p1.x, game->pos_p1.y);
}

void	check_angle(t_game *game)
{
	if (game->ray.angle < 0.0f)
		game->ray.angle = 360.0f;
	if (game->ray.angle > 360.0f)
		game->ray.angle = 0.0f;
}

void	start_direction(t_game *game)
{

	if (game->ray.angle == 0.0f)
	{
		game->ray.cos = 0;
		game->ray.sin = -1;
	}
	else if (game->ray.angle == 90.0f)
	{
		game->ray.cos = 1;
		game->ray.sin = 0;
	}
	else if (game->ray.angle == 180.0f)
	{
		game->ray.cos = 0;
		game->ray.sin = 1;
	}
	else if (game->ray.angle == 270.0f)
	{
		game->ray.cos = -1;
		game->ray.sin = 0;
	}
}

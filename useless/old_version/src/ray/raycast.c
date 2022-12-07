/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:35:29 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


// int	raycast_01(t_game *game)
// {
// 	game->ct.x = (((int)game->pos_real_p1.x + (game->utils.tile_size / 2)) / game->utils.tile_size);
// 	game->ct.y = (int)game->pos_real_p1.y / game->utils.tile_size;
// 	game->ct.i = -1;
// 	while (++game->ct.i < (float)game->ray.nbr_ray)
// 	{
// 		printf("TEST\n");
// 		// first_ray(game, game->ct.i, ((int)game->pos_real_p1.x + (game->utils.tile_size / 2)),
// 		// 		(int)game->pos_real_p1.y - (game->utils.tile_size / 2));
// 	}
	
// 	return (0);
// }

// int	raycast_01(t_game *game)
// {
// 	game->ct.x = (((int)game->pos_real_p1.x + (game->utils.tile_size / 2)) / game->utils.tile_size);
// 	game->ct.y = (int)game->pos_real_p1.y / game->utils.tile_size;
// 	game->ct.i = -1;
// 	while (++game->ct.i < (float)game->ray.nbr_ray)
// 	{
// 		printf("NBR: %d\n", game->ct.i);
// 		first_ray(game, game->ct.i, ((int)game->pos_real_p1.x + (game->utils.tile_size / 2)),
// 				(int)game->pos_real_p1.y - (game->utils.tile_size / 2));
// 	}
	
// 	return (0);
// }

// void	first_ray(t_game *game, float i, float x, float y)
// {
// 	game->ray.xx = game->pos_p1_min_map.x;
// 	game->ray.yy = game->pos_p1_min_map.y;
// 	game->ray.pi = game->utils.pi / 180;
// 	game->ct.kk = (int)y;
// 	game->ct.ii = (int)x;

// 	ray_again(game, i, x, y + game->utils.tile_size);
// }

// void	ray_again(t_game *game, float i, float x, float y)
// {
// 	// int g;
// 	int h;
// 	// int ct = -1;
// 	int	*ray;
	
// 	ray = ft_calloc(sizeof(int), 5);
// 	if (!ray)
// 	{
// 		free(ray);
// 		kill_game(game, "Error, wrong alloc <ray_again>");
// 	}
// 	ray[0] = (int)x;
// 	ray[1] = (int)y;
// 	game->ct.kk = (int)y / 32;
// 	game->ct.ii = (int)x / 32;
// 	// g = 0;
// 	h = 0;
// 	while (game->map[game->ct.kk][game->ct.ii] != '1')
// 	{
// 		game->ct.kk = (int)y / 32;
// 		game->ct.ii = (int)x / 32;
// 		// if (game->map[game->ct.kk][game->ct.ii] == '1')
// 		// 	break;
// 		// if (((int)x % game->utils.tile_size == 0
// 		// 		|| (int)y % game->utils.tile_size == 0)
// 		// 		&& game->ray.xx > (int)(game->utils.whide - game->utils.x_case * 6)
// 		// 		&& game->ray.yy < (int)game->utils.y_case * 6)
// 		// {
// 		mlx_pixel_put(game->mlx, game->win, game->ray.xx + 3,
// 					game->ray.yy + 3, 100000);
// 		// }
// 		// if ((int)x % game->utils.tile_size == 0
// 		// 		|| (int)y % game->utils.tile_size == 0)
// 		// {
// 		mlx_pixel_put(game->mlx, game->win, x,
// 						y, 100000);	
// 		// }
// 		x += cosf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12) * 32;
// 		y += sinf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12) * 32;
// 		game->ray.xx += (cosf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12) / 32 * 6) * 32;
// 		game->ray.yy += (sinf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12) / 32 * 6) * 32;
// 		// g += 32;
// 		h++;
// 		// printf("CT: %d\n", ++ct);
// 		printf("H: %d\n", h);
// 	}
// 	ray[2] = (int)x;
// 	ray[3] = (int)y;
// 	save_ray(game, ray, game->ct.i);
// }

// void	save_ray(t_game *game, int *ray, int i)
// {
// 	int		x;
// 	int		y;
// 	x = ray[0] - ray[2];
// 	y = ray[1] - ray[3];
// 	if (x < 0)
// 		x *= -1;
// 	if (y < 0)
// 		y *= -1;
// 	game->ray_len[i] = (int)sqrt((x * x) + (y * y));
// 	// printf("RAY_LEN: %d\n", game->ray_len[i]);
// }

// void	calculate_rays(int start_x, int x, int start_y, int y)
// {
	
// }





int	raycast_01(t_game *game)
{
	game->ct.x = (((int)game->pos_real_p1.x + (game->utils.tile_size / 2)) / game->utils.tile_size);
	game->ct.y = (int)game->pos_real_p1.y / game->utils.tile_size;
	game->ct.i = -1;
	while (++game->ct.i < (float)game->ray.nbr_ray)
	{
		first_ray(game, game->ct.i, ((int)game->pos_real_p1.x + (game->utils.tile_size / 2)),
				(int)game->pos_real_p1.y - (game->utils.tile_size / 2));
	}
	
	return (0);
}

void	first_ray(t_game *game, float i, float x, float y)
{
	game->ray.xx = game->pos_p1_min_map.x;
	game->ray.yy = game->pos_p1_min_map.y;
	game->ray.pi = game->utils.pi / 180;
	game->ct.kk = (int)y;
	game->ct.ii = (int)x;

	ray_again(game, i, x, y + game->utils.tile_size);
}

void	ray_again(t_game *game, float i, float x, float y)
{
	// int g;
	int h;
	// int ct = -1;
	int	*ray;
	
	ray = ft_calloc(sizeof(int), 5);
	if (!ray)
	{
		free(ray);
		kill_game(game, "Error, wrong alloc <ray_again>");
	}
	ray[0] = (int)x;
	ray[1] = (int)y;
	// g = 0;
	h = 0;
	while (game->map[game->ct.kk / 32][game->ct.ii / 32] != '1')
	{
		game->ct.kk = (int)y;
		game->ct.ii = (int)x;
		// if (game->map[game->ct.kk][game->ct.ii] == '1')
		// 	break;
		if (((int)x % game->utils.tile_size == 0
				|| (int)y % game->utils.tile_size == 0)
				&& game->ray.xx > (int)(game->utils.whide - game->utils.x_case * 6)
				&& game->ray.yy < (int)game->utils.y_case * 6)
		{
			mlx_pixel_put(game->mlx, game->win, game->ray.xx + 3,
					game->ray.yy + 3, 100000);
		}
		if ((int)x % game->utils.tile_size == 0
				|| (int)y % game->utils.tile_size == 0)
		{
			mlx_pixel_put(game->mlx, game->win, x,
					y, 100000);	
		}
		x += cosf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12);
		y += sinf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12);
		game->ray.xx += (cosf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12) / 32 * 6);
		game->ray.yy += (sinf(game->ray.angle * game->ray.pi + i * game->ray.pi / 12) / 32 * 6);
		// g += 32;
		h++;
		// printf("CT: %d\n", ++ct);
	}
	ray[2] = (int)x;
	ray[3] = (int)y;
	save_ray(game, ray, game->ct.i);
}

void	save_ray(t_game *game, int *ray, int i)
{
	int		x;
	int		y;
	x = ray[0] - ray[2];
	y = ray[1] - ray[3];
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	game->ray_len[i] = (int)sqrt((x * x) + (y * y));
	printf("RAY_LEN: %d\n", game->ray_len[i]);
}
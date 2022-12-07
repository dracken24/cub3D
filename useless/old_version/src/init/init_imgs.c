/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:06:40 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	init_imgs(t_game *game)
{
	int	x;
	int	y;
	
	game->imgs.wall.wall_01 = mlx_xpm_file_to_image(game->mlx, "./imgs/brick_01.xpm", &x, &y);
	game->imgs.wall.circle = mlx_xpm_file_to_image(game->mlx, "./imgs/circle.xpm", &x, &y);
	printf("INIT_IMG\n");
}

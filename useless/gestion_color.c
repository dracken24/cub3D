/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/14 11:51:12 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_choose_color(t_game *game)
{
	// game->color_xpm = ft_calloc(sizeof(char), 2);
	// choose wall color
	if (game->world_map[game->map_x][game->map_y] == '1')
	{
		// game->color_xpm[0] = ';';
		// game->color_xpm[1] = '\0';
		game->color = create_trgb(0, 189, 112, 36);
	}
	else if (game->world_map[game->map_x][game->map_y] == '2')
	{
		// game->color_xpm[0] = '-';
		// game->color_xpm[1] = '\0';
		game->color = create_trgb(0, 110, 64, 164);
	}
	else if (game->world_map[game->map_x][game->map_y] == '3')
	{
		// game->color_xpm[0] = '+';
		// game->color_xpm[1] = '\0';
		game->color = create_trgb(0, 164, 64, 130);
	}
	else if (game->world_map[game->map_x][game->map_y] == '4')
	{
		// game->color_xpm[0] = 'g';
		// game->color_xpm[1] = '\0';
		game->color = create_trgb(0, 62, 62, 191);
	}
	else
	{
		// game->color_xpm[0] = 'p';
		// game->color_xpm[1] = '\0';
		game->color = create_trgb(0, 255, 153, 51);
	}
}

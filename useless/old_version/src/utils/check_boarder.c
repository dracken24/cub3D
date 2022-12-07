/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boarder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:03:48 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	check_board(t_game *game)
{
	game->ct.error = 1;
	check_boarder_01(game);
	if (game->ct.error == 0)
	{
		free(game->map);

		perror("Error, Boarder not ok\n");
		exit(0);
	}
}

void	check_boarder_01(t_game *game)
{
	game->ct.i = -1;
	while (++game->ct.i < game->len.len_y)
	{
		game->ct.k = 0;
		while (game->map[game->ct.i][game->ct.k])
		{
			check_direction(game);
			while (game->map[game->ct.i][game->ct.k] == ' ')
				game->ct.k++;
			if (game->map[game->ct.i][game->ct.k] != CASE_1)
			{
				check_in_x(game);
				check_in_y(game);
			}
			game->ct.k++;
		}
	}
}

void	check_in_x(t_game *game)
{
	if (game->map[game->ct.i][game->ct.k - 1] != CASE_E
			&& game->map[game->ct.i][game->ct.k - 1] != CASE_1
			&& game->map[game->ct.i][game->ct.k - 1] != CASE_0
			&& game->map[game->ct.i][game->ct.k - 1] != CASE_N
			&& game->map[game->ct.i][game->ct.k - 1] != CASE_S
			&& game->map[game->ct.i][game->ct.k - 1] != CASE_W)
		game->ct.error = 0;
	if (game->map[game->ct.i][game->ct.k + 1] != CASE_E
			&& game->map[game->ct.i][game->ct.k + 1] != CASE_1
			&& game->map[game->ct.i][game->ct.k + 1] != CASE_0
			&& game->map[game->ct.i][game->ct.k + 1] != CASE_N
			&& game->map[game->ct.i][game->ct.k + 1] != CASE_S
			&& game->map[game->ct.i][game->ct.k + 1] != CASE_W)
		game->ct.error = 0;
}

void	check_in_y(t_game *game)
{
	if (game->map[game->ct.i - 1][game->ct.k] != CASE_E
			&& game->map[game->ct.i - 1][game->ct.k] != CASE_1
			&& game->map[game->ct.i - 1][game->ct.k] != CASE_0
			&& game->map[game->ct.i - 1][game->ct.k] != CASE_N
			&& game->map[game->ct.i - 1][game->ct.k] != CASE_S
			&& game->map[game->ct.i - 1][game->ct.k] != CASE_W)
		game->ct.error = 0;
	if (game->map[game->ct.i + 1][game->ct.k] != CASE_E
			&& game->map[game->ct.i + 1][game->ct.k] != CASE_1
			&& game->map[game->ct.i + 1][game->ct.k] != CASE_0
			&& game->map[game->ct.i + 1][game->ct.k] != CASE_N
			&& game->map[game->ct.i + 1][game->ct.k] != CASE_S
			&& game->map[game->ct.i + 1][game->ct.k] != CASE_W)
		game->ct.error = 0;
}

void	check_direction(t_game *game)
{
	if (game->map[game->ct.i][game->ct.k] == CASE_N)
		game->ray.angle = 239;
	if (game->map[game->ct.i][game->ct.k] == CASE_S)
		game->ray.angle = 57;
	if (game->map[game->ct.i][game->ct.k] == CASE_E)
		game->ray.angle = 329;
	if (game->map[game->ct.i][game->ct.k] == CASE_W)
		game->ray.angle = 148;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usless.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void ft_init_img(t_game *game, int img)
{
	int i;
	int k;
	char *str;

	game->xpm = ft_calloc(sizeof(char *), game->h + 12);
	if (!game->xpm)
		x_quit(game);
	game->xpm[0] = ft_strdup("/* XPM */\n");
	game->xpm[1] = ft_strdup("static char *result[] = {\n");
	game->xpm[2] = ft_strdup("/* columns rows colors chars-per-pixel */\n");
	game->xpm[3] = ft_strdup("\"640 400 6 1 \",\n");
	game->xpm[4] = ft_strdup("\". c black \",\n");
	game->xpm[5] = ft_strdup("\"; c #0000B0 \",\n");
	game->xpm[6] = ft_strdup("\"- c #6C4824 \",\n");
	game->xpm[7] = ft_strdup("\"+ c #382C14 \",\n");
	game->xpm[8] = ft_strdup("\"g c #B4AC00 \",\n");
	game->xpm[9] = ft_strdup("\"p c #FCF420 \",\n");
	game->xpm[10] = ft_strdup("/* pixels */ \n");
	i = 0;
	while (i < 11)
	{
		ft_putstr_fd(game->xpm[i], img);
		i++;
	}
	while (i < game->h + 11)
	{
		str = ft_strjoin("\"", "\n\0", 0);
		game->xpm[i] = ft_strdup(str);
		ft_putstr_fd(game->xpm[i], img);
		free(str);
		i++;
	}
}

bool ft_draw_line(t_game *game, int x, int y1, int y2)
{

	int i;
	int k;
	int img;
	char *tmp;

	if (y2 < y1) // swap y1 and y2
	{
		y1 += y2;
		y2 = y1 - y2;
		y1 -= y2;
	}
	if (y2 < 0 || y1 >= game->h || x < 0 || x >= game->w) // no single point of the line is on screen
		return 0;
	if (y1 < 0) // clip
		y1 = 0;
	if (y2 >= game->w) // clip
		y2 = game->h - 1;

	if (game->i == 1)
	{
		img = ft_open_fd("tmp.xpm", 3);
		if (!img)
			return false;
		ft_init_img(game, img);
		close(img);
	}
	else
	{
		i = 0;
		k = 0;
		ft_choose_color(game);
		while (i < 11)
		{
			i++;
		}
		while (i < y1 + 11)
		{
			game->xpm[i][ft_strlen(game->xpm[i])] = '\0';
			game->xpm[i] = ft_strjoin(game->xpm[i], ".\0", 1);

			k++;
			i++;
		}
		// printf("A\n");
		while (y1 <= y2)
		{
			game->xpm[i][ft_strlen(game->xpm[i])] = '\0';
			game->xpm[i] = ft_strjoin(game->xpm[i], game->color_xpm, 1);
			k++;
			y1++;
			i++;
		}
		i--;
		while (++i < game->h + 11)
		{
			game->xpm[i][ft_strlen(game->xpm[i])] = '\0';
			game->xpm[i] = ft_strjoin(game->xpm[i], ".\0", 1);
			k++;
		}

		img = ft_open_fd("tmp.xpm", 3);
		if (!img)
			return false;

		i = -1;
		while (game->xpm[++i])
		{
			ft_putstr_fd(game->xpm[i], img);
			if (i > 10)
			{
				if (i == game->h + 10)
				{
					ft_putstr_fd("\"\n", img);
					ft_putstr_fd("};\n", img);
				}
				else
					ft_putstr_fd("\",\n", img);
			}
		}
		close(img);
		return (true);
	}

	ft_choose_color(game);

	i = 0;
	k = 0;
	while (i < 11)
	{
		i++;
	}
	while (i < y1 + 11)
	{
		game->xpm[i][ft_strlen(game->xpm[i]) - 1] = '.';
		game->xpm[i][ft_strlen(game->xpm[i])] = '\"';
		game->xpm[i][ft_strlen(game->xpm[i]) + 1] = '\n';
		game->xpm[i][ft_strlen(game->xpm[i + 2])] = '\0';
		k++;
		i++;
	}
	while (y1 <= y2)
	{
		game->xpm[i][ft_strlen(game->xpm[i]) - 1] = game->color_xpm[0];
		game->xpm[i][ft_strlen(game->xpm[i])] = '\0';
		k++;
		y1++;
		i++;
	}
	i--;
	while (++i < game->h + 11)
	{
		game->xpm[i][ft_strlen(game->xpm[i]) - 1] = '.';
		game->xpm[i][ft_strlen(game->xpm[i])] = '\0';
		k++;
	}

	img = ft_open_fd("tmp.xpm", 3);
	if (!img)
		return false;

	i = -1;
	while (game->xpm[++i])
	{
		ft_putstr_fd(game->xpm[i], img);
		if (i > 10)
		{
			if (i == game->h + 10)
			{
				ft_putstr_fd("\"\n", img);
				ft_putstr_fd("};\n", img);
			}
			else
				ft_putstr_fd("\",\n", img);
		}
	}
	close(img);
	return (true);
}

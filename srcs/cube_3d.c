/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/11/01 20:48:49 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/control.h"

void	ft_clean_map(int fd)
{
	int		fdsave;
	char	*tmp;

	fdsave = ft_open_fd("tmp.cub", 2);
	if (!fd)
		return ;
	tmp = get_next_line(fd);
	while (tmp)
	{
		ft_putstr_fd(tmp, fdsave);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fdsave);
}

void	ft_split_map_suite(t_game *game, int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	game->imgs.texture_n.name = ft_strdup(tmp + 3);
	ft_free(tmp);
	tmp = get_next_line(fd);
	game->imgs.texture_s.name = ft_strdup(tmp + 3);
	ft_free(tmp);
	tmp = get_next_line(fd);
	game->imgs.texture_w.name = ft_strdup(tmp + 3);
	ft_free(tmp);
	tmp = get_next_line(fd);
	game->imgs.texture_e.name = ft_strdup(tmp + 3);
	ft_free(tmp);
	tmp = get_next_line(fd);
	ft_free(tmp);
	tmp = get_next_line(fd);
	game->imgs.down.name = ft_strdup(tmp + 2);
	ft_free(tmp);
	tmp = get_next_line(fd);
	game->imgs.top.name = ft_strdup(tmp + 2);
	ft_free(tmp);
	tmp = get_next_line(fd);
	ft_free(tmp);
}

void	ft_split_map(t_game *game, char *name)
{
	int	fd;

	if (check_name(name) == 0)
	{
		printf("Error, Invalid files <name>.cub\n");
		exit(0);
	}
	fd = ft_open_fd(name, 1);
	if (!fd)
	{
		printf("error, wrong open for <name>.ber\n");
		exit(0);
	}
	ft_split_map_suite(game, fd);
	ft_clean_map(fd);
	close(fd);
}

void	*ft_run_mlx(void *arg)
{
	t_game	*game;

	game = arg;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->w, game->h, "BANKAI");
	ft_init_imgs(game);

	game->player = ft_init_player(game);
	mlx_hook(game->win, 17, 0, x_quit, game);
	mlx_loop_hook(game->mlx, ft_routine, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop(game->mlx);
	return (NULL);
}

int	main(int entry, char **name)
{
	t_game	game;

	ft_split_map(&game, name[1]);
	check_entry(&game, entry, "tmp.cub");
	init_vars(&game);
	ft_run_mlx(&game);
	return (0);
}

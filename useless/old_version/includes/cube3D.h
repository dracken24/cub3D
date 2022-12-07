/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:15 by nadesjar          #+#    #+#             */
/*   Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cube3d_H
# define cube3d_H

# include "../src/get_next_line/gnl.h"
# include "../src/libft/libft.h"
# include "../minilibx/mlx-linux/mlx.h"
// # include "../minilibx/opengl/mlx.h"
# include "imgs.h"
# include <math.h>

typedef __uint8_t uint8_t;
typedef	uint8_t uint8;
#define SDL_MAX_UINT8   ((Uint8)0xFF)           /* 255 */
#define SDL_MIN_UINT8   ((Uint8)0x00)           /* 0 */

// typedef struct ColorRGBA
// {
// 	uint8 color;
// 	int r;
// 	int g;
// 	int b;
// 	int a;

// 	struct	ColorRGBA(uint8 r, uint8 g, uint8 b, uint8 a);
// 	struct	ColorRGBA(const struct ColorRGBA color);
// 	struct	ColorRGBA();
// }	ColorRGBA;


/* Control Key */
typedef enum s_keyboard {
	KEY_A_LINUX = 97,
	KEY_D_LINUX = 100,
	KEY_S_LINUX = 115,
	KEY_W_LINUX = 119,
	KEY_E_LINUX = 101,
	KEY_R_LINUX = 114,
	KEY_M_L_LINUX = 1,
	KEY_M_R_LINUX = 3,
	KEY_SPACE_LINUX = 32,
	KEY_ESC_LINUX = 65307,
	KEY_A_MAC = 0,
	KEY_D_MAC = 2,
	KEY_S_MAC = 1,
	KEY_W_MAC = 13,
	KEY_E_MAC = 14,
	KEY_SPACE_MAC = 49,
	KEY_ESC_MAC = 53,
}	t_keyboard;

typedef enum s_letters{
	CASE_0 = '0',
	CASE_1 = '1',
	CASE_N = 'N',
	CASE_S = 'S',
	CASE_E = 'E',
	CASE_W = 'W',
} t_letters;

typedef struct s_vector_2 {
	float		x;
	float		y;
}	t_vector2;

typedef struct s_vector_3 {
	float		x;
	float		y;
	float		z;
}	t_vector3;

/* Counters */
typedef struct s_ct {
	float		x;
	float		y;
	float		xx;
	float		yy;
	float		rotate_x;
	float		rotate_y;
	int			last_x;
	int			last_y;
	int			i;
	int			ii;
	int			k;
	int			kk;
	int			map_size;
	int			move_x;
	int			move_y;
	int			error;
	float		time;
}	t_ct;

/* Len */
typedef struct s_len {
	int			len;
	int			len_x;
	int			len_y;
	int			max_len_x;
	int			max_len_y;
}	t_len;

/* Utils */
typedef struct s_utils {
	float			pi;
	float			pyt;
	unsigned int	wait;
	unsigned int	x_case;
	unsigned int	y_case;
	unsigned int	tile_size;
	unsigned int	whide;
	unsigned int	height;
}	t_utils;

typedef struct s_ray {
	t_vector2	mouse_pos;
	int			nbr_ray;
	int			half_nbr_ray;
	float		xx;
	float		yy;
	float		pi;
	float		*pos;
	// float		**ray;
	// float		**last_ray;
	float		angle;
	float		fov;
	float		ray_len;
	float		radius;
	float		move_speed;
	float		angle_speed;
	float		cos;
	float		sin;
}	t_ray;

/* General */
typedef struct s_game {
	int		*ray_len;
	int			test;
	char		**map;
	char		**tmp;
	void		*mlx;
	void		*win;
	t_vector2	pos_p1;
	t_vector2	pos_p1_min_map;
	t_vector2	move_mini;
	t_vector2	pos_real_p1;
	t_utils		utils;
	t_ray		ray;
	t_len		len;
	t_ct		ct;
	t_imgs		imgs;
	
	int			w;
	int			h;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		time;
	double		oldTime;
	double		planeX;
	double		planeY;
}	t_game;

/* Check */
void	check_entry(int entry, char **name, t_game *game);
void	mape_size(char **name, t_game *game);
void	map_read(t_game *game, char *name);
void	check_boarder_01(t_game *game);
void	check_direction(t_game *game);
void	check_board(t_game *game);
void	check_angle(t_game *game);
void	check_in_x(t_game *game);
void	check_in_y(t_game *game);
void	save_map(t_game *game);
void	map_size(t_game *game);

int 	check_name(t_game *game, char *name);

/* Utility */

/* Init game */
void	init_window(t_game *game);
void	init_imgs(t_game *game);
void	init_var(t_game *game);

/* Mecanique */
void	kill_game(t_game *game, char *str);
void	wait_time(t_game *game, int i);
void	find_player(t_game *game);
void	pos(t_game *game);

int		update(t_game *game);
int		x_quit(t_game *game);

/* Control */
void	draw_cursor(t_game *game);
void	key_r(t_game *game);
void	key_w(t_game *game);
void	key_a(t_game *game);
void	key_s(t_game *game);
void	key_d(t_game *game);

int		key_pressed(int key, t_game *game);
// int		mouse_key(int key, int x, int y, t_game *game);
int 	mouse_move(int x, int y, t_game *game);

/* RayCasting */
void	first_ray(t_game *game, float i, float x, float y);
void	ray_again(t_game *game, float i, float x, float y);
void	save_ray(t_game *game, int *ray, int i);

int		raycast_01(t_game *game);
// void	start_direction(t_game *game);

/* Draw */
void	draw_square(t_game *game, int x, int y, int color);
// void	draw_raycast(t_game *game);
void	draw_env(t_game *game);
// void	draw(t_game *game, t_imgs *imgs);

int		draw_grid(t_game *game);

#endif

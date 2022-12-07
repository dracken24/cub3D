int	key_pressed(int key, t_game *game)
{
	if (key == KEY_ESC_LINUX || key == KEY_ESC_MAC)
		kill_game(game, "Why did you kill me !#*@**#?");	
	else if (key == KEY_D_LINUX || key == KEY_D_MAC)
		key_d(game);
	else if (key == KEY_A_LINUX || key == KEY_A_MAC)
		key_a(game);
	else if (key == KEY_W_LINUX || key == KEY_W_MAC)
		key_w(game);
	else if (key == KEY_S_LINUX || key == KEY_S_MAC)
		key_s(game);
	printf("KEY: %d\n", key);
	// game->pos_real_p1.x = game->pos_p1.x * game->utils.tile_size + game->ct.move_x;
	// game->pos_real_p1.y = game->pos_p1.y * game->utils.tile_size + game->ct.move_y;
	printf("X: %f  Y: %f\n", game->pos_real_p1.x, game->pos_real_p1.y);
	return (0);
}

void	key_w(t_game *game)
{
	float	x;
	float	y;
	
	game->move_mini.x -= cosf(game->ray.angle * game->utils.pi / 180 + 150) / 5.3333;
	game->move_mini.y -= sinf(game->ray.angle * game->utils.pi / 180 + 150) / 5.3333;
	game->pos_real_p1.x += cosf(game->ray.angle * game->utils.pi / 180 + 0.5);
	game->pos_real_p1.y += sinf(game->ray.angle * game->utils.pi / 180 + 0.5);
	x = game->pos_real_p1.x;
	y =  game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x + 32) / 32] == '1'
			|| game->map[(int)y / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1')
	{
		
		game->pos_real_p1.y += 12;
		game->move_mini.y -= 12.0 / 5.3333;
	}
	printf("W\n");
}

void	key_a(t_game *game)
{
	float	x;
	float	y;
	
	game->move_mini.x += 12.0 / 5.3333;
	game->pos_real_p1.x -= 12;
	x = game->pos_real_p1.x;
	y = game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x + 32) / 32] == '1'
			|| game->map[(int)y / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1')
	{
		game->pos_real_p1.x += 12;
		game->move_mini.x -= 12.0 / 5.3333;
	}
	printf("A\n");
}

void	key_s(t_game *game)
{
	float	x;
	float	y;
	
	game->move_mini.y -= 12.0 / 5.3333;
	game->pos_real_p1.y += 12;
	x = game->pos_real_p1.x;
	y = game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x) / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][((int)x + 32) / 32] == '1'
			|| game->map[((int)y) / 32][((int)x + 32) / 32] == '1')
	{
		game->pos_real_p1.y -= 12;
		game->move_mini.y += 12.0 / 5.3333;
	}
	printf("S\n");
}

void	key_d(t_game *game)
{
	float	x;
	float	y;
	
	game->move_mini.x -= 12.0 / 5.3333;
	game->pos_real_p1.x += 12;
	x = game->pos_real_p1.x;
	y = game->pos_real_p1.y;
	if (game->map[(int)y / 32][((int)x + 32) / 32] == '1'
			|| game->map[(int)y / 32][(int)x / 32] == '1'
			|| game->map[((int)y + 32) / 32][((int)x + 32) / 32] == '1'
			|| game->map[((int)y + 32) / 32][(int)x / 32] == '1')
	{
		game->pos_real_p1.x -= 12;
		game->move_mini.x += 12.0 / 5.3333;
	}
	printf("D\n");
}

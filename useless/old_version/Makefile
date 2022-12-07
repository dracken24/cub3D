# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 16:09:57 by nadesjar          #+#    #+#              #
#    Updated: 2022/10/01 17:50:53 by nadesjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIGHT_RED		= $(shell tput -Txterm setaf 1)
LIGHT_GREEN		= $(shell tput -Txterm setaf 2)
LIGHT_BROWN		= $(shell tput -Txterm setaf 3)
CYAN			= $(shell tput -Txterm setaf 4)
LILAS			= $(shell tput -Txterm setaf 5)
LIGHT_CYAN		= $(shell tput -Txterm setaf 6)
WHITE			= $(shell tput -Txterm setaf 7)
RESET			= "\033[0m"

PATH_OBJS 		= ./objs/
PATH_SRC		= ./src/
PATH_GNL    	= ./src/get_next_line/
PATH_UTILS  	= ./src/utils/
PATH_KILL		= ./src/kill/
PATH_INIT		= ./src/init/
PATH_MOVE		= ./src/move/
PATH_DRAW		= ./src/draw/
PATH_RAY		= ./src/ray/

FILES 			= $(PATH_SRC)cube3d.c \
				$(PATH_UTILS)utils.c \
				$(PATH_UTILS)check_entry.c $(PATH_UTILS)check_boarder.c \
				$(PATH_KILL)kill_game.c \
				$(PATH_INIT)init_imgs.c $(PATH_INIT)init_var.c \
				$(PATH_DRAW)draw_grid.c $(PATH_DRAW)draw_env.c \
				$(PATH_DRAW)draw_raycast.c $(PATH_DRAW)draw_3d.c \
				$(PATH_MOVE)key_pressed.c $(PATH_MOVE)mouse.c \
				$(PATH_MOVE)key_press_suite.c \
				$(PATH_RAY)raycast.c \
				$(PATH_GNL)gnl.c $(PATH_GNL)gnl_utils.c \

OBJS 			= $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC 				= gcc

CFLAGS 			= -Wall -Werror -Wextra
MLXFLAG_MAC 	= -framework OpenGl -framework Cocoa
MLXFLAG_LINUX	= -lbsd -lXext -lX11 -lm

LIBS			= make_lib
MLX_LIB_LINUX	= minilibx/mlx-linux/libmlx.a
MLX_LIB_MAC		= minilibx/opengl/libmlx.a
LIBFT_A			= src/libft/libft.a

NAME 			= cub_3D

all: $(LIBS) $(NAME)

$(NAME): msg_in $(OBJS) msg_out
	@cp $(MLX_LIB_LINUX) $(NAME)
	@gcc $(NAME) $(OBJS) $(MLX_LIB_LINUX) $(LIBFT_A) $(CFLAGS) $(MLXFLAG_LINUX) -o cub3D
	@./cub3D maps/test_02.cub

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)get_next_line
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)kill
	@mkdir -p $(PATH_OBJS)init
	@mkdir -p $(PATH_OBJS)draw
	@mkdir -p $(PATH_OBJS)move
	@mkdir -p $(PATH_OBJS)ray
	@mkdir -p $(PATH_OBJS)libft
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(LIGHT_GREEN)■"

make_lib:
	@$(MAKE) -C ./src/libft
# @$(MAKE) -C ./minilibx//mlx-linux

msg_in:
	@echo $(LILAS)"COMPILATION DE Cub_3D EN COURS..."$(RESET)

msg_out:
	@echo $(LILAS)"\nCUBE READY !!!"$(RESET)

clean:
	@rm -fr ./objs/
	rm -f cub3D
	@$(MAKE) fclean -C ./src/libft
	@echo $(LIGHT_GREEN)"BYE BYE"$(RESET)

fclean: clean
	@rm -f $(NAME) $(LIBFT_A)

re:	fclean all

.PHONY: all make_lib push clean fclean re

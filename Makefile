# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squiquem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 19:01:27 by squiquem          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2018/12/03 15:48:57 by qsebasti         ###   ########.fr        #
=======
#    Updated: 2018/11/29 14:59:02 by sderet           ###   ########.fr        #
>>>>>>> 9bb6ef917ac07142ede3f5b0bd805df97aba3b8d
#                                                                              #
# **************************************************************************** #

.PHONY			:	all clean fclean re opti

NAME			=	RT

SRC_DIR			=	sources

OBJ_DIR			=	objects

CPPFLAGS 		=	-I includes/

<<<<<<< HEAD
SRC_FILES		=	main.c \
					handle/keyhook.c \
					handle/mousehook.c \
					handle/move.c \
					hud/cursor.c \
					hud/draw_color.c \
					hud/general_ui.c \
					hud/hud.c \
					hud/new_image.c \
					hud/ui1.c \
					maths/rotate.c \
					maths/vec.c \
					maths/vec2.c \
					parser/error.c \
					parser/get_position.c \
					parser/get_value_mat.c \
					parser/get_value_obj.c \
					parser/get_value_obj2.c \
					parser/parser.c \
					parser/parser_all.c \
					parser/recup_camera.c \
					parser/recup_env.c \
					parser/recup_light.c \
					parser/recup_mat.c \
					parser/recup_object.c \
					parser/recup_object2.c \
					parser/recup_object3.c \
					parser/recursive_element.c \
					parser/recursive_elem2.c \
					parser/set_zero_mat.c \
					render/checker.c \
					render/draw.c \
					render/color.c \
					render/fct_to_add.c \
					render/find_closest.c \
					render/find_normal.c \
					render/fresnel.c \
					render/hit_disk.c \
					render/hit_func.c \
					render/hit_items.c \
					render/light.c \
					render/marble.c \
					render/new.c \
					render/noise.c \
					render/ray.c \
					render/shadow.c \
					render/tab.c \
					render/textures_util.c \
					render/textures.c

SUB_FOLDERS		=	parser render hud handle maths

BUILD_DIR		=	$(addprefix $(OBJ_DIR)/,$(SUB_FOLDERS))
=======
SRC_FILES		=	color.c \
					display1.c \
					draw.c \
					error.c \
					fct_to_add.c \
					find_closest.c \
					find_normal.c \
					ft_draw.c \
					fresnel.c \
					get_position.c \
					get_value_mat.c \
					get_value_obj.c \
					get_value_obj2.c \
					hit_disk.c \
					hit_func.c \
					hit_items.c \
					hud.c \
					keyhook.c \
					light.c \
					main.c \
					mousehook.c \
					move.c \
					new.c \
					new_image.c \
					parser.c \
					parser_all.c \
					ray.c \
					recup_camera.c \
					recup_env.c \
					recup_light.c \
					recup_mat.c \
					recup_object.c \
					recup_object2.c \
					recup_object3.c \
					recursive_element.c \
					recursive_elem2.c \
					rotate.c \
					tab.c \
					textures_util.c \
					textures.c \
					checker.c \
					noise.c \
					marble.c \
					vec.c \
					vec2.c
>>>>>>> 9bb6ef917ac07142ede3f5b0bd805df97aba3b8d

OBJ_FILES		=	$(SRC_FILES:.c=.o)

OBJ_D_FILES		=	$(SRC_FILES:.c=.d)

SRC				=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ				=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

OBJ_D			=	$(addprefix $(OBJ_DIR)/, $(OBJ_D_FILES))

LFT				=	-L libft/ -lft

MLX				=	-L minilibx/ -lmlx -framework OpenGL -framework AppKit

LIBFT			=	libft/libft.a

LIBMLX			=	minilibx/libmlx.a

CC				=	gcc

<<<<<<< HEAD
CFLAGS			=	-Wall -Wextra -Werror -g -O2 -MMD
=======
CFLAGS			=	-Wall -Wextra -Werror -g
>>>>>>> 9bb6ef917ac07142ede3f5b0bd805df97aba3b8d

opti			:
	@make -j8 all

all				:	objects
	@make all -C libft/
	@make all -C minilibx/
	@make $(NAME)

objects			:	$(BUILD_DIR)

$(BUILD_DIR)	:
	@mkdir -p $@

$(NAME)			:	$(OBJ)
	@$(CC) $(CFLAGS) $(LFT) $(MLX) $(OBJ) -o $@ 
	@printf '\033[4m'
	@printf "\033[32m[ ✔ ] $(NAME)\n\033[0m"
	@touch .gitignore
	@echo $(NAME) > .gitignore

<<<<<<< HEAD
$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c $(LIBFT) $(LIBMLX)
=======
$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c $(LIBFT) $(LIBMLX)
>>>>>>> 9bb6ef917ac07142ede3f5b0bd805df97aba3b8d
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean			:
	@make clean -C libft/
	@make clean -C minilibx/
	@rm -f $(OBJ)
	@rm -f $(OBJ_D)
	@rm -rf $(OBJ_DIR) 2> /dev/null || true
	@printf '\033[4m'
	@echo "\033[31m$(NAME):\033[0m"
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Object Files"

fclean			:	clean
	@rm -f $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Binary File"

re				:
	@make fclean
	@make opti

-include $(OBJ_D)

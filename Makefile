# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squiquem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 19:01:27 by squiquem          #+#    #+#              #
#    Updated: 2018/12/21 16:03:55 by sderet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY			:	all clean fclean re opti

NAME			=	RT

SRC_DIR			=	sources

OBJ_DIR			=	objects

CPPFLAGS 		=	-I includes/

SRC_FILES		=	main.c \
					handle/keyhook.c \
					handle/mousehook.c \
					handle/move.c \
					handle/ui1_zone.c \
					hud/cursor.c \
					hud/general_ui.c \
					hud/hud.c \
					hud/init_hud.c \
					hud/loading.c \
					hud/new_image.c \
					hud/pick_item.c \
					hud/reset_ui.c \
					hud/ruler.c \
					hud/shade_bar.c \
					hud/shape.c \
					hud/ui1.c \
					hud/ui1_bottom.c \
					hud/ui2.c \
					hud/ui2_bottom.c \
					hud/util.c \
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
					parser/get_value_obj3.c \
					render/aliasing.c \
					render/cartoon.c \
					render/checker.c \
					render/color.c \
					render/fct_to_add.c \
					render/filters.c \
					render/find_closest.c \
					render/find_normal.c \
					render/fresnel.c \
					render/hit_disk.c \
					render/hit_func.c \
					render/hit_items.c \
					render/hsv.c \
					render/light.c \
					render/marble.c \
					render/new.c \
					render/noise.c \
					render/pixel.c \
					render/quadric.c \
					render/ray.c \
					render/shadow.c \
					render/tab.c \
					render/textures_util.c \
					render/textures.c \
					render/threads.c \

SUB_FOLDERS		=	parser render hud handle maths

BUILD_DIR		=	$(addprefix $(OBJ_DIR)/,$(SUB_FOLDERS))

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

CFLAGS			=	-Wall -Wextra -Werror -g -O2 -MMD

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

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c $(LIBFT) $(LIBMLX)
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

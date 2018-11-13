# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squiquem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 19:01:27 by squiquem          #+#    #+#              #
#    Updated: 2018/11/13 17:15:42 by sderet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY			:	all clean fclean re opti

NAME			=	RT

SRC_DIR			=	./sources/

OBJ_DIR			=	./objects/

CPPFLAGS 		=	-I includes/

SRC_FILES		=	color.c \
					draw.c \
					fct_to_add.c \
					find_closest.c \
					find_normal.c \
					fresnel.c \
					hit_disk.c \
					hit_func.c \
					hit_items.c \
					keyhook.c \
					light.c \
					main.c \
					mousehook.c \
					move.c \
					new.c \
					parsing.c \
					parsing2.c \
					parsing_items.c \
					ray.c \
					rotate.c \
					vec.c \
					vec2.c \
					parser_all.c \
					error.c \
					get_position.c \
					get_value_obj.c \
					get_value_obj2.c \
					parser.c \
					recup_camera.c \
					recup_env.c \
					recup_light.c \
					recup_mat.c \
					recup_object.c \
					recup_object2.c \
					recup_object3.c \
					recursive_element.c \
					recursive_elem2.c \
					tab.c \
					textures.c

OBJ_FILES		=	$(SRC_FILES:.c=.o)

OBJ_D_FILES		=	$(SRC_FILES:.c=.d)

SRC				=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ				=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

OBJ_D			=	$(addprefix $(OBJ_DIR), $(OBJ_D_FILES))

LFT				=	-L libft/ -lft

MLX				=	-L minilibx/ -lmlx -framework OpenGL -framework AppKit

LIBFT			=	libft/libft.a

LIBMLX			=	minilibx/libmlx.a

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g

opti			:
	@make -j8 all

all				:
	@make all -C libft/
	@make all -C minilibx/
	@make $(NAME)

$(NAME)			:	$(OBJ)
	@$(CC) $(CFLAGS) $(LFT) $(MLX) $(OBJ) -o $@ 
	@printf '\033[4m'
	@printf "\033[32m[ ✔ ] $(NAME)\n\033[0m"
	@touch .gitignore
	@echo $(NAME) > .gitignore

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c $(LIBFT) $(LIBMLX)
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

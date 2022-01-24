# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: choney <choney@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:41:33 by choney            #+#    #+#              #
#    Updated: 2022/01/23 20:45:20 by choney           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIB		=	libft.a

HEADER_NAME		=	cub3d.h
NAME_CUB			=	cub3D

INC_DIR			=	./includes/
INC_LIB			=	./libft/
SRC_DIR			=	./srcs/
OBJ_DIR			=	./obj/

SRC_NAME_CUB	=	calculation.c get_next_line_utils.c parsing.c sprites_render.c clear_game.c key_manager.c parsing_init.c textures.c drawing.c main.c ray_casting.c utils.c fill.c map_check.c split_whitespaces.c utils2.c get_next_line.c map_parsing.c sprites_calc.c what_id.c move.c

HEADER			=	$(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_CUB			=	$(addprefix $(SRC_DIR), $(SRC_NAME_CUB))
OBJ_CUB			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_CUB:.c=.o))

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -g
FLAGSMLX		=	-lmlx -framework OpenGL -framework AppKit
GCC_LIBFT		=	-L ./libft/ -l ft

all: $(NAME_CUB)

$(NAME_CUB): $(OBJ_DIR) $(OBJ_CUB) $(NAME_LIB) $(HEADER)
	@$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_CUB) $(FLAGSMLX) libmlx.dylib -o $(NAME_CUB)

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) -I $(INC_LIB_FT) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME_CUB)
	@make fclean -C libft/

re: fclean all
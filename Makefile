# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khle <khle@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 07:35:00 by khle              #+#    #+#              #
#    Updated: 2023/03/23 07:21:09 by khle             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror -MMD

NAME = so_long

MLX_DIR = mlx

MLX_LIB = mlx_Linux

HEADER += inc/so_long.h

#******************************************************************************#
#*									PARSING	  								  *#
#******************************************************************************#

SRC += Src/Parsing/check_map1.c
SRC += Src/Parsing/check_map2.c
SRC += Src/Parsing/check_path1.c
SRC += Src/Parsing/check_path2.c
SRC += Src/main.c

#******************************************************************************#
#*									GAME	  								  *#
#******************************************************************************#

SRC += Src/Game/game.c
SRC += Src/Game/init.c
SRC += Src/Game/move_down.c
SRC += Src/Game/move_up.c
SRC += Src/Game/move_left.c
SRC += Src/Game/move_right.c
SRC += Src/Game/move.c

#******************************************************************************#
#*									ERRORS  								  *#
#******************************************************************************#

SRC += Error/destroy_mlx.c
SRC += Error/Error_message.c

#******************************************************************************#
#*									UTILS	  								  *#
#******************************************************************************#

SRC += Src/utils/ft_putnbr.c
SRC += Src/utils/ft_split.c
SRC += Src/utils/ft_strdup.c
SRC += Src/utils/ft_len_tab.c
SRC += Src/utils/ft_putstr.c
SRC += Src/utils/ft_strstr.c
SRC += Src/utils/get_next_line/get_next_line.c
SRC += Src/utils/get_next_line/get_next_line_utils.c




OBJ = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)

$(NAME): $(OBJ) $(HEADER)
		$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I mlx -Lmlx -lmlx -lm -lXext -lX11 -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(MLX_DIR) -o $@ -c $< 

NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m
YELLOW		= \033[0;33m
BACK_WHITE  = \033[0;47;30m

all: $(NAME) header

clean:
	rm -rf $(OBJ)
	rm -rf $(DEPS)
	$(MAKE) clean -C $(MLX_DIR)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

header:
	clear
	@echo " $(CYAN) $$HEADER_PROJECT $(NOC)" 

-include $(OBJ:.o=.d)

.PHONY: all clean fclean re

define HEADER_PROJECT                                                                       

                    888                            
 dP"Y  e88 88e      888  e88 88e  888 8e   e88 888 
C88b  d888 888b     888 d888 888b 888 88b d888 888 
 Y88D Y888 888P     888 Y888 888P 888 888 Y888 888 
d,dP   "88 88"      888  "88 88"  888 888  "88 888 
                888                         ,  88P 
                                           "8",P"  
                                                     
endef
export HEADER_PROJECT
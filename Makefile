# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 13:45:45 by llee              #+#    #+#              #
#    Updated: 2018/12/19 13:04:40 by llee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of executable
NAME = fdf

# compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# sources, objects, and header
SRCS = ./srcs/main.c ./srcs/init.c ./srcs/clean.c ./srcs/read.c ./srcs/map.c ./srcs/render.c ./srcs/window.c ./srcs/keyboard.c ./srcs/color.c
OBJS = ./objs/main.o ./objs/init.o ./objs/clean.o ./objs/read.o ./objs/map.o ./objs/render.o ./objs/window.o ./objs/keyboard.o ./objs/color.o
SRCDIR = ./srcs/
OBJDIR = ./objs/
INCDIR = ./includes/

# libft library
LIBFT = ./libft/
LIBFT_L = -L./libft -l ft
LIBFT_I = -I./libft/libft.h

# minilibx library
MLX = ./minilibx/
MLX_L = -L./minilibx -l mlx -framework OpenGL -framework AppKit
MLX_I = -I./minilibx/mlx.h

all: obj $(LIBFT_L) $(MLX_L) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) $(LIBFT_I) $(MLX_I) -I $(INCDIR) -o $@ -c $<

$(LIBFT_L):
	make -C $(LIBFT)
	make clean -C $(LIBFT)

$(MLX_L):
	make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT_L) $(MLX_L) $(SRCS)

clean: 
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)
	make clean -C $(MLX)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re lite

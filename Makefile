# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 21:18:17 by mmaila            #+#    #+#              #
#    Updated: 2023/12/15 17:18:48 by mmaila           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
FLAGS= -Wall -Werror -Wextra
OBJ= game.o draw.o exit.o map.o positions.o events.o validate_map.o srcs/printf/ft_printf.o srcs/printf/ft_prints.o srcs/printf/ft_putchar.o \
	 srcs/printf/ft_putnbr.o srcs/printf/ft_putnbr_base.o srcs/printf/ft_putnbr_u.o srcs/printf/ft_putstr.o \
	 srcs/get_next_line/get_next_line.o srcs/get_next_line/get_next_line_utils.o srcs/libft/del.o srcs/libft/ft_lstadd_back.o \
	 srcs/libft/ft_lstclear.o srcs/libft/ft_lstdelone.o srcs/libft/ft_strcmp.o srcs/libft/ft_itoa.o srcs/libft/ft_strcat.o srcs/libft/ft_strcpy.o
NAME=so_long

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o : %.c Includes/so_long.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

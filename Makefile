# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 21:18:17 by mmaila            #+#    #+#              #
#    Updated: 2023/12/17 15:11:42 by mmaila           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
FLAGS= -Wall -Werror -Wextra

OBJ= game.o draw.o exit.o map.o positions.o events.o validate_map.o validate_path.o

SRCS= srcs/printf/ft_printf.o srcs/printf/ft_prints.o srcs/printf/ft_putchar.o \
	 srcs/printf/ft_putnbr.o srcs/printf/ft_putnbr_base.o srcs/printf/ft_putnbr_u.o srcs/printf/ft_putstr.o \
	 srcs/get_next_line/get_next_line.o srcs/get_next_line/get_next_line_utils.o \
	 srcs/libft/ft_strcmp.o srcs/libft/ft_itoa.o srcs/libft/ft_strcat.o srcs/libft/ft_strcpy.o

BONUS_SRCS= so_long_bonus/game_bonus.c so_long_bonus/draw_bonus.c so_long_bonus/exit_bonus.c so_long_bonus/map_bonus.c \
	 so_long_bonus/positions_bonus.c so_long_bonus/events_bonus.c so_long_bonus/validate_map_bonus.c so_long_bonus/validate_path_bonus.c

BONUSOBJ= $(BONUS_SRCS:.c=.o)

NAME=so_long
NAMEBONUS=so_long_bonus

all : $(NAME)

bonus : $(NAMEBONUS)

$(NAME) : $(OBJ) $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAMEBONUS) :  $(SRCS) $(BONUSOBJ)
	$(CC) $(FLAGS) $(SRCS) $(BONUSOBJ) -lmlx -framework OpenGL -framework AppKit -o so_long_bonus/$(NAMEBONUS)

%.o : %.c Includes/so_long.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ) $(BONUSOBJ) $(SRCS)

fclean : clean
	rm -rf $(NAME) so_long_bonus/$(NAMEBONUS)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 16:50:44 by mkaoukin          #+#    #+#              #
#    Updated: 2024/02/27 16:16:26 by mkaoukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAMEB = so_long_bonus

CC = CC

FLAGS = -Wall -Wextra -Werror -Imlx

SRC =	ft_split.c\
		parsing.c\
		get_next_line_utils.c\
		get_next_line.c\
		so_long.c\
		function_par.c\
		graphique.c\
		move.c\
		ft_putnbr.c

SRCB = 	ft_split.c\
		parsing_bonus.c\
		get_next_line_utils.c\
		get_next_line.c\
		so_long_bonus.c\
		function_par_bonus.c\
		graphique_bonus.c\
		move_bonus.c\
		ft_itoa.c\
		ft_putnbr.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

INCLUDE = so_long.h


$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAMEB) : $(OBJB)
	$(CC) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(NAMEB)

%.o : %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

bonus : $(NAMEB)

clean :
	rm -rf $(OBJ) $(OBJB)

fclean : clean
	rm -rf $(NAME) $(NAMEB)

re : fclean all

.PHONY : clean
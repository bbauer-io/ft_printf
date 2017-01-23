# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 16:20:35 by bbauer            #+#    #+#              #
#    Updated: 2017/01/22 18:02:06 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_printf.a
CC = gcc
SRC =  ft_printf.c ft_vprintf.c
OPT = $(SRC:.c=.o)
HEADER = ./ft_printf.h ./libft/libft.h
LIBFT = ./libft/libft.a
OPTIONS = -c
FLAGS = -Wall -Wextra -Werror
TESTMAIN = ./tests/main.c
TESTOPTIONS = -g

all: $(NAME)

$(NAME):
	$(CC) $(OPTIONS) $(SRC) $(HEADER) $(FLAGS)
	ar rc $(NAME) $(OPT) $(LIBFT)
	ranlib $(NAME)

test:
	$(CC) $(SRC) $(HEADER) $(TESTMAIN) $(FLAGS) $(LIBFT) $(TESTOPTIONS)

clean:
	/bin/rm -f $(OPT) main.o
	/bin/rm -f ft_printf.h.gch
	/bin/rm -rf a.out.dSYM

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f a.out

re: fclean all

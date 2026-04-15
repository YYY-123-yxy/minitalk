# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ziyang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 18:23:55 by ziyang            #+#    #+#              #
#    Updated: 2025/12/25 17:11:13 by ziyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_format.c ft_putchar.c ft_putnbr.c ft_putptr.c \
      ft_putstr.c ft_puthexa_lower.c ft_puthexa_upper.c ft_putunsigned_u.c

OBJ = $(SRC:.c=.o)

INCLUD = -I ./

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $(INCLUD) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

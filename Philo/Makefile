# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 10:47:02 by ilahyani          #+#    #+#              #
#    Updated: 2022/05/22 11:04:45 by ilahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	philo.c utiles.c

OBJ	=	$(SRC:.c=.o)

NAME	=	philo

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -pthread -g

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^

#temp wildcard

clean:	
		rm -rf *.o

fclean:		clean
			rm -rf $(NAME)

re:	fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 10:47:02 by ilahyani          #+#    #+#              #
#    Updated: 2022/05/27 17:25:57 by ilahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c utiles.c utiles_2.c get_args.c kill_thread.c philo_create.c routine.c

OBJ	=	$(SRC:.c=.o)

NAME	=	philo

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -pthread

all:	$(NAME)

HDR		=	./philo.h

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HDR)
		$(CC) $(CFLAGS) -c $< -o $@
			
clean:	
		rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:	fclean all
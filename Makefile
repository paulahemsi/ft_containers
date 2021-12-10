# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:38:38 by phemsi-a          #+#    #+#              #
#    Updated: 2021/12/04 18:41:22 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
TEST = test

SRC =	main.cpp

OBJS =	main.o

CC	= c++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

$(TEST):	$(OBJS)
			$(CC) $(CFLAGS) -o $(TEST) $(OBJS)

$(OBJS):	$(SRC)
			$(CC) $(CFLAGS) -c $(SRC)

all:		$(TEST)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(TEST)
			$(RM) $(OBJS)

re:			fclean all

PHONY:		all clean fclean re

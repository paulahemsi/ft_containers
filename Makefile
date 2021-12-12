# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:38:38 by phemsi-a          #+#    #+#              #
#    Updated: 2021/12/12 00:10:18 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft.out
ORGINAL = original

SRC =	main.cpp

FT_SRC =	ft_main.cpp


OBJS =	main.o

FT_OBJS =	ft_main.o

CC	= c++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

$(NAME):	$(FT_OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(FT_OBJS)

$(ORGINAL):	$(OBJS)
			$(CC) $(CFLAGS) -o $(ORGINAL) $(OBJS)

$(OBJS):	$(SRC)
			$(CC) $(CFLAGS) -c $(SRC)

$(FT_OBJS):	$(FT_SRC)
			$(CC) $(CFLAGS) -c $(FT_SRC)

all:		$(TEST)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(TEST)
			$(RM) $(OBJS)
			$(RM) $(NAME)
			$(RM) $(FT_OBJS)

re:			fclean all

PHONY:		all clean fclean re

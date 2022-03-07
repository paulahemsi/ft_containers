# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:38:38 by phemsi-a          #+#    #+#              #
#    Updated: 2022/03/06 23:26:55 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../containers.mk
include srcs.mk

NAME	:= ft.out
ORGINAL	:= original

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -g
CFLAGS	+= -std=c++98

STD_VERSION := -D STD_VERSION

RM		:=	rm -rf

OBJ_DIR		:= ./objs/
FT_OBJ_DIR	:= ./ft_objs/
OBJS		:= $(addprefix $(OBJ_DIR), $(notdir $(SRC:.cpp=.o)))
FT_OBJS		:= $(addprefix $(FT_OBJ_DIR), $(notdir $(SRC:.cpp=.o)))

$(OBJ_DIR)%.o:	%.cpp $(TEMPLATES) $(HEADER)
				$(CC) $(STD_VERSION) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_OBJ_DIR)%.o:	%.cpp $(TEMPLATES) $(HEADER)
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(FT_OBJS) 
			$(CC) $(CFLAGS) $^ -o $@ 

$(ORGINAL):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

$(FT_OBJS): | $(FT_OBJ_DIR)

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
			mkdir $(OBJ_DIR)

$(FT_OBJ_DIR):
			mkdir $(FT_OBJ_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJ_DIR)
			$(RM) $(FT_OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(ORGINAL)

re:			fclean all

test:
		make map_script -C $(ROOT)

PHONY:		all clean fclean re test

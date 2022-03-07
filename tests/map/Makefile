# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:38:38 by phemsi-a          #+#    #+#              #
#    Updated: 2022/03/06 15:46:04 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= ft.out
ORGINAL	:= original

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -g
CFLAGS	+= -std=c++98

STD_VERSION := -D STD_VERSION

RM		:=	rm -rf

ROOT		:=	../../

TEST_DIR	:=	./

SUB_DIR	:=	
#SUB_DIR	:=	$(addprefix $(TEST_DIR), $(SUB_DIR))

SRC	:=	main.cpp\
		pair.cpp\
		auxiliary.cpp

HEADER	:=	

CONTAINERS_DIR	:=	$(ROOT)containers/
CONTAINERS		:=	Vector.hpp

ITERATORS_DIR	:=	$(ROOT)iterators/
ITERATORS		:=	bidirectional_iterator.hpp\
					random_access_iterator.hpp\
					iterators_traits.hpp\
					reverse_iterator.hpp

AUX_TEMPLATES_DIR	:=	$(ROOT)aux_templates/
AUX_TEMPLATES		:=	lexicographical_compare.tpp\
						type_traits.tpp 

TEMPLATES_DIR	:= $(CONTAINERS_DIR) $(ITERATORS_DIR) $(AUX_TEMPLATES_DIR) 
TEMPLATES		:= $(CONTAINERS) $(ITERATORS) $(AUX_TEMPLATES)

VPATH	:=	$(TEST_DIR)\
			$(TEMPLATES_DIR)\
			$(SUB_DIR)

OBJ_DIR		:= ./objs/
FT_OBJ_DIR	:= ./ft_objs/
OBJS		:= $(addprefix $(OBJ_DIR), $(notdir $(SRC:.cpp=.o)))
FT_OBJS		:= $(addprefix $(FT_OBJ_DIR), $(notdir $(SRC:.cpp=.o)))

INCLUDES	:= $(addprefix -I, $(TEMPLATES_DIR) $(TEST_DIR))

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

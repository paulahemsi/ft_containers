# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:38:38 by phemsi-a          #+#    #+#              #
#    Updated: 2022/02/23 11:17:55 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= ft.out
ORGINAL	:= original

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -g
CFLAGS	+= -std=c++98

RM		:= rm -rf

TESTDIR		:=	./tests/

VECTORTESTDIR	:=	member_functions/
VECTORTESTDIR	:=	$(addprefix $(TESTDIR), $(VECTORTESTDIR))

SRC		:=	main.cpp
FT_SRC	:=	ft_main.cpp\
			constructors.cpp\
			simple_assignment_operator.cpp\
			auxiliary.cpp\
			iterators.cpp\
			out_of_bounds.cpp\
			relational_operators.cpp\
			empty.cpp\
			assign.cpp\
			clear.cpp\
			data.cpp\
			erase.cpp\
			insert.cpp\
			swap.cpp\
			resize.cpp\
			reserve.cpp\
			get_allocator.cpp\
			element_access.cpp\
			push_back.cpp\
			pop_back.cpp

HEADER	:=	tests.hpp

CONTAINERSDIR	:=	./containers/
CONTAINERS		:=	Vector.hpp

ITERATORSDIR	:=	./iterators/
ITERATORS		:=	bidirectional_iterator.hpp\
					random_access_iterator.hpp\
					iterators_traits.hpp\
					reverse_iterator.hpp

AUXTEMPLATESDIR	:=	./aux_templates/
AUXTEMPLATES	:=	lexicographical_compare.tpp\
				type_traits.hpp 

TEMPLATES		:= $(CONTAINERS) $(ITERATORS) $(AUXTEMPLATES)
TEMPLATESDIR	:= $(CONTAINERSDIR) $(ITERATORSDIR) $(AUXTEMPLATESDIR) 

VPATH	:=	$(TESTDIR)\
			$(TEMPLATESDIR)\
			$(VECTORTESTDIR)

OBJDIR		:= ./objs/
OBJS		:= $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))
FT_OBJS		:= $(addprefix $(OBJDIR), $(notdir $(FT_SRC:.cpp=.o)))

INCLUDES	:= $(addprefix -I, $(TEMPLATESDIR) $(TESTDIR))

$(OBJDIR)%.o:	%.cpp $(TEMPLATES) $(HEADER)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(FT_OBJS) 
			$(CC) $(CFLAGS) -o $@ $(FT_OBJS)

$(ORGINAL):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $(OBJS)

$(FT_OBJS): | $(OBJDIR)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
			mkdir $(OBJDIR)

all:		$(NAME)

clean:
			$(RM) $(OBJDIR)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(ORGINAL)

re:			fclean all

PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:38:38 by phemsi-a          #+#    #+#              #
#    Updated: 2022/03/01 10:13:41 by lfrasson         ###   ########.fr        #
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
TESTER	:=	bash tester.sh

LOGSDIR		:=	./logs/
TESTDIR		:=	./tests/

VECTORTESTDIR	:=	member_functions/\
					non-member_functions/\
					iterators/
VECTORTESTDIR	:=	$(addprefix $(TESTDIR), $(VECTORTESTDIR))

SRC	:=	ft_main.cpp\
		constructors.cpp\
		simple_assignment_operator.cpp\
		auxiliary.cpp\
		iterators.cpp\
		const_iterators.cpp\
		reverse_iterators.cpp\
		aux_iterators.cpp\
		aux_reverse_iterators.cpp\
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

HEADER	:=	tests.hpp\
			comparison.hpp\
			swap.tpp\
			iterators.hpp\
			reverse_iterators.tpp\
			iterators.tpp

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
FT_OBJDIR	:= ./ft_objs/
OBJS		:= $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))
FT_OBJS		:= $(addprefix $(FT_OBJDIR), $(notdir $(SRC:.cpp=.o)))

INCLUDES	:= $(addprefix -I, $(TEMPLATESDIR) $(TESTDIR))

$(OBJDIR)%.o:	%.cpp $(TEMPLATES) $(HEADER)
				$(CC) $(STD_VERSION) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_OBJDIR)%.o:	%.cpp $(TEMPLATES) $(HEADER)
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(FT_OBJS) 
			$(CC) $(CFLAGS) -o $@ $(FT_OBJS)

$(ORGINAL):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $(OBJS)

$(FT_OBJS): | $(FT_OBJDIR)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
			mkdir $(OBJDIR)

$(FT_OBJDIR):
			mkdir $(FT_OBJDIR)

all:		$(NAME)

test:
		$(TESTER)

clean:
			$(RM) $(OBJDIR)
			$(RM) $(FT_OBJDIR)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(ORGINAL)
			$(RM) $(LOGSDIR)

re:			fclean all

PHONY:		all clean fclean re test

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vector_srcs.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 18:39:11 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/19 20:57:23 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK_DIR	:=	../mk/

include $(MK_DIR)auxiliary.mk

TEST_DIR	:=	./

SUB_DIR		:=	member_functions/\
				non-member_functions/\
				iterators/
SUB_DIR		:=	$(addprefix $(TEST_DIR), $(SUB_DIR))

SRC			+=	ft_main.cpp\
				constructors.cpp\
				simple_assignment_operator.cpp\
				utils.cpp\
				iterators.cpp\
				const_iterators.cpp\
				reverse_iterators.cpp\
				const_reverse_iterators.cpp\
				aux_iterators.cpp\
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

HEADER		+=	tests.hpp\
				comparison.hpp\
				swap.tpp\
				iterators.hpp\
				reverse_iterators.tpp\
				iterators.tpp

INCLUDES	+= $(addprefix -I, $(TEST_DIR))

VPATH		+=	$(TEST_DIR)\
				$(SUB_DIR)

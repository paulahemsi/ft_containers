# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    set_srcs.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 15:15:01 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/15 17:17:00 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK_DIR	:=	../mk/

include $(MK_DIR)auxiliary.mk

TEST_DIR	:=	./

SRC			+=	main.cpp\
				assigment_operator.cpp\
				constructors.cpp\
				count.cpp\
				empty.cpp\
				equal_range.cpp\
				utils.cpp\
				erase.cpp\
				find.cpp\
				get_allocator.cpp\
				insert.cpp\
				iterator.cpp\
				less-than_comparison.cpp\
				lower_bound.cpp\
				max_size.cpp\
				size.cpp\
				swap.cpp\
				upper_bound.cpp\
				value_comp.cpp\
				equality_operator.cpp

INCLUDES	+=	$(addprefix -I, $(TEST_DIR))

HEADER		+=	tests.hpp

VPATH		+=	$(TEST_DIR)\
				$(SUB_DIR)

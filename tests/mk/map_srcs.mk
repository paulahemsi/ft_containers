# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    map_srcs.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 18:39:11 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/14 21:04:24 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK_DIR	:=	../mk/

include $(MK_DIR)auxiliary.mk

TEST_DIR	:=	./

# SUB_DIR	:=	
# SUB_DIR	:=	$(addprefix $(TEST_DIR), $(SUB_DIR))

SRC			+=	main.cpp\
				utils.cpp\
				pair.cpp\
				find.cpp\
				get_allocator.cpp\
				insert.cpp\
				erase.cpp\
				access_operator.cpp\
				size.cpp\
				lower_bound.cpp\
				upper_bound.cpp\
				equal_range.cpp\
				count.cpp\
				constructors.cpp\
				assigment_operator.cpp\
				empty.cpp\
				value_comp.cpp\
				max_size.cpp\
				swap.cpp\
				equality_operator.cpp\
				less-than_comparison.cpp

# HEADER	+=	

INCLUDES	+= $(addprefix -I, $(TEST_DIR))

VPATH		+=	$(TEST_DIR)\
				$(SUB_DIR)

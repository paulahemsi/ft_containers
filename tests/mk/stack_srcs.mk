# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stack_srcs.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 22:30:30 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/15 12:01:04 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK_DIR	:=	../mk/

include $(MK_DIR)auxiliary.mk

TEST_DIR	:=	./

SRC			+=	main.cpp\
				canonical.cpp\
				size.cpp\
				pop.cpp\
				push.cpp\
				top.cpp

INCLUDES	+=	$(addprefix -I, $(TEST_DIR))

HEADER		+=	tests.hpp

VPATH		+=	$(TEST_DIR)\
				$(SUB_DIR)

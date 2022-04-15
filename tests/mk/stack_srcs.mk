# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stack_srcs.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 22:30:30 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/15 11:45:47 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK_DIR	:=	../mk/

include $(MK_DIR)auxiliary.mk

TEST_DIR	:=	./

SRC			+=	main.cpp\
				canonical.cpp\
				size.cpp\
				push.cpp

INCLUDES	+=	$(addprefix -I, $(TEST_DIR))

HEADER		+=	tests.hpp

VPATH		+=	$(TEST_DIR)\
				$(SUB_DIR)

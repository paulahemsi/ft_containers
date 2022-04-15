# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    set_srcs.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 15:15:01 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/15 15:15:10 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK_DIR	:=	../mk/

include $(MK_DIR)auxiliary.mk

TEST_DIR	:=	./

SRC			+=	main.cpp\

INCLUDES	+=	$(addprefix -I, $(TEST_DIR))

HEADER		+=	tests.hpp

VPATH		+=	$(TEST_DIR)\
				$(SUB_DIR)

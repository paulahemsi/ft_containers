# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    map_srcs.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 18:39:11 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/06 23:38:21 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK_DIR	:=	../mk/

include $(MK_DIR)auxiliary.mk

TEST_DIR	:=	./

# SUB_DIR	:=	
# SUB_DIR	:=	$(addprefix $(TEST_DIR), $(SUB_DIR))

SRC			+=	main.cpp\
				pair.cpp

# HEADER	+=	

INCLUDES	+= $(addprefix -I, $(TEST_DIR))

VPATH		+=	$(TEST_DIR)\
				$(SUB_DIR)
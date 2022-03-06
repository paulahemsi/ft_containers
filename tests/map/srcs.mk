# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 18:39:11 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/06 19:02:40 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_DIR	:=	./

SUB_DIR	:=	
#SUB_DIR	:=	$(addprefix $(TEST_DIR), $(SUB_DIR))

SRC	:=	main.cpp\
		pair.cpp\
		auxiliary.cpp

HEADER	:=	

VPATH	+=	$(TEST_DIR)\
			$(SUB_DIR)

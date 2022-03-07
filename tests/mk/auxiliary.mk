# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auxiliary.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 18:39:11 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/06 19:43:59 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR			:=	../auxiliary/

SRC			+=	auxiliary.cpp

HEADER		+=	auxiliary.hpp	

INCLUDES	+=	$(addprefix -I, $(DIR))

vpath 		auxiliary.cpp $(DIR)
vpath 		auxiliary.hpp $(DIR)
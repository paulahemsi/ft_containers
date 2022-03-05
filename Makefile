# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 17:27:40 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/04 21:43:10 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		:=	rm -rf
TESTER	:=	bash tester.sh

LOGS_DIR	:=	./logs/

TESTS_DIR	:=	./tests/

VECTOR_TEST_DIR	:=	$(TESTS_DIR)vector

vector_test:
		make -C $(VECTOR_TEST_DIR)

all: vector_test

test:
		$(TESTER)
clean:
		make clean -C $(VECTOR_TEST_DIR)

fclean:	
		make fclean -C $(VECTOR_TEST_DIR)
		$(RM) $(LOGS_DIR)

re:		fclean all

PHONY:	all clean fclean re vector_test test
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 17:27:40 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/06 15:44:05 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		:=	rm -rf
TESTER	:=	bash tester.sh

LOGS_DIR	:=	./logs/

TESTS_DIR	:=	./tests/

VECTOR_TEST_DIR	:=	$(TESTS_DIR)vector
MAP_TEST_DIR	:=	$(TESTS_DIR)map

all:	vector_test map_test

vector_test:
		make -C $(VECTOR_TEST_DIR)

map_test:
		make -C $(MAP_TEST_DIR)

vector_script:
		$(TESTER) vector

map_script:
		$(TESTER) map

clean:
		make clean -C $(VECTOR_TEST_DIR)
		make clean -C $(MAP_TEST_DIR)

fclean:	
		make fclean -C $(VECTOR_TEST_DIR)
		make fclean -C $(MAP_TEST_DIR)
		$(RM) $(LOGS_DIR)

re:		fclean all

PHONY:	all clean fclean re vector_test map_test test

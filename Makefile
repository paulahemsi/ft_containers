# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 17:27:40 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/18 22:52:32 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		:=	rm -rf
TESTER	:=	bash tester.sh

LOGS_DIR	:=	./logs/

TESTS_DIR	:=	./tests/

VECTOR_TEST_DIR	:=	$(TESTS_DIR)vector
MAP_TEST_DIR	:=	$(TESTS_DIR)map
STACK_TEST_DIR	:=	$(TESTS_DIR)stack
SET_TEST_DIR	:=	$(TESTS_DIR)set
INTRA_TEST_DIR	:=	$(TESTS_DIR)intra

all:	vector_test map_test stack_test set_test intra_test

vector_test:
		make -C $(VECTOR_TEST_DIR)

map_test:
		make -C $(MAP_TEST_DIR)

stack_test:
		make -C $(STACK_TEST_DIR)

set_test:
		make -C $(SET_TEST_DIR)

intra_test:
		make -C $(INTRA_TEST_DIR)

test: vector_script map_script stack_script set_script intra_script

vector_script:
		$(TESTER) vector

map_script:
		$(TESTER) map

stack_script:
		$(TESTER) stack

set_script:
		$(TESTER) set

intra_script:
		$(TESTER) intra

clean:
		make clean -C $(VECTOR_TEST_DIR)
		make clean -C $(MAP_TEST_DIR)
		make clean -C $(STACK_TEST_DIR)
		make clean -C $(SET_TEST_DIR)
		make clean -C $(INTRA_TEST_DIR)

fclean:	
		make fclean -C $(VECTOR_TEST_DIR)
		make fclean -C $(MAP_TEST_DIR)
		make fclean -C $(STACK_TEST_DIR)
		make fclean -C $(INTRA_TEST_DIR)
		$(RM) $(LOGS_DIR)

re:		fclean all

PHONY:	all clean fclean re\
		vector_test map_test stack_test set_test intra_test\
		vector_script map_script stack_script set_script intra_script

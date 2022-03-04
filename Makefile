# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 17:27:40 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/04 17:44:50 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM		:=	rm -rf
TESTER	:=	bash tester.sh

LOGSDIR	:=	./logs/

TESTDIR	:=	./tests/

VECTORDIR	:=	$(TESTDIR).

vector:
		make -C $(VECTORDIR)

all: vector

test:
		$(TESTER)
clean:
		make clean -C $(VECTORDIR)

fclean:	
		make fclean -C $(VECTORDIR)
		$(RM) $(LOGSDIR)

re:		fclean all

PHONY:	all clean fclean re vector test
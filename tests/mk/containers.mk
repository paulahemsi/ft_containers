# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    containers.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 16:41:12 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/22 15:52:08 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT		:=	../../

CONTAINERS_DIR	:=	$(ROOT)containers/
CONTAINERS		:=	vector.hpp\
					map.hpp\
					stack.hpp\
					set.hpp

ITERATORS_DIR	:=	$(ROOT)iterators/
ITERATORS		:=	map_iterator.hpp\
					random_access_iterator.hpp\
					iterators_traits.hpp\
					reverse_iterator.hpp

AUX_TEMPLATES_DIR	:=	$(ROOT)aux_templates/
AUX_TEMPLATES		:=	lexicographical_compare.tpp\
						type_traits.tpp\
						pair.tpp

TEMPLATES_DIR	:= $(CONTAINERS_DIR) $(ITERATORS_DIR) $(AUX_TEMPLATES_DIR) 
TEMPLATES		:= $(CONTAINERS) $(ITERATORS) $(AUX_TEMPLATES)

VPATH	:=	$(TEMPLATES_DIR)

INCLUDES	:= $(addprefix -I, $(TEMPLATES_DIR))

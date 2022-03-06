# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    containers.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 16:41:12 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/06 16:41:17 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT		:=	../../

CONTAINERS_DIR	:=	$(ROOT)containers/
CONTAINERS		:=	Vector.hpp

ITERATORS_DIR	:=	$(ROOT)iterators/
ITERATORS		:=	bidirectional_iterator.hpp\
					random_access_iterator.hpp\
					iterators_traits.hpp\
					reverse_iterator.hpp

AUX_TEMPLATES_DIR	:=	$(ROOT)aux_templates/
AUX_TEMPLATES		:=	lexicographical_compare.tpp\
						type_traits.tpp 

TEMPLATES_DIR	:= $(CONTAINERS_DIR) $(ITERATORS_DIR) $(AUX_TEMPLATES_DIR) 
TEMPLATES		:= $(CONTAINERS) $(ITERATORS) $(AUX_TEMPLATES)
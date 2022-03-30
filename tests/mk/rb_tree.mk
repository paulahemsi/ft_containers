# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rb_tree.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 18:39:11 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/29 22:19:02 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR				:=	$(ROOT)rb_tree/includes/

TEMPLATES		+=	rb_tree.hpp\
					btree.tpp\
					btree_insert_data.tpp

VPATH			+=	$(DIR)

INCLUDES		+=	$(addprefix -I, $(DIR))
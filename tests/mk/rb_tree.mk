# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rb_tree.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 18:39:11 by lfrasson          #+#    #+#              #
#    Updated: 2022/04/05 19:45:56 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR				:=	$(ROOT)rb_tree/includes/

TEMPLATES		+=	rb_tree.hpp\
					btree.tpp\
					btree_create_node.tpp\
					btree_insert_data.tpp\
					btree_left_rotate.tpp\
					btree_right_rotate.tpp\
					btree_rotate_aux.tpp\
					btree_next.tpp\
					btree_previous.tpp\
					btree_auxiliary.tpp

VPATH			+=	$(DIR)

INCLUDES		+=	$(addprefix -I, $(DIR))

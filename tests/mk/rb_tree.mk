# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rb_tree.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 18:39:11 by lfrasson          #+#    #+#              #
#    Updated: 2022/03/30 22:49:04 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR				:=	$(ROOT)rb_tree/includes/

TEMPLATES		+=	rb_tree.hpp\
					btree.tpp\
					btree_insert_data.tpp\
					btree_left_rotate.tpp\
					btree_right_rotate.tpp\
					btree_rotate_aux.tpp

VPATH			+=	$(DIR)

INCLUDES		+=	$(addprefix -I, $(DIR))
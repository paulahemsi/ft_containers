
NAME			:=	tree.out

INCLUDES_DIR	:=	./includes/
SRC_DIR			:=	./src/
TESTS_DIR		:=	./tests/
OBJS_DIR		:=	./objs/

CC				:=	c++
CFLAGS			:=	-Wall -Wextra -Werror
CFLAGS			+=	-g3
CFLAGS			+=	-std=c++98

RM				:=	rm -rf

TESTS			:=	$(TESTS_DIR)main.cpp

OBJS			:=	$(addprefix $(OBJS_DIR), $(notdir $(TESTS:.cpp=.o)))

HEADER			:=	btree.tpp\
					test.hpp\
					btree_create_node.tpp\
					btree_insert_data.tpp\
					btree_apply_prefix.tpp\
					btree_apply_infix.tpp\
					btree_apply_suffix.tpp\
					btree_apply_by_level.tpp\
					btree_search_item.tpp\
					btree_level_count.tpp\
					btree_delete.tpp\
					btree_right_rotate.tpp\
					btree_left_rotate.tpp\
					btree_rotate_aux.tpp\
					print_item.tpp\
					btree_begin.tpp\
					btree_end.tpp\
					btree_auxiliary.tpp\
					btree_next.tpp\
					btree_previous.tpp\
					queue.tpp

INCLUDES_DIR	+=	../aux_templates/
HEADER			+=	pair.tpp

VPATH			:=	$(INCLUDES_DIR)

INCLUDES		:= $(addprefix -I, $(INCLUDES_DIR))

$(OBJS_DIR)%.o:	$(TESTS_DIR)%.cpp
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ -o $@

$(OBJS):		$(HEADER) | $(OBJS_DIR)

$(OBJS_DIR):
				mkdir $(OBJS_DIR)

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

PHONY:			all clean fclean re

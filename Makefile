NAME		= push

CC			= cc
CFLAGS		= -g -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= push_swap.c \
			cmds_push.c \
			cmds_rotate.c \
			cmds_swap.c \
			sort_small.c \
			analyze_stack.c \
			lis_analyzer.c \

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "Linking $@"
	$(CC) $(CFLAGS) $(OBJS) -o $@
	chmod +x $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

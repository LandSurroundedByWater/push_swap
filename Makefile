NAME		= push_swap

CC			= cc
CFLAGS		= -g -Wall -Wextra -Werror
RM			= rm -rf

LIBFT_DIR	= libft
LIBFT		= $libft/libft.a

SRCS		= push_swap.c \
			cmds_push.c \
			cmds_rotate.c \
			cmds_rotate2.c \
			cmds_swap.c \
			sort_small.c \
			analyze_stack.c \
			analyze_stack2.c \
			sort_big.c \
			utils.c \
			utils2.c \
			ft_free.c \
			extras.c \

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "Linking $@"
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $@
	chmod +x $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


LIBFT= 	libft/libft.a

SRCS		= push_swap.c \
			cmds_push.c \
			cmds_rotate.c \
			cmds_rotate2.c \
			cmds_swap.c \
			sort_small.c \
			analyze_stack.c \
			analyze_stack2.c \
			sort_big.c \
			sort_big2.c \
			utils.c \
			utils2.c \
			utils3.c \
			ft_free.c \

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all:		$(NAME)


$(OBJ_DIR)/%.o: %.c
			@$(CC) $(CFLAGS) -o $@ -c $<
			@echo "\033[0;36mObject $@ [\033[0;32mOK\033[0;36m]\033[0m"

$(LIBFT):
			@make -C "libft"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJ_DIR) $(OBJS) $(LIBFT) libft/*.c
			@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
			@echo "\033[1;32mPush-Swap compile success!\n\033[0m"


clean:
			$(RM) $(OBJ_DIR)
			@make clean -C "libft"
			@echo "\033[0;36mClean Push-Swap [\033[0;32mDONE\033[0;36m]\033[0m"

fclean:		clean
			$(RM) $(NAME) $(OBJ_DIR)
			@make fclean -C "libft"
			@echo "\033[0;36mFClean Push-Swap [\033[0;32mDONE\033[0;36m]\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
NAME = push_swap
CHECKER_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft #-fsanitize=address -g3

LIBFT = libft/libft.a

SRCS =  src/main.c src/find_cost.c src/find_target.c src/ft_atol.c src/handle_error.c src/handle_str.c \
		src/initialize_stack.c src/operations.c src/push_swap_op.c \
		src/rotate_op.c src/reverse_rotate_op.c src/sort_three.c src/sort_small.c src/sort_big.c \
		src/utils.c src/valid_input.c src/sort_big_utils.c src/sort_big_utils2.c src/process_args.c \

OBJ_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

BONUS = src/checker.c src/checker_utils.c \
		src/find_cost.c src/find_target.c src/ft_atol.c src/handle_error.c src/handle_str.c \
		src/initialize_stack.c src/operations.c src/push_swap_op.c \
		src/rotate_op.c src/reverse_rotate_op.c src/utils.c src/valid_input.c src/process_args.c \

BONUS_OBJ_DIR = obj_bonus
BONUS_OBJS = $(BONUS:src/%.c=$(BONUS_OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(LIBFT) :
	make -C libft

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	make -C libft clean

fclean : clean
	rm -f $(NAME) $(CHECKER_NAME)
	make -C libft fclean

re : fclean all

bonus : $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(CHECKER_NAME)

$(BONUS_OBJ_DIR)/%.o: src/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR) :
	mkdir -p $(BONUS_OBJ_DIR)

.PHONY : all clean fclean re bonus
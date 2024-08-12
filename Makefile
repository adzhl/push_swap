 NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft 

LIBFT = libft/libft.a

SRCS = src/main.c src/operations.c src/parse_arg.c src/push_swap.c \
		src/rotate_reverse.c src/sort_stack.c src/analyze_stack.c \
		src/utils1.c src/utils2.c src/sorting_algo.c\

OBJ_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

BONUS = 

BONUS_OBJ_DIR = obj_bonus
BONUS_OBJS = $(BONUS:src_bonus/%.c=$(BONUS_OBJ_DIR)/%.o)

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
	rm -f $(NAME)
	make -C libft fclean

re : fclean all

bonus : $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)

$(BONUS_OBJ_DIR)/%.o: src_bonus/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR) :
	mkdir -p $(BONUS_OBJ_DIR)

.PHONY : all clean fclean re bonus
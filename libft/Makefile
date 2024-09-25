# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 11:34:17 by abinti-a          #+#    #+#              #
#    Updated: 2024/09/24 12:29:50 by abinti-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of file
NAME = libft.a

# Compiler and Compiler Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./ #-fsanitize=address -g3

# Source files and object
SRCS = ft_isdigit.c \
	  ft_strncmp.c \
	  ft_split.c \
	  ft_atoi.c \
	  ft_substr.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  get_next_line.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 

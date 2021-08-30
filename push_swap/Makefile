# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 12:47:40 by zakdim            #+#    #+#              #
#    Updated: 2021/06/14 12:36:27 by zakdim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = push_swap.c push_help_2.c push_help_3.c push_help.c push_scan.c \
		solutions.c transition_3.c transitions_2.c transitions.c \
		ft_strlen.c ft_strchr.c ft_strdup.c ft_splite.c ft_strtrim.c \
		chack_error.c ft_free.c
NAME = push_swap
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
%.o:%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@
all: *.h
	@$(MAKE) $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all


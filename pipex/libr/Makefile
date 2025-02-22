# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 16:16:53 by abdsebba          #+#    #+#              #
#    Updated: 2025/02/12 16:43:04 by abdsebba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
HEAD = libr.h
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
ARRCS = ar -rcs

SRC = ft_split.c   ft_strchr.c  ft_strcmp.c  ft_strdup.c  ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
	ft_strlen.c  ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@
	$(ARRCS) $(NAME) $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 17:18:29 by abdsebba          #+#    #+#              #
#    Updated: 2025/02/02 12:48:41 by abdsebba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC    = pipex.c check_path.c helper_function.c error_print.c
OBJ    = $(SRC:.c=.o)
SRC_BONUS = bonus/bonnus_.c bonus/get_next_line.c bonus/exute_cmd.c bonus/helper.c bonus/parte_2.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME   = pipex
BONUS  = pipex_bonus
CC     = cc
CFLAGS = -Wall -Wextra -Werror
LIB    = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
#make all -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

%.o: %.c pipex.h bonus/bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
#make all -C libft
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) -o $@

clean:
#make clean -C libft
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
#make fclean -C libft
	rm -f $(NAME) $(BONUS)

re: fclean all

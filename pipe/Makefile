# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 17:18:29 by abdsebba          #+#    #+#              #
#    Updated: 2025/02/10 18:08:35 by abdsebba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC    = pipex.c check_path.c helper_function.c error_print.c
OBJ    = $(SRC:.c=.o)
SRC_BONUS = bonus/pipex_bonus.c bonus/get_next_line.c bonus/exute_cmd_bonus.c bonus/helper.c bonus/parte_2_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME   = pipex
BONUS  = pipex_bonus
CC     = cc
CFLAGS = -Wall -Wextra -Werror
LIB    = libft/libft.a

all: $(NAME)

bonus: $(BONUS)

$(OBJ):%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
#make all -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

$(OBJ_BONUS):%.o: %.c bonus/pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

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

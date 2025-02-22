# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 17:18:29 by abdsebba          #+#    #+#              #
#    Updated: 2025/02/21 13:13:21 by abdsebba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC    = pipex.c check_path.c helper_function.c error_print.c
OBJ    = $(SRC:.c=.o)
SRC_BONUS = bonus/pipex_bonus.c bonus/get_next_line.c bonus/exute_cmd_bonus.c bonus/helper.c bonus/parte_2_bonus.c\
	bonus/ft_maltu.c bonus/here_doc.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME   = pipex
CC     = cc
CFLAGS = -Wall -Wextra -Werror
LIB    = libr/libft.a

all: $(NAME)

bonus: $(OBJ_BONUS)
	make all -C libr
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) -o $(NAME)

$(OBJ):%.o: %.c pipex.h libr/libr.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make all -C libr
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

$(OBJ_BONUS):%.o: %.c bonus/pipex_bonus.h bonus/get_next_line.h libr/libr.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libr
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C libr
	rm -f $(NAME) $(BONUS)

re: fclean all

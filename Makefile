# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:50:42 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/15 15:58:24 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = \
		s_clear.c \
		s_clone.c \
		s_init.c \
		s_pop.c \
		s_push.c \
		main.c

#-Wall -Wextra -Werror
CFLAGS = -g -Wall -Wextra -Werror -I .
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = stack

OBJ_DIR = OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:OUT/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

##################

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

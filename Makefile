# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 12:55:35 by ale-goff          #+#    #+#              #
#    Updated: 2018/10/22 18:50:30 by ale-goff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly

SRCS = grimly.c\
	   init_values.c\
	   parse.c\
	   algorithms.c\
	   

OBJ = $(SRCS:.c=.o)

MAKE = make -C libft/

MAKEP = make -C ft_printf/

LIBRARY2 = ft_printf/libftprintf.a

LIBRARY = libft/libft.a

INCLUDES = -I libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBRARY) $(LIBRARY2)
	gcc $(FLAGS) $(INCLUDES) $(OBJ) $(LIBRARY) $(LIBRARY2) -o $(NAME)

$(LIBRARY):
	$(MAKE)

$(LIBRARY2):
	$(MAKEP)

debug:
	gcc -g -fsanitize=address $(FLAGS) $(OBJ) $(LIBRARY) $(LIBRARY2) -o $(NAME)

clean:
	/bin/rm -f $(OBJ) && $(MAKE) clean && $(MAKEP) clean

fclean: clean
	/bin/rm -f $(NAME) && $(MAKE) fclean && $(MAKEP) fclean

re: fclean all

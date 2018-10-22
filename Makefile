# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 12:55:35 by ale-goff          #+#    #+#              #
#    Updated: 2018/10/22 12:57:17 by ale-goff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly

OBJ = $(SRCS:.c=.o)

MAKE = make -C libft/

MAKEP = make -C ft_printf/

LIBRARY2 = ft_printf/libftprintf.a

LIBRARY = libft/libft.a

NAME = calc

INCLUDES = -I libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	gcc $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBRARY) $(LIBRARY2)
	gcc $(INCLUDES) $(OBJ) $(LIBRARY) $(LIBRARY2) -o $(NAME)

$(LIBRARY):
	$(MAKE)

$(LIBRARY2):
	$(MAKEP)

clean:
	/bin/rm -f $(OBJ) && $(MAKE) clean && $(MAKEP) clean

fclean: clean
	/bin/rm -f $(NAME) && $(MAKE) fclean && $(MAKEP) fclean

re: fclean all

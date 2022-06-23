# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shirapra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 01:25:59 by shirapra          #+#    #+#              #
#    Updated: 2022/06/21 03:12:30 by shirapra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT	= libft
INCLUDES = includes
CC	= gcc
CFLGAS	= -Wall -Wextra -Werror
OBJDIR	= obj

SOURCES	= ft_printf.c utils_printf_general.c utils_printf_hexadecimal.c \
	  utils_printf_pointer.c utils_printf_unsigned.c \

SRCDIR	= srcs
SRCS	= ${addprefix $(SRCDIR)/, $(SOURCES)}
OBJS	= ${addprefix $(OBJDIR)/, $(SOURCES:.c=.o)}

all:	${NAME}

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p obj
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)
	

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re :	fclean all

.PHONY: all clean fclean re

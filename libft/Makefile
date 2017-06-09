# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelharim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 16:24:27 by aelharim          #+#    #+#              #
#    Updated: 2017/06/09 13:46:16 by aelharim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -g -Wall -Wextra -Werror

SRCS = ft_putnstr.c get_next_line.c ft_lstmap.c ft_abs.c ft_sqrt.c ft_lstiter.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstnew.c ft_itoa.c ft_strsplit.c ft_strtrim.c ft_strsub.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strjoin.c ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_putendl.c ft_striteri.c ft_striter.c ft_strdel.c ft_memdel.c ft_strclr.c ft_memalloc.c ft_strnew.c ft_strlcat.c ft_memmove.c ft_memcmp.c ft_memchr.c ft_memccpy.c ft_strrchr.c ft_strchr.c ft_strnstr.c ft_strncat.c ft_strcat.c ft_memcpy.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_atoi.c ft_strncpy.c ft_strncmp.c ft_memset.c ft_strstr.c ft_bzero.c ft_isalpha.c ft_isdigit.c

OBJ = ft_putnstr.o ft_lstmap.o get_next_line.o ft_abs.o ft_sqrt.o ft_lstiter.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstnew.o ft_itoa.o ft_strsplit.o ft_strtrim.o ft_strsub.o ft_putnbr_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putchar_fd.o ft_strjoin.o ft_strnequ.o ft_strequ.o ft_strmapi.o ft_strmap.o ft_putendl.o ft_striteri.o ft_striter.o ft_strdel.o ft_memdel.o  ft_strclr.o ft_memalloc.o ft_strnew.o ft_strlcat.o ft_memmove.o ft_memcmp.o ft_memchr.o ft_memccpy.o ft_strrchr.o ft_strchr.o ft_strnstr.o ft_strncat.o ft_strcat.o ft_memcpy.o ft_tolower.o ft_toupper.o ft_isprint.o ft_isascii.o ft_isalnum.o ft_putchar.o ft_putstr.o ft_strlen.o ft_putnbr.o ft_strcmp.o ft_strcpy.o ft_strdup.o ft_atoi.o ft_strncpy.o ft_strncmp.o ft_memset.o ft_strstr.o ft_bzero.o ft_isalpha.o ft_isdigit.o

HEADER = -Ilibft.h

all : $(NAME)

$(NAME) :
	gcc $(FLAG) $(HEADER) -c $(SRCS)
	ar rc $(NAME) $(OBJ)

clean :
	/bin/rm -rf $(OBJ)

fclean :
	make clean
	/bin/rm -rf $(NAME)

re : 
	make fclean
	make all

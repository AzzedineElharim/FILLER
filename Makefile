# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelharim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/06 16:13:43 by aelharim          #+#    #+#              #
#    Updated: 2017/06/07 16:02:03 by aelharim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = aelharim.filler
FLAG = -g -Wall -Werror -Wextra
LIB = ./libft/libft.a
SRCS_NAME = main.c algo.c init.c tools.c info.c
SRC_PATH = sources/
SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

#COLORS
C_GREEN         =   "\033[32m"
C_END           =   "\033[0m"

#MESSAGE
SUCCESS         =   SUCCESS$(C_END)

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@cc $(FLAG) $(SRCS) $(LIB) -o $(NAME)
	@echo $(C_GREEN)"Compiling" [ aelharim.filler ] $(SUCCESS)

cc:
	@cc -g $(FLAG) $(SRCS) $(LIB) -o $(NAME)
	@echo $(C_GREEN)"Compiling without flags" [ aelharim.filler ] $(SUCCESS)
	hilite ./resources/filler_vm -f ./resources/maps/map00 \
		-p2 ./aelharim.filler \
		-p1 ./resources/players/superjeannot.filler

##--------------------GRAPH-----------------##
#| ./Show_Filler/show.filler
##--------------------Map 00--------------------##
## champely ==> OK                               ##
## grati ==> OK                                  ##
## abanlin ==> OK                                ##
## hcao ==> OK                                   ##
## carli ==> OK                                  ##
## superjeannot ==> OK                           ##
clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re

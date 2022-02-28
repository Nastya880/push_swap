# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 18:00:54 by tandroma          #+#    #+#              #
#    Updated: 2022/02/24 13:18:45 by tandroma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/operations_r.c \
			srcs/operations_s.c \
			srcs/operations_p.c \
			srcs/algo_less_four_args.c \
			srcs/algo_more_five_args.c \
			srcs/algo_more_three_less_six_args.c \
			srcs/work_with_parts.c \
			srcs/average_arg.c \
			srcs/check_input.c \
			srcs/check_sort.c \
			main.c \

OBJS    =       ${SRCS:.c=.o}

CC      =       clang

FLAGS   =       -Wall -Wextra -Werror

NAME    =       push_swap

LINK	=	-lft

LIB     =       libft/libft.a

RM      =       rm -rf

LIB_PATH	=	-L ./libft/

all:    ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:        ${OBJS}
		make -C libft
		${CC} ${LIB_PATH} -o ${NAME} ${OBJS} ${LINK}

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean:         clean
	make fclean -C libft
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re

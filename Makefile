# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 16:07:53 by llepiney          #+#    #+#              #
#    Updated: 2022/04/29 17:26:34 by llepiney         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC            =    gcc

FLAGS        =    -Wall -Werror -Wextra

RM            =    rm -f

SRCS        =   so_long.c \
				gnl/gnl.c gnl/gnl_utils.c \
				map/map_check.c map/map_handler.c map/map_utils.c \
				# utils/ft_strjoin.c \
				# utils/ft_strlen.c \
				# utils/ft_split.c \
				# utils/ft_putstr.c \
				# is_valid_map.c \
				# init_map.c \
				# moove.c \
				# trap.c \
				# gob.c \
				# gob_moove.c \
				# game_over.c \

OBJS        =    ${SRCS:.c=.o}

MLX            =    minilibx-linux/libmlx_Linux.a

MLXFLAGS    =    -lX11 -lXext

NAME        =    so_long

all            :    ${NAME}

${NAME}    :    ${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME} ${MLX} ${MLXFLAGS}

.c.o    :
			$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

clean    :
		${RM} ${OBJS}

fclean    :    clean
			${RM} ${NAME}

re    :    fclean    all

.PHONY    :    all clean fclean re libft bonus
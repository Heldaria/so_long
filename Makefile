# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 16:07:53 by llepiney          #+#    #+#              #
#    Updated: 2022/05/16 21:35:34 by llepiney         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC            =    gcc

FLAGS        =    -Wall -Werror -Wextra

RM            =    rm -f

SRCS        =   $(addprefix mn/, \
				so_long.c \
				gnl/gnl.c gnl/gnl_utils.c \
				map/map_check.c map/map_handler.c map/map_utils.c \
				img/put_image.c map/fill_map.c map/count_check.c\
				key_act.c move.c game_over.c error_msg.c)

BONUS_SRCS	= $(addprefix bn/, \
				so_long.c \
				gnl/gnl.c gnl/gnl_utils.c \
				map/map_check.c map/map_handler.c map/map_utils.c map/map_utils2.c \
				img/put_image.c map/fill_map.c map/count_check.c\
				key_act.c move.c game_over.c error_msg.c \
				ghost.c ghost_move.c buck.c ghost_display.c mvt_display.c \
				ft_strjoin2.c ft_itoa.c)

OBJS        =    ${SRCS:.c=.o}

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

MLX            =    minilibx-linux/libmlx_Linux.a

MLXFLAGS    =    -lX11 -lXext

NAME        =    so_long

all            :    ${NAME}

${NAME}    :    ${OBJS} so_long.h
			${CC} ${FLAGS} ${OBJS} -o ${NAME} ${MLX} ${MLXFLAGS}

bonus			:	${BONUS_OBJS} so_long.h
			${CC} ${FLAGS} ${BONUS_OBJS} -o so_long ${MLX} ${MLXFLAGS}

.c.o    :
			$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

clean    :
		${RM} ${OBJS} ${BONUS_OBJS}

fclean    :    clean
			${RM} ${NAME} ${BONUS}

re    :    fclean    all bonus

.PHONY    :    all clean fclean re libft bonus
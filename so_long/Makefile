# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 17:57:46 by magonzal          #+#    #+#              #
#    Updated: 2022/09/20 19:39:22 by magonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c display.c get_next_line_utils.c get_next_line.c createmap.c checkmap.c game.c keys.c

OBJS	= ${SRCS:.c=.o}

NAME	= solong

MINILIB	= minilibx/libmlx.a

PATHMLIB	= minilibx/

PATHLIB	= 42_libft/

LIBFT	= 42_libft/libft.a

CC	= gcc

RM	= rm -f

CFLAGS	= -I. -Wall -Wextra -Werror -Imlx -g3 -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				@make -C ${PATHLIB}
				@make -C ${PATHMLIB}
				${CC} ${CFLAGS} ${MINILIB} ${LIBFT} ${OBJS} -lmlx -framework OpenGL -framework AppKit -L. -o ${NAME}

all:		${NAME}

clean:
				@make clean -C ${PATHLIB}
				@make clean -C ${PATHMLIB}
				${RM} ${OBJS}

fclean: 	clean
				@make clean
				${RM} ${LIBFT}
				${RM} ${MINILIB}
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
















# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 12:22:13 by jdegluai          #+#    #+#              #
#    Updated: 2023/12/19 15:24:52 by jdegluai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = cub3d.c parsing.c read_map.c wall.c wall_utils.c player.c direction.c get_colors.c moove.c get_textures.c put_texture.c

NAME = cub3d

MINILIBX = mlx/libmlx.a

LIBFT = libft/libft.a

OBJS_DIR = objs/

OBJS = ${SRCS:.c=.o}

OBJS_PREFIXED = ${addprefix ${OBJS_DIR}, ${OBJS}}

CC = cc

CC_FLAGS = -Wall -Werror -Wextra -g

MLB_FLAGS = -I -g -L /usr/X11/lib -Lincludes -L./mlx -lmlx -Imlx -lXext -lX11 -lz -lm libft/libft.a

${OBJS_DIR}%.o : %.c cub3d_h/cub3d.h
		@mkdir -p ${OBJS_DIR}
		@${CC} ${CC_FLAGS} -c $< -o $@

${NAME}: ${OBJS_PREFIXED} ${MINILIBX} ${LIBFT}
		@${CC} -o ${NAME} ${OBJS_PREFIXED} ${CC_FLAGS} ${MLB_FLAGS}

all : ${NAME}

${MINILIBX} :
		@make -C mlx

${LIBFT} :
		@make -C libft

clean :
		@rm -rf ${OBJS_DIR}
		@make clean -C libft

fclean : clean
		@make clean -C mlx
		@make clean -C libft
		@rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re

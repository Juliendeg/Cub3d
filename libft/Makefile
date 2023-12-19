# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdegluai <jdegluai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 10:52:26 by jdegluai          #+#    #+#              #
#    Updated: 2023/12/12 15:40:36 by jdegluai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
	get_next_line.c get_next_line_utils.c ft_printf.c ft_putchar.c ft_put_memory.c ft_putnbr.c \
	ft_putnbr_hexa_min.c ft_putnbr_hexa_maj.c ft_putnbr_u.c ft_putstr.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS = ${SRCS:.c=.o}

NAME = libft.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${OBJS} 
	  ar rcs ${NAME} ${OBJS}

clean :
	${RM} ${OBJS}

fclean :clean
	${RM} ${NAME}

re : fclean $(NAME)

bonus : ${OBJS}
	ar rcs ${NAME} ${OBJS}

.PHONY : all clean fclean re

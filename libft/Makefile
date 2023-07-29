# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 19:08:45 by jkarosas          #+#    #+#              #
#    Updated: 2021/11/22 19:08:45 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c

OBJS		= ${SRCS:.c=.o}

BONUS		=	ft_lstadd_back.c ft_lstadd_front.c \
				ft_lstlast.c ft_lstdelone.c ft_lstclear.c\
				ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC			= gcc
RM			= rm -f
AR			= ar rc

CFLAGS		= -Wall -Wextra -Werror

NAME		= libft.a

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		$(NAME)

clean:
			${RM} ${OBJS} $(BONUS_OBJS)

fclean:		clean
			${RM} $(NAME)

re:			fclean all

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:		all clean fclean re bonus

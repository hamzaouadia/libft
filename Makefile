# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 07:39:55 by haouadia          #+#    #+#              #
#    Updated: 2022/10/17 08:39:01 by haouadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_atoi.c ft_isprint.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c ft_bzero.c ft_itoa.c \
		ft_memset.c ft_strdup.c ft_strncmp.c ft_calloc.c ft_putchar_fd.c ft_striteri.c \
		ft_strnstr.c ft_isalnum.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_isalpha.c \
		ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c \
		ft_substr.c ft_isdigit.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c 

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c \
		ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ): $(SRC)
	$(CC) -I ./ $(CFLAGS) -c $(SRC)

$(OBONUS) : $(BONUS)
		$(CC) -I ./ $(CFLAGS) -c $(BONUS)
		ar -rc $(NAME) $(OBONUS) $(OBJ)
		ranlib $(NAME)

bonus: $(OBONUS) $(OBJ)
		
clean:
		$(RM) $(OBJ) $(OBONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

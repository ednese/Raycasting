NAME	= libft.a

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr_lib.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c

OBJS    = ${SRCS:.c=.o}

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra 

.a.o:
	${CC} ${CFLAGS}  $< -o ${<:.c=.o}


$(NAME): ${OBJS}
	ar rc $(NAME) ${OBJS}
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

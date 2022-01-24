NAME	=	libft.a

SRCS 	=	ft_atoi.c		ft_bzero.c		ft_calloc.c 	ft_isalnum.c	ft_isalpha.c\
			ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_itoa.c		ft_memchr.c\
			ft_memcmp.c		ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_putchar_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c		ft_strchr.c\
			ft_strdup.c		ft_strjoin.c	ft_strlcat.c	ft_strlcpy.c	ft_strlen.c\
			ft_strmapi.c	ft_strncmp.c	ft_strnstr.c	ft_strrchr.c	ft_strtrim.c\
			ft_substr.c		ft_tolower.c	ft_toupper.c	ft_memccpy.c	ft_strcmp.c\
			ft_free_array.c	ft_revers.c

HEADER	=	libft.h

SRCS_B	= 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
			ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c

OBJS	=	$(patsubst %.c, %.o, $(SRCS))
OBJS_B	=	$(patsubst %.c, %.o, $(SRCS_B))

FLAGS	=	-Wall -Wextra -Werror -g

all		:	${NAME}

${NAME} :	${OBJS} ${HEADER}
	ar rc $(NAME) ${OBJS}

%.o		:	%.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

bonus	:	${OBJS_B}
	@make OBJS="${OBJS_B}" all
clean	:
	@rm -f ${OBJS} ${OBJS_B}

fclean	: 	clean
	@rm -f ${NAME}

re 		:	fclean all

.PHONY :	all clean fclean re


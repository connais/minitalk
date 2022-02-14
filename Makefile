SRCLIENT = client.c

SRCSERVER = server.c

NAME = client

NAMESERVER = server

CC = gcc 

LIBFT = @cd LIBFT && make

FTPRINTF = @cd ft_printf && make

HEADER = minitalk.h

FLAGS	= -Wall -Wextra -Werror 

OBJCLIENT = ${SRCLIENT:.c=.o}

OBJSERVER = ${SRCSERVER:.c=.o}

RM = rm -f

all	: ${NAME} ${NAMESERVER}

${NAME} : 	${OBJCLIENT}
		${LIBFT}
		${FTPRINTF}
		${CC} ${FLAGS} -o ${NAME} ${OBJCLIENT} LIBFT/libft.a ft_printf/libftprintf.a

${NAMESERVER} :	${OBJSERVER}
		${LIBFT}
		${FTPRINTF}
		${CC} ${FLAGS} -o ${NAMESERVER} ${OBJSERVER}  LIBFT/libft.a ft_printf/libftprintf.a

clean :
	${RM} ${OBJSERVER} ${OBJCLIENT}
	@cd LIBFT && make clean
	@cd ft_printf && make clean


fclean :	clean
	${RM} ${NAME} ${NAMESERVER}
	@cd LIBFT && make fclean
	@cd ft_printf && make fclean


re :	fclean all

SERVER_NAME	= server

CLIENT_NAME	= client

SRCS_SERVER = ./srcs/server/server.c

SRCS_CLIENT = ./srcs/client/client.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

CC			= clang

FLAGS		= -Wall -Wextra -Werror

INCLUDES	= ./includes/minitalk.h

RM			= rm -rf

all:		${SERVER_NAME} ${CLIENT_NAME}

${SERVER_NAME}:	${OBJS_SERVER}
					${MAKE} -C libft
					${CC} ${FLAGS} -o ${SERVER_NAME} ${OBJS_SERVER} libft/libft.a -I ${INCLUDES}

${CLIENT_NAME}:	${OBJS_CLIENT}
					${CC} ${FLAGS} -o ${CLIENT_NAME} ${OBJS_CLIENT} libft/libft.a -I ${INCLUDES}

clean:		
			${MAKE} -C libft clean
			${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${CLIENT_NAME} ${SERVER_NAME}

re:			fclean all

.PHONY:		clean fclean re all
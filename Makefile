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
					@${MAKE} -C libft
					@echo "minitalk : libft compiled."
					@${CC} ${FLAGS} -o ${SERVER_NAME} ${OBJS_SERVER} libft/libft.a -I ${INCLUDES}
					@echo "minitalk : server compiled."

${CLIENT_NAME}:	${OBJS_CLIENT}
					@${CC} ${FLAGS} -o ${CLIENT_NAME} ${OBJS_CLIENT} libft/libft.a -I ${INCLUDES}
					@echo "minitalk : client compiled."

.c.o:
				@${CC} ${CFLAGS} -c $< -o ${<:c=o}

clean:		
			@${MAKE} -C libft clean
			@${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
			@echo "minitalk : \".o\" files were erased"

fclean:		clean
			@${MAKE} -C libft fclean
			@${RM} ${CLIENT_NAME} ${SERVER_NAME}
			@echo "minitalk : \".o\" and executables were erased"

re:			fclean all

.PHONY:		clean fclean re all
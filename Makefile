SERVER_NAME	= server

CLIENT_NAME	= client

SRCS_SERVER = ./srcs/server/server.c

SRCS_CLIENT = ./srcs/client/client.c \
			./srcs/client/client_utils.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

CC			= clang

FLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I ./includes/ -I ./libft/includes/

RM			= rm -rf

.c.o:
				@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all:		${SERVER_NAME} ${CLIENT_NAME}

${SERVER_NAME}:	${OBJS_SERVER}
					@${MAKE} -C libft
					@echo "minitalk : libft compiled."
					@${CC} -g ${FLAGS} -o ${SERVER_NAME} ${OBJS_SERVER} libft/libft.a ${INCLUDES}
					@echo "minitalk : server compiled."

${CLIENT_NAME}:	${OBJS_CLIENT}
					@${CC} -g ${FLAGS} -o ${CLIENT_NAME} ${OBJS_CLIENT} libft/libft.a ${INCLUDES}
					@echo "minitalk : client compiled."



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
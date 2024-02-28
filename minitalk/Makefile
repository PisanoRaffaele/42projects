CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM		= rm -f

CLIENT = client.c \
		utils.c

SERVER = server.c

CLIENT_OBJ = ${CLIENT:.c=.o}
SERVER_OBJ = ${SERVER:.c=.o}

NAME_CL = client
NAME_SER = server

all: server client

server: ${SERVER_OBJ}
	${CC} ${CFLAGS} $^ -o $@

client: ${CLIENT_OBJ}
	${CC} ${CFLAGS} $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $?
	
clean:
	${RM} ${NAME_CL} ${CLIENT_OBJ}
	${RM} ${NAME_SER} ${SERVER_OBJ}

re: clean all

.PHONY:  server client clean re

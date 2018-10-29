CPP	= gcc
CFLAGS	= -O3 -Wall
#DEBUG	= -g
LIB	= -lncurses
SSRCS = server.c game_lib.c
SOBJS = ${SSRCS:.c=.o}
CSRCS = client.c game_lib.c
COBJS = ${CSRCS:.c=.o}

ALL: server client
server: ${SOBJS}
	${CPP} ${CFLAGS} ${DEBUG} -o $@ ${SOBJS} ${LIB}
client: ${COBJS}
	${CPP} ${CFLAGS} ${DEBUG} -o $@ ${COBJS} ${LIB} 
.c.o:
	${CPP} ${CFLAGS} ${DEBUG} -c $<
clean:
	rm -f *.o *.*~ *~ server client
clover:
	rm -f *.o *.*~ *~

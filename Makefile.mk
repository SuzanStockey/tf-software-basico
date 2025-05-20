CFLAGS = -Wall -g

PROG = app1
FONTES = app1.c filmes.c
OBJETOS = ${FONTES:.c=.o}

${PROG}:	${OBJETOS}
		gcc ${CFLAGS} ${OBJETOS} -o $@

clean:
		-@rm -f ${OBJETOS} ${PROG}
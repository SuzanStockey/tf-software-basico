all:		app1 app2 app3

app1:		app1.o filmes.o
		gcc -o app1 app1.o filmes.o

app2:		app2.o cinemas.o
		gcc -o app2 app2.o cinemas.o

app3:		app3.o filmes.o cinemas.o programacao.o
		gcc -o app3 app3.o filmes.o cinemas.o programacao.o

app1.o:		app1.c filmes.h
		gcc -c app1.c

filmes.o:	filmes.c filmes.h
		gcc -c filmes.c

app2.o:		app2.c cinemas.h
		gcc -c app2.c
		
cinemas.o:	cinemas.c cinemas.h
		gcc -c cinemas.c

app3.o:		app3.c filmes.h cinemas.h programacao.h
		gcc -c app3.c

programacao.o:	programacao.c programacao.h
		gcc -c programacao.c

clean:
		rm -f *.o app1 app2 app3

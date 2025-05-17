#define TAM_HORARIO 60 //TODO - PERGUNTAR TAMANHO
#define MAX_PROGRAMAS 100
#include "cinemas.h"
#include "filmes.h"

typedef struct {
	cinema_t *cinema;
	int sala_cinema;
	filme_t *filme;
	int tp_exibicao; //1=legendado;2=dublado;3=3D legendado;4=3D dublado;5=Nacional
	char horario_exibicao[TAM_HORARIO+1];
} programacao_t;

int programacao_carrega (char *nome_arq);
void programacao_mostra();

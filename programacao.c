#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "programacao.h"

static programacao_t programacao[MAX_PROGRAMAS];
static int num_programas = 0;

int programacao_carrega (char *nome_arq) {
	FILE *f = fopen(nome_arq,"r");
	if (f == NULL) return 0;
	
	char linha[TAM_HORARIO+1];
	while (1) {
		if(num_programas >= MAX_PROGRAMAS) break;

		if(fgets(linha, TAM_HORARIO+1, f) == NULL) break;
		cinema_t *cinema = cinemas_obtem_cinema_id(atoi(linha));
		programacao[num_programas].cinema = cinema;

		if(fgets(linha, TAM_HORARIO+1, f) == NULL) break;
		programacao[num_programas].sala_cinema = atoi(linha);

		if(fgets(linha, TAM_HORARIO+1, f) == NULL) break;
		filme_t *filme = filmes_obtem_filme_id(atoi(linha));
		programacao[num_programas].filme = filme;

		if(fgets(linha, TAM_HORARIO+1, f) == NULL) break;
		programacao[num_programas].tp_exibicao = atoi(linha);

		if(fgets(programacao[num_programas].horario_exibicao, TAM_HORARIO+1, f) == NULL) break;
		int tam = strlen(programacao[num_programas].horario_exibicao);
		if(programacao[num_programas].horario_exibicao[tam-1] =='\n') {
			programacao[num_programas].horario_exibicao[tam-1] ='\0';
		}

		++num_programas;
	}
	
	fclose(f);
	return 1;
	
}

void programacao_mostra_programa(programacao_t *programa){
	switch (programa->tp_exibicao) {
		case 1:
			if(programa->filme->faixa_etaria == 0) {
				printf("Sala %d: %s | %s | LEG | [LIVRE] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->estilo);
			}
			else {
				printf("Sala %d: %s | %s | LEG | [%d] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->faixa_etaria, programa->filme->estilo);
			}
			break;
		case 2:
			if(programa->filme->faixa_etaria == 0) {
				printf("Sala %d: %s | %s | DUB | [LIVRE] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->estilo);
			}
			else {
				printf("Sala %d: %s | %s | DUB | [%d] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->faixa_etaria, programa->filme->estilo);
			}
			break;
		case 3:
			if(programa->filme->faixa_etaria == 0) {
				printf("Sala %d: %s | %s | 3D LEG | [LIVRE] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->estilo);
			}
			else {
				printf("Sala %d: %s | %s | 3D LEG | [%d] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->faixa_etaria, programa->filme->estilo);
			}
			break;
		case 4:
			if(programa->filme->faixa_etaria == 0) {
				printf("Sala %d: %s | %s | 3D DUB | [LIVRE] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->estilo);
			}
			else {
				printf("Sala %d: %s | %s | 3D DUB | [%d] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->faixa_etaria, programa->filme->estilo);
			}
			break;
		case 5:
			if(programa->filme->faixa_etaria == 0) {
				printf("Sala %d: %s | %s | NAC | [LIVRE] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->estilo);
			}
			else {
				printf("Sala %d: %s | %s | NAC | [%d] | %s\n", programa->sala_cinema, programa->filme->nome, programa->horario_exibicao, programa->filme->faixa_etaria, programa->filme->estilo);
			}
			break;
		default:
			break;
	}

}

void programacao_mostra() {
	for (int i=0; i<cinemas_num_cinemas(); ++i) {
		cinema_t *cinema = cinemas_obtem_cinema_indice(i);
		printf("%s\n\n", cinema->nome);
		for (int j=0; j<num_programas; ++j) {
			if(programacao[j].cinema == cinema) {
				programacao_mostra_programa( &programacao[j] );
			}
		}
		printf("\n");
	}
}

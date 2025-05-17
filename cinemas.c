#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cinemas.h"

static cinema_t cinemas[MAX_CINEMAS];
static int num_cinemas = 0;

//FEITO
int cinemas_menor (cinema_t *c1, cinema_t *c2) {
	if( strcmp(c1->nome, c2->nome) < 0) return -1;
	if( strcmp(c1->nome, c2->nome) > 0) return 1;
	return 0;
}

//FEITO
int cinemas_carrega (char *nome_arq) {
	FILE *f = fopen(nome_arq,"r");
	if (f == NULL) return 0;
	
	char linha[TAM_NOME+1];
	while (1) {
		if(num_cinemas >= MAX_CINEMAS) break;

		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		cinemas[num_cinemas].id_cinema = atoi(linha);

		if(fgets(cinemas[num_cinemas].nome, TAM_NOME+1, f) == NULL) break;
		int tam = strlen(cinemas[num_cinemas].nome);
		if(cinemas[num_cinemas].nome[tam-1] =='\n') {
			cinemas[num_cinemas].nome[tam-1] ='\0';
		}

		if(fgets(cinemas[num_cinemas].logradouro, TAM_LOGRADOURO+1, f) == NULL) break;
		tam = strlen(cinemas[num_cinemas].logradouro);
		if(cinemas[num_cinemas].logradouro[tam-1] =='\n') {
			cinemas[num_cinemas].logradouro[tam-1] ='\0';
		}

		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		cinemas[num_cinemas].numero = atoi(linha);

		if(fgets(cinemas[num_cinemas].complemento, TAM_NOME+1, f) == NULL) break;
		tam = strlen(cinemas[num_cinemas].complemento);
		if(cinemas[num_cinemas].complemento[tam-1] =='\n') {
			cinemas[num_cinemas].complemento[tam-1] ='\0';
		}

		if(fgets(cinemas[num_cinemas].bairro, TAM_NOME+1, f) == NULL) break;
		tam = strlen(cinemas[num_cinemas].bairro);
		if(cinemas[num_cinemas].bairro[tam-1] =='\n') {
			cinemas[num_cinemas].bairro[tam-1] ='\0';
		}

		if(fgets(cinemas[num_cinemas].cep, TAM_CEP+1, f) == NULL) break;
		tam = strlen(cinemas[num_cinemas].cep);
		if(cinemas[num_cinemas].cep[tam-1] =='\n') {
			cinemas[num_cinemas].cep[tam-1] ='\0';
		}

		if(fgets(cinemas[num_cinemas].cidade, TAM_NOME+1, f) == NULL) break;
		tam = strlen(cinemas[num_cinemas].cidade);
		if(cinemas[num_cinemas].cidade[tam-1] =='\n') {
			cinemas[num_cinemas].cidade[tam-1] ='\0';
		}

		if(fgets(cinemas[num_cinemas].estado, TAM_ESTADO+1, f) == NULL) break;
		tam = strlen(cinemas[num_cinemas].estado);
		if(cinemas[num_cinemas].estado[tam-1] =='\n') {
			cinemas[num_cinemas].estado[tam-1] ='\0';
		}

		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		cinemas[num_cinemas].num_salas = atoi(linha);


		++num_cinemas;
	}
	
	fclose(f);
	return 1;
	
}

//FEITO
int cinemas_num_cinemas() {
	return num_cinemas;
}

//FEITO
cinema_t *cinemas_obtem_cinema_id(int id){
	for (int i=0; i<num_cinemas; ++i) {
		if(cinemas[i].id_cinema ==id) {
			return &cinemas[i];
		}
	}
	return 0;
}

//FEITO
cinema_t *cinemas_obtem_cinema_indice(int indice){
	if(indice < 0 || indice >=num_cinemas) return NULL;
	return &cinemas[indice];
}

//FEITO
void cinemas_mostra_cinema(cinema_t *cinema){
	printf("%s [%d]\n", cinema->nome, cinema->id_cinema);
	if(cinema->numero == -1){ //TODO - PERGUNTAR SE COMPLEMENTO TB PODE VIR COM -1
		printf("%s - %s - Bairro %s - CEP %s - %s - %s\n", cinema->logradouro, cinema->complemento, cinema->bairro, cinema->cep, cinema->cidade, cinema->estado);
	} else{
		printf("%s, %d - %s - Bairro %s - CEP %s - %s - %s\n", cinema->logradouro, cinema->numero, cinema->complemento, cinema->bairro, cinema->cep, cinema->cidade, cinema->estado);
	}
	printf("Cinema(s): %d\n", cinema->num_salas);
}

//FEITO
void cinemas_mostra(){
	for (int i=0; i<num_cinemas; ++i) {
		cinemas_mostra_cinema( & cinemas[i]);
	}
}

//FEITO
void cinemas_ordena() {
	for (int i=0; i<num_cinemas; ++i) {
		int menor = i;
		for (int j= i+1; j < num_cinemas; ++j) {
			if(cinemas_menor (&cinemas[j], &cinemas[menor]) < 0)
				menor = j;
		}
		if(menor != i) {
			cinema_t aux = cinemas[menor];
			cinemas[menor] = cinemas[i];
			cinemas[i] = aux;
		}
	}
}

//FEITO
int cinemas_salva(char *nome_arq){
	
	FILE *f = fopen(nome_arq, "w");
	if(f ==NULL) return 0;

	for (int i=0; i < num_cinemas; ++i) {
		fprintf(f, "%d\n", cinemas[i].id_cinema);
		fprintf(f, "%s\n", cinemas[i].nome);
		fprintf(f, "%s\n", cinemas[i].logradouro);
		fprintf(f, "%d\n", cinemas[i].numero);
		fprintf(f, "%s\n", cinemas[i].complemento);
		fprintf(f, "%s\n", cinemas[i].bairro);
		fprintf(f, "%s\n", cinemas[i].cep);
		fprintf(f, "%s\n", cinemas[i].cidade);
		fprintf(f, "%s\n", cinemas[i].estado);
		fprintf(f, "%d\n", cinemas[i].num_salas);

	}
	fclose(f);
	return 1;
}
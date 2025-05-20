#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filmes.h"

static filme_t filmes[MAX_FILMES];
static int num_filmes = 0;

int filmes_menor (filme_t *f1, filme_t *f2) {
	if( strcmp(f1->nome, f2->nome) < 0) return -1;
	if( strcmp(f1->nome, f2->nome) > 0) return 1;
	return 0;
}

int filmes_carrega (char *nome_arq) {
	FILE *f = fopen(nome_arq,"r");
	if (f == NULL) return 0;
	
	char linha[TAM_NOME+1];
	while (1) {
		if(num_filmes >= MAX_FILMES) break;
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		filmes[num_filmes].id_filme = atoi(linha);
		if(fgets(filmes[num_filmes].nome, TAM_NOME+1, f) == NULL) break;
		int tam = strlen(filmes[num_filmes].nome);
		if(filmes[num_filmes].nome[tam-1] =='\n') {
			filmes[num_filmes].nome[tam-1] ='\0';
		}
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		filmes[num_filmes].faixa_etaria = atoi(linha);
		if(fgets(filmes[num_filmes].estilo, TAM_ESTILO+1, f) == NULL) break;
		tam = strlen(filmes[num_filmes].estilo);
		if(filmes[num_filmes].estilo[tam-1] =='\n') {
			filmes[num_filmes].estilo[tam-1] ='\0';
		}
		
		
		++num_filmes;
	}
	
	fclose(f);
	return 1;
	
}

int filmes_num_filmes() {
	return num_filmes;
}

filme_t *filmes_obtem_filme_id(int id){
	for (int i=0; i<num_filmes; ++i) {
		if(filmes[i].id_filme ==id) {
			return &filmes[i];
		}
	}
	return 0;
}

filme_t *filmes_obtem_filme_indice(int indice){
	if(indice < 0 || indice >=num_filmes) return NULL;
	return &filmes[indice];
}

void filmes_mostra_filme(filme_t *filme){
	if(filme->faixa_etaria == 0){
          //Besouro Azul [1] - LIVRE - Ação
		printf("%s [%d] - LIVRE - %s\n", filme->nome, filme->id_filme, filme->estilo);
	} else {
		// Besouro Azul [1] - 14 anos - Ação
		printf("%s [%d] - %d anos - %s\n", filme->nome, filme->id_filme, filme-> faixa_etaria, filme->estilo);
	}
}

void filmes_mostra(){
	for (int i=0; i<num_filmes; ++i) {
		filmes_mostra_filme( &filmes[i] );
	}
}

void filmes_ordena() {
	for (int i=0; i<num_filmes; ++i) {
		int menor = i;
		for (int j= i+1; j < num_filmes; ++j) {
			if(filmes_menor (&filmes[j], &filmes[menor]) < 0)
				menor = j;
		}
		if(menor != i) {
			filme_t aux = filmes[menor];
			filmes[menor] = filmes[i];
			filmes[i] = aux;
		}
	}
}

int filmes_salva(char *nome_arq){
	FILE *f = fopen(nome_arq, "w");
	if(f == NULL) return 0;

	for (int i=0; i < num_filmes; ++i) {
		fprintf(f, "%d\n", filmes[i].id_filme);
		fprintf(f, "%s\n", filmes[i].nome);
		fprintf(f, "%d\n", filmes[i].faixa_etaria);
		fprintf(f, "%s\n", filmes[i].estilo);
	}
	fclose(f);
	return 1;
}
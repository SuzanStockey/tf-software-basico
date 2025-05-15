#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filmes.h"

static filme_t filmes[MAX_FILMES];
static int num_filmes = 0; //static = só consigo acessar essa variável dentro do arquivo (semelhante ao private de java)

int filmes_menor (filme_t *a1, filme_t *a2) {
	if( strcmp(a1->nome, a2->nome) < 0) return -1;
	if( strcmp(a1->nome, a2->nome) > 0) return 1;
	return 0;
}

int filmes_carrega (char *nome_arq) {
	FILE *f = fopen(nome_arq,"r");
	if (f == NULL) return 0;
	
	char linha[TAM_NOME+1];
	while (1) {
		if(num_filmes >= MAX_FILMES) break;
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		filmes[num_filmes].id_filme = atoi(linha); //atoi = conversor de string para inteiro
		if(fgets(filmes[num_filmes].nome, TAM_NOME+1, f) == NULL) break; // essa linha já adiciona o valor direto dentro do nome, sem precisar converter, pois ambos são string. É necessário, nesse caso, fazer o processamento do \n, que vem ao final de todas as linhas
		int tam = strlen(filmes[num_filmes].nome);
		if(filmes[num_filmes].nome[tam-1] =='\n') {
			filmes[num_filmes].nome[tam-1] ='\0';
		}
		//FAZER PARA OS OUTROS DADOS (DATA DE NASCIMENTO E MORTE)
		if(fgets(linha, TAM_NOME+1, f) == NULL) break; //verifica linha a linha, cada linha é uma info...
		filmes[num_filmes].id_filme = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		filmes[num_filmes].id_filme = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		filmes[num_filmes].id_filme = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		filmes[num_filmes].id_filme = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		filmes[num_filmes].id_filme = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		filmes[num_filmes].id_filme = atoi(linha);
		
		
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

//TODO - FEITO
void filmes_mostra_filme(filme_t *filme){
	if(filme->faixa_etaria == 0){
          //Besouro Azul [1] - LIVRE - Ação
		printf("%s [%d] - LIVRE - %s\n", filme->nome, filme->id_filme, filme->estilo);
	} else {
		// Besouro Azul [1] - 14 anos - Ação
		printf("%s [%d] - %d anos - %s\n", filme->nome, filme->id_filme, filme-> faixa_etaria, filme->estilo);
	}
}

//TODO - FEITO
void filmes_mostra(){
	for (int i=0; i<num_filmes; ++i) {
		filmes_mostra_filme( &filmes[i] );
	}
}

void filmes_ordena() {
	// Professor implementou o selection sort, mas posso fazer qualquer que eu queira.
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
	//TODO - PERGUNTAR AO PROFESSOR SE NA SAÍDA A FAIXA ETÁRIA 0 DEVE SER NUMÉRICA OU COM O "LIVRE" NO LUGAR
	FILE *f = fopen(nome_arq, "w");
	if(f ==NULL) return 0;

	for (int i=0; i < num_filmes; ++i) {
		fprintf(f, "%d\n", filmes[i].id_filme);
		fprintf(f, "%s\n", filmes[i].nome);
		fprintf(f, "%d\n", filmes[i].faixa_etaria);
		fprintf(f, "%s\n", filmes[i].estilo);
	}
	fclose(f);
	return 1;
}
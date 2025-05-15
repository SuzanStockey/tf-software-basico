#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atores.h"

static ator_t atores[MAX_ATORES];
static int num_atores = 0; //static = só consigo acessar essa variável dentro do arquivo (semelhante ao private de java)

int atores_menor (ator_t *a1, ator_t *a2) {
	if( strcmp(a1->nome, a2->nome) < 0) return -1;
	if( strcmp(a1->nome, a2->nome) > 0) return 1;
	return 0;
}

int atores_carrega (char *nome_arq) {
	FILE *f = fopen(nome_arq,"r");
	if (f == NULL) return 0;
	
	char linha[TAM_NOME+1];
	while (1) {
		if(num_atores >= MAX_ATORES) break;
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		atores[num_atores].id_ator = atoi(linha); //atoi = conversor de string para inteiro
		if(fgets(atores[num_atores].nome, TAM_NOME+1, f) == NULL) break; // essa linha já adiciona o valor direto dentro do nome, sem precisar converter, pois ambos são string. É necessário, nesse caso, fazer o processamento do \n, que vem ao final de todas as linhas
		int tam = strlen(atores[num_atores].nome);
		if(atores[num_atores].nome[tam-1] =='\n') {
			atores[num_atores].nome[tam-1] ='\0';
		}
		//FAZER PARA OS OUTROS DADOS (DATA DE NASCIMENTO E MORTE)
		if(fgets(linha, TAM_NOME+1, f) == NULL) break; //verifica linha a linha, cada linha é uma info...
		atores[num_atores].id_ator = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		atores[num_atores].id_ator = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		atores[num_atores].id_ator = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		atores[num_atores].id_ator = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		atores[num_atores].id_ator = atoi(linha);
		if(fgets(linha, TAM_NOME+1, f) == NULL) break;
		atores[num_atores].id_ator = atoi(linha);
		
		
		++num_atores;
	}
	
	fclose(f);
	return 1;
	
}

int atores_num_ators() {
	return num_atores;
}

ator_t *atores_obtem_ator_id(int id){
	for (int i=0; i<num_atores; ++i) {
		if(atores[i].id_ator ==id) {
			return &atores[i];
		}
	}
	return 0;
}

ator_t *atores_obtem_ator_indice(int indice){
	if(indice < 0 || indice >=num_atores) return NULL;
	return &atores[indice];
}

void atores_mostra_ator(ator_t *ator){
	if(ator->morte.dia == -1){
		printf("[%d] %s (* %02d/%02d/%02d)\n", ator->id_ator, ator->nome, ator->nascimento.dia, ator->nascimento.mes, ator->nascimento.ano);
	} else{
		printf("[%d] %s (* %02d/%02d/%02d;+ %02d/%02d/%02d)\n", ator->id_ator, ator->nome, ator->nascimento.dia, ator->nascimento.mes, ator->nascimento.ano, ator->morte.dia, ator->morte.mes, ator->morte.ano);
	}
}

void atores_mostra(){
	for (int i=0; i<num_atores; ++i) {
		atores_mostra_ator( & atores[i]);
	}
}

void atores_ordena() {
	// Professor implementou o selection sort, mas posso fazer qualquer que eu queira.
	for (int i=0; i<num_atores; ++i) {
		int menor = i;
		for (int j= i+1; j < num_atores; ++j) {
			if(atores_menor (&atores[j], &atores[menor]) < 0)
				menor = j;
		}
		if(menor != i) {
			ator_t aux = atores[menor];
			atores[menor] = atores[i];
			atores[i] = aux;
		}
	}
}

int atores_salva(char *nome_arq){
	
	FILE *f = fopen(nome_arq, "w");
	if(f ==NULL) return 0;

	for (int i=0; i < num_atores; ++i) {
		fprintf(f, "%d\n", atores[i].id_ator);
		fprintf(f, "%s\n", atores[i].nome);
		fprintf(f, "%d\n%d\n%d\n", atores[i].nascimento.dia, atores[i].nascimento.mes, atores[i].nascimento.ano);
		fprintf(f, "%d\n%d\n%d\n", atores[i].morte.dia, atores[i].morte.mes, atores[i].morte.ano);
	}
	fclose(f);
	return 1;
}
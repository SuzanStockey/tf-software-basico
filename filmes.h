#define TAM_NOME 60
#define MAX_FILMES 100

typedef struct {
	int id_filme;
	char nome[TAM_NOME+1];
	int faixa_etaria;
	char estilo[TAM_NOME+1];
} filme_t;

int     filmes_menor(filme_t *f1, filme_t *f2); //FEITO
int     filmes_carrega (char *nome_arq);		//FEITO
int     filmes_num_filmes();					//FEITO
filme_t *filmes_obtem_filme_id(int id);			//FEITO
filme_t *filmes_obtem_filme_indice(int indice);	//FEITO
void    filmes_mostra_filme(filme_t *filme);	//FEITO
void    filmes_mostra();						//FEITO
void    filmes_ordena();						//FEITO
int     filmes_salva(char *nome_arq);			//TODO - PERGUNTAR AO PROFESSOR SE NA SAÍDA A FAIXA ETÁRIA 0 DEVE SER NUMÉRICA OU COM O "LIVRE" NO LUGAR

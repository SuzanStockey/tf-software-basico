#define TAM_NOME 60
#define MAX_FILMES 100
#define TAM_ESTILO 50

typedef struct {
	int id_filme;
	char nome[TAM_NOME+1];
	int faixa_etaria;
	char estilo[TAM_ESTILO+1];
} filme_t;

int     filmes_menor(filme_t *f1, filme_t *f2);
int     filmes_carrega (char *nome_arq);
int     filmes_num_filmes();
filme_t *filmes_obtem_filme_id(int id);
filme_t *filmes_obtem_filme_indice(int indice);
void    filmes_mostra_filme(filme_t *filme);
void    filmes_mostra();
void    filmes_ordena();
int     filmes_salva(char *nome_arq);
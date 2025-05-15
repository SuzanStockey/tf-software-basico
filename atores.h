#define TAM_NOME 60
#define MAX_ATORES 100

typedef struct {
	int dia,mes, ano;
} data_t;

typedef struct {
	int id_ator;
	char nome[TAM_NOME+1];
	data_t nascimento;
	data_t morte;
} ator_t;

int		atores_menor(ator_t *f1, ator_t *f2);
int atores_carrega (char *nome_arq);
int atores_num_ators();
ator_t *atores_obtem_ator_id(int id);
ator_t *atores_obtem_ator_indice(int indice);
void atores_mostra_ator(ator_t *ator);
void atores_mostra();
void atores_ordena();
int atores_salva(char *nome_arq);
#define TAM_NOME 60
#define TAM_CEP 10
#define TAM_ESTADO 3
#define TAM_CIDADE 40
#define TAM_LOGRADOURO 60
#define TAM_COMPLEMENTO 40
#define TAM_BAIRRO 40
#define MAX_CINEMAS 50


typedef struct {
	int id_cinema;
	char nome[TAM_NOME+1];
	char logradouro[TAM_LOGRADOURO+1];
	int numero;
	char complemento[TAM_COMPLEMENTO+1];
	char bairro[TAM_BAIRRO+1];
	char cep[TAM_CEP+1];
	char cidade[TAM_CIDADE+1];
	char estado[TAM_ESTADO+1];
	int num_salas;
} cinema_t;

int	cinemas_menor(cinema_t *c1, cinema_t *c2);
int cinemas_carrega (char *nome_arq);
int cinemas_num_cinemas();
cinema_t *cinemas_obtem_cinema_id(int id);
cinema_t *cinemas_obtem_cinema_indice(int indice);
void cinemas_mostra_cinema(cinema_t *cinema);
void cinemas_mostra();
void cinemas_ordena();
int cinemas_salva(char *nome_arq);

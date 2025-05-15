// app3.c (Roland Teodorowitsch; 18 maio 2024)

#include <stdio.h>
#include "programacao.h"

int main() {
  if ( !filmes_carrega("filmes.txt") ) return 0;
  if ( !cinemas_carrega("cinemas.txt") ) return 0;
  cinemas_ordena();
  if ( !programacao_carrega("programacao.txt") ) return 0;
  printf("----------\n");
  programacao_mostra();
  printf("----------\n");
  return 0;
}

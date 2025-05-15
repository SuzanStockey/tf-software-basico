// app1.cpp (Roland Teodorowitsch; 17 maio 2024)

#include <stdio.h>
#include "filmes.h"

int main() {
  if ( !filmes_carrega("filmes.txt") ) return 0;
  printf("----------\n");
  filmes_mostra();
  filmes_ordena();
  if ( !filmes_salva("filmes.txt.out") ) return 0;
  printf("----------\n");
  filmes_mostra();
  printf("----------\n");
  return 0;
}

// app2.c (Roland Teodorowitsch; 17 maio 2024)

#include <stdio.h>
#include "cinemas.h"

int main() {
  if ( !cinemas_carrega("cinemas.txt") ) return 0;
  printf("----------\n");
  cinemas_mostra();
  cinemas_ordena();
  if ( !cinemas_salva("cinemas.txt.out") ) return 0;
  printf("----------\n");
  cinemas_mostra();
  printf("----------\n");
  return 0;
}

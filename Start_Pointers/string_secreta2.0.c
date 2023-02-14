#include <stdio.h>
#include <string.h>

int main()
{
  int entrada;

  while (scanf("%x", &entrada) == 1){ //%x número na base hexadecimal
    char *ponteiro = &entrada;

    printf("%s\n", ponteiro);
  }
}


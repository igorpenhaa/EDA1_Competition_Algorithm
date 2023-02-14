#include <stdio.h>
#include <string.h>

int main()
{
  int entrada;

  while (scanf("%x", &entrada) != EOF){ //%x número na base hexadecimal
    char *ponteiro = &entrada;

    for(int i = 0; i < 4; ++i){
      if(ponteiro[i] == 0){
        printf("\n"); 
        return 0;
      }
      
      printf("%c", ponteiro[i]);
    }
  }
}


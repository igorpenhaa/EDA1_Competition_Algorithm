#include <stdio.h>
#include <string.h>

int main(){
  //Atributos: 
  int num_linhas = 0, linha = 0, coluna = 0;
  char sobe_desce, buff;

  scanf("%d", &num_linhas);
  char str[num_linhas+1][1002];
  
  scanf("%c", &buff);
  for(int i = 0; i < num_linhas; ++i){
    fgets(str[i], 1002, stdin);
    str[i][strlen(str[i])-1] = '\0';
  }
  
  scanf("%d %d", &linha, &coluna);
  linha = linha -1;
  coluna = coluna -1;

  while(scanf("%c", &sobe_desce) != EOF){
    if(sobe_desce == 'j'){
      if(linha == num_linhas - 1){
        if(strlen(str[linha]) >= coluna + 1){
          printf("%d %d %c\n", linha+1, coluna+1, str[linha][coluna]);
        }else if(strlen(str[linha]) < coluna + 1){
          printf("%d %d %c\n", linha+1, strlen(str[linha]), str[linha][strlen(str[linha])-1]);
        }
      }else{
        if(strlen(str[linha+1]) >= coluna + 1){
          linha = linha + 1;
          printf("%d %d %c\n", linha+1, coluna+1, str[linha][coluna]);
        }else if(strlen(str[linha+1]) < coluna + 1){
          linha = linha + 1;
          printf("%d %d %c\n", linha+1, strlen(str[linha]), str[linha][strlen(str[linha])-1]);
        }
      }
    }else if(sobe_desce == 'k'){
      if(linha == 0){
        if(strlen(str[linha]) >= coluna + 1){
          printf("%d %d %c\n", linha+1, coluna+1, str[linha][coluna]);
        }else if(strlen(str[linha]) < coluna + 1){
          printf("%d %d %c\n", linha+1, strlen(str[linha]), str[linha][strlen(str[linha])-1]);
        }
      }else{
        if(strlen(str[linha-1]) >= coluna + 1){
          linha = linha - 1;
          printf("%d %d %c\n", linha+1, coluna+1, str[linha][coluna]);
        }else if(strlen(str[linha-1]) < coluna + 1){
          linha = linha - 1;
          printf("%d %d %c\n", linha+1, strlen(str[linha]), str[linha][strlen(str[linha])-1]);
        }
      }
    }
  }

  return 0;
}
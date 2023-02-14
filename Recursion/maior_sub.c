#include<stdio.h>
#include<string.h>

int find(char *str, char *sub){
  if(*sub == '\0'){
    return 0;
  }

  if(*str != *sub){
    return -1;
  }

  return find(str+1, sub+1);
}

//retorna a posicao no vetor em que comeca a primeira aparicao da substring
int primeira_sub(char *str, char *sub, int index){
  if(*str != '\0'){

    int a = -1;
    a = find(str, sub);
    
    if(a == 0){
      return index;
    }
    
    index++;
    return primeira_sub(str+1, sub, index);
    
  }else{
    return -1;
  }
}


//retorna a posicao no vetor em que comeca a ultima aparicao da substring
int ultima_sub(char *str, char *sub, int index){
  int a = -1;
  a = find(str, sub);
  
  if(a >= 0){
    return index;
  }
  index--;

  return ultima_sub(str-1, sub, index);
}

int main(void){

  char str[101];
  char sub[101];
  scanf("%s", str);
  scanf("%s", sub);
  int comeco = 0, fim = 0;
  comeco = primeira_sub(str, sub, 0);
  if(comeco != -1){
    fim = ultima_sub(&str[strlen(str)], sub, strlen(str));
    printf("%d\n", fim - comeco + strlen(sub));
  }else{
    printf("0\n");
  }

  return 0;
}

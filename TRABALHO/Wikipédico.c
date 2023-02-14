#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct{
  Item *v;
  int topo;
  int size;
}pilha_st;


int inicializaPilha(pilha_st *p, int s){
  p->v = malloc(sizeof(Item)*s); 
  if(p->v == NULL){
    return 0;
  }

  p->size = s;
  p->topo = 0;
  return 1;
}

int empilhar(pilha_st *p, Item e){
  if(p->size == p->topo){
    return 0;
  }

  p->v[p->topo++] = e;
  return 1;
}

int estaVazia(pilha_st *p){
  return p->topo == 0;
}

Item topo(pilha_st *p){
  return p->v[p->topo-1];
}

void desempilha(pilha_st *p){
  p->topo--;
}


int main(void){
  int t;
  scanf("%d", &t);
  pilha_st p;
  inicializaPilha(&p, t*100002);

  for(int i = 0; i < t; i++){
    char str[100002];
    scanf(" %[^\n]", str);

    int j = 0;
    while(str[j] != '\0'){
      if(str[j] == '*'|| str[j] == '/' || str[j] == '_'){
        if(estaVazia(&p) == 1){
          empilhar(&p, str[j]);
        }else if(topo(&p) == str[j]){
          desempilha(&p);
        }else{
          empilhar(&p, str[j]);
        }
      }
        
      j++;
    }
  }
  
  if(estaVazia(&p) == 1){
    printf("C\n");
  }else{
    printf("E\n");
  }

  return 0;
}

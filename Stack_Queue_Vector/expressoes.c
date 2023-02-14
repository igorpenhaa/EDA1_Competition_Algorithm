#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int empilha(pilha_st *p, Item e){
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
  char str[100002];
  for(int i = 0; i < t; i++){
    scanf("%s", str);
    int j = 0;
    pilha_st p;
    inicializaPilha(&p, strlen(str));
    while(str[j] != '\0'){
      if(str[j]=='{' || str[j]=='[' || str[j]=='('){
        empilha(&p, str[j]);
      }else if(str[j] =='}'){
        if(topo(&p) == '{'){
          desempilha(&p);
        }else{
          empilha(&p, str[j]);
          break;
        }
      }else if(str[j] ==']'){
        if(topo(&p) == '['){
          desempilha(&p);
        }else{
          empilha(&p, str[j]);
          break;
        }
      }else if(str[j] ==')'){
        if(topo(&p) == '('){
          desempilha(&p);
        }else{
          empilha(&p, str[j]);
          break;
        }
      }
      j++;
    }

    if(estaVazia(&p) == 1){
      printf("S\n");
    }else{
      printf("N\n");
    }
  }


  return 0;
}

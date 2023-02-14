#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *Item;

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
  return p->v[p->topo]-1;
}

void desempilha(pilha_st *p){
  printf("%s\n", p->v[p->topo-1]);
  p->topo--;
}

int main(void){

  pilha_st p;
	inicializaPilha(&p, 1000);
	char op[9];
	
  while (scanf("%s", op) != EOF) {
    char *str = malloc(sizeof(char)*101);
		if (strcmp(op, "inserir") == 0) {
      scanf(" %[^\n]", str);
      empilhar(&p, str);
		} else if (strcmp(op, "desfazer") == 0){
      if(p.topo == 0){
        printf("NULL\n");
      }else{
        desempilha(&p);
      }
    }
  }

  return 0;
}

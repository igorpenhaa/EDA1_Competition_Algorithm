#include <stdio.h>
#include <stdlib.h>

typedef int Item;

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

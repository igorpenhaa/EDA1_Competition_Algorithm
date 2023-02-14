#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct{
  char v;
  Item e;
  no_st *ant, *prox;
}no_st;

typedef struct{
  no_st *inicio;
  no_st fim;
  int *no_count;
}cabeca_st;

no_st *criaNovoNo(Item e){
  no_st *novo = malloc(sizeof(no_st));
  if(novo == NULL) return NULL;
  novo->e = e;
  novo->prox = NULL;
  novo->ant = NULL;
  novo->v = 2;
  return novo;
}

int insereInicio(cabeca_st *h, Item e){
  no_st *novo = malloc(sizeof(no_st));

  if(novo == NULL) return 0;

  novo->e = e;
  novo->ant = NULL;
  novo->prox = h->inicio;
  h->inicio->ant = novo;
  h->inicio = novo;
  h->no_count++;

  return 1;
}

void removeInicio(cabeca_st *h){
  h->inicio = h->inicio->prox;
  h->no_count--;
}

int insereDepois(cabeca_st *h, no_st *c, Item e){
  no_st *novo = criaNovoNo(e);

  if(novo == NULL)return 0;

  if(c->prox != NULL){
    c->prox->ant = novo;
    novo->prox = c->prox;
    novo->ant = c;
    c->prox = novo;
    h->no_count++;
  }else{
    novo->prox = NULL;
    novo->ant = c;
    c->prox = novo;
    h->no_count++;
  }

  return 1;
}

int insereAntes(cabeca_st *h, no_st *c, Item e){
  no_st *novo = criaNovoNo(e);

  if(novo == NULL) return 0;

  if(c->ant != NULL){
    c->ant->prox = novo;
    novo->ant = c->ant;
    novo->prox = c;
    c->ant = novo;
    h->no_count++;
  }else{
    insereInicio(h, e);
  }
}

void removeNo(cabeca_st *h, no_st *rm){
  if(h->inicio == rm){removeInicio(h); return;}

  no_st *aux = h->inicio;
  while(aux->prox != rm){
    aux = aux->prox;
  }

  aux->prox = rm->prox;
  free(rm);
}

int Saudavel(no_st *A, no_st *B){
  if(A->prox == A || B->ant == B) return 0;
  while(A!=B){
    if(A->prox->ant != A || A->prox == NULL|| A->v == 1) return 0;

    A->v = 1;
    A = A->prox;
  }

  return 1;
}

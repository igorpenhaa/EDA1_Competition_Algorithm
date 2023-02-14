#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct{
  Item *v;
  int size;
  int inicio;
  int fim;
  int ocupados;
}fila_st;

int inicializa_fila(fila_st *f, int s){
  f->v = malloc(sizeof(Item)*s);
  f->size = s;
  f->inicio = -1;
  f->fim = 0;
  f->ocupados = 0;

  return 1;
}

int enfila(fila_st *f, Item e){
  if(f->ocupados >= f->size) return 0;
  f->v[f->fim] = e;
  f->fim = (f->fim + 1) % f->size;
  f->ocupados ++;
}

Item espia(fila_st *f){
  return f->v[(f->inicio+1)%f->size];
}

void desenfila(fila_st *f){
  f->ocupados--;
  f->inicio = f->inicio+1 % f->size;
}

int esta_vazia(fila_st *f){
  return f->ocupados == 0;
}


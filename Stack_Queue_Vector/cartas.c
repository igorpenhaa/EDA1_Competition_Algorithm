#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct{
  Item *v;
  int inicio;
  int fim;
  int size;
  int ocupado;
}fila_st;

int inicializaFila(fila_st *f, int s){
  f->v = malloc(sizeof(Item)*s);
  if(f->v == NULL) return 0;
  f->fim = 0;
  f->inicio = -1;
  f->size = s;
  f->ocupado = 0;

  return 1;
}

int enfila(fila_st *f, Item e){
  if(f->ocupado >= f->size) return 0;
  f->v[f->fim] = e;
  f->fim = (f->fim+1) % f->size;
  f->ocupado++;

  return 1;
}

int estaVazia(fila_st *f){
  return f->ocupado == 0;
}

int tem1(fila_st *f){
  if(f->ocupado == 1)return 1;
  else return 0;
}

int desenfila(fila_st *f){
  if(estaVazia == 0) return 0;
  f->ocupado--;
  f->inicio = (f->inicio+1) % f->size;
}

Item espia(fila_st *f){
  return f->v[(f->inicio+1)%f->size];
}


int main(void){

  int n, i = 0;
  fila_st f, descarte;
  scanf("%d", &n);
  inicializaFila(&f, n);
  inicializaFila(&descarte,n-1);

  for(int i = 1; i<=n; i++){
    enfila(&f, i);
  }

  while(tem1(&f) != 1){
    Item y = espia(&f);
    desenfila(&f);
    if(i%2 == 0){
      enfila(&descarte, y);
    }else{
      enfila(&f, y);
    }
    i++;
  }

  printf("Cartas descartadas: %d", espia(&descarte));
  desenfila(&descarte);
  for(int j = 0; j < n-2; j++){
    printf(", %d", espia(&descarte));
    desenfila(&descarte);
  }
  printf("\n");

  printf("Carta restante: %d\n", espia(&f));

  return 0;
}

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


int main(void){
  
  int part, rod, index = 1;
  scanf("%d %d", &part, &rod);
  fila_st f;

  while(part!=0 || rod != 0){
    int xi[part];

    inicializa_fila(&f, part);

    for(int i = 0; i < part; i++){
      scanf("%d", &xi[i]);
      enfila(&f, xi[i]);
    }

    int numPar, ordem, ai[part];
    for(int j = 0; j<rod; j++){
      int k = 0;
      scanf("%d %d", &numPar, &ordem);
      for(int l=0; l<numPar; l++){
        Item y = espia(&f);
        desenfila(&f);
        scanf("%d", &ai[l]);
        if(ai[l] == ordem){
          enfila(&f, y);
        }
      }
    }

    printf("Teste %d\n", index);
    printf("%d\n", espia(&f));
    index++;
    scanf("%d %d", &part, &rod);
  }


  return 0;
}


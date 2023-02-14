#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int value;
  int id;
  int next;
}Item;

typedef struct no_st no_st;

struct no_st{
  Item e;
  no_st *prox;
};

typedef struct{
  no_st *inicio;
  int no_count;
  no_st *ultimo;
}cabeca_st;

int inicializaLista(cabeca_st *h){
  h->inicio = NULL;
  h->ultimo = NULL;
  h->no_count = 0;
  return 1;
}

int insere_inicio(cabeca_st *h, Item e){
  no_st *novo = malloc(sizeof(no_st));

  if(novo == NULL) return 0;

  novo->e = e;
  novo->prox = h->inicio;

  h->inicio = novo;
  h->no_count++;

  return 1;
}

void removeInicio(cabeca_st *h){
  printf("%d\n", h->inicio->e.value);
  h->inicio = h->inicio->prox;
  h->no_count--;
  return;
}

int main(void){
  int n;
  scanf("%d", &n);
  Item item[n];

  cabeca_st h;
  inicializaLista(&h);

  for(int i = 0; i<n; i++){
    scanf("%d %d %d", &item[i].id, &item[i].value, &item[i].next);
    if(item[i].next == -1){
      insere_inicio(&h, item[i]);
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(item[j].next == h.inicio->e.id){
        insere_inicio(&h, item[j]);
      }
    }
  }

  for(int i = 0; i < n; i++){
    removeInicio(&h);
  }

  return 0;

}




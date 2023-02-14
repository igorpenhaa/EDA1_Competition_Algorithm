#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define eq(A,B) (key(A) == key(B))
#define NULLITEM (no_st){NULL, 0}
#define less(A,B) (key(A->e) < key(B->e))
#define exch(A,B){int t=A->e; A->e=B->e; B->e=t;}
#define compexch(A,B){if(less(B,A)){exch(A,B)}}

typedef int Item;

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

Item removeInicio(cabeca_st *h){
  no_st *ts_remove = h->inicio;
  h->inicio = h->inicio->prox;
  Item rem = ts_remove->e;
  free(ts_remove);
  h->no_count--;
  return rem;
}

int insereDepois(no_st *no, Item e){
  no_st *novono = malloc(sizeof(no_st));
 
  if(novono == NULL) return 0;
  
  novono->e = e;
  novono->prox = no->prox;
  no->prox = novono->prox;
  
  return 1;
}

int insereDepoisN(cabeca_st *h, Item e, int p){
  int i = 0;
  no_st *aux = h->inicio;
  while(i<p && aux->prox != NULL){
    aux = aux->prox;
    i++;
  }

  if(insereDepois(aux, e) == 0) return 0;

  h->no_count ++;
  return 1;
}

no_st *busca_lista(cabeca_st *h, Item b){
  no_st *aux = h->inicio;
  
  while(aux != NULL && !eq(b, aux->e)){
    aux = aux->prox;
  }

  //if(aux == NULL) return NULLITEM;

  return aux;
}

int insereDepoisItem(cabeca_st *h, Item c, Item e){
  no_st *a = busca_lista(h, c);
  return insereDepois(a,e);
}

void removeElemento(cabeca_st *h, no_st *r){
  if(r == h->inicio){removeInicio(h); return;}

  no_st *aux = h->inicio;

  while(aux->prox != r){
    aux = aux->prox;
  }

  aux->prox = r->prox;
  free(r);
}

void imprimeLista(cabeca_st *h){
  for(int i = 0; i < h->no_count; i++){
    printf("%d", h->inicio->e);
    h->inicio = h->inicio->prox;
  }
  printf("\n");
  return;
}

void bubleSort(cabeca_st *h, int l, int r){
  no_st *aux = h->inicio;
  no_st *aux2 = aux->prox;
  printf("%d %d\n", aux->e, aux2->e);
  for(int i=l; i<r; i++){
    for(int j=l; j<r; j++){
      compexch(aux2, aux);
      aux = aux2;
      aux2 = aux2->prox;
      //compexch(v[j+1],v[j]);
    }
  }
}

int main(void){
  cabeca_st h;
  inicializaLista(&h);
  Item b = 8, c = 7, d = 6, e = 5, i = 1;
  insere_inicio(&h, i);
  insere_inicio(&h, e);
  insere_inicio(&h, d);
  insere_inicio(&h, c);
  insere_inicio(&h, b);

  bubleSort(&h, 0, h.no_count);
  //imprimeLista(&h);

}


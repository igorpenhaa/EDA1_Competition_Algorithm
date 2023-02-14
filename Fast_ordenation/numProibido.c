#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Item t=A; A=B; B=t;}
#define compexch(A,B){if(less(B,A)) exch(A,B);}

int BB(Item *v, int l, int r, int x){

  if(v[l] == x){
    return l;
  }
  
  while(l < r-1){
    int m = l + (r-l)/2;
    
    if(less(v[m], x)){
      l = m;
    }else{
      r = m;
    }
  }

  return r;
}

void merge(Item *v, int l, int m, int r){
  int ia = l, ib = m+1;
  Item *aux = malloc(sizeof(Item) * (r-l+1));
  int iaux = 0, j = 0;

  while(ia <= m && ib <= r){
    if(less(v[ia], v[ib])){
      aux[iaux++] = v[ia++];
    }else{
      aux[iaux++] = v[ib++];
    }
  }

  while(ia <= m){
    aux[iaux++] = v[ia++];
  }

  while(ib <= r){
    aux[iaux++] = v[ib++];
  }

  for(int i = l; i <= r; i++){
    v[i] = aux[j++];
  }
}

void mergeSort(Item *v, int l, int r){
  if(l >= r){
    return;
  }

  int m = l + (r-l)/2;
  mergeSort(v, l, m);
  mergeSort(v, m+1, r);
  merge(v, l, m, r);
}

/*
void insertionSort(Item *v, int l, int r){

  for(int i = r; i > l; i--){
    compexch(v[i-1], v[i]);
  }

  for(int i = l+2; i<=r; i++){
    Item m = v[i];
    int j = i;

    while(less(m, v[j-1])){
      v[j] = v[j-1];
      j--;
    }

    v[j] = m;
  }
}
*/


int main(void){
  int n;
  scanf("%d", &n);
  int numProibidos[n], procura;

  for(int i = 0; i < n; i++){
    scanf("%d", &numProibidos[i]);
  }

  mergeSort(numProibidos, 0, n-1);

  while(scanf("%d", &procura) == 1){
    if(numProibidos[BB(numProibidos, 0, n-1, procura)] == procura){
      printf("sim\n");
    }else{
      printf("nao\n");
    }
  }

  return 0;
}
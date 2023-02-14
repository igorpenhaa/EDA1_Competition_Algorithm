#include<stdio.h>

//premissa: o vetor de l ate m e de m+1 ate r ambos devem estar ordenados

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Item t=A; A=B; B=t;}
#define cmpexch(A,B){if(less(A,B)) exch(A,B);}

void merge(Item *v, int l, int r){
  int m = (l+r)/2;
  int ia = l, ib = m+1; 
  Item *aux[r-l+1];
  int iaux = 0;

  while(ia<=m && ib<=r){
    if(less(v[ib], v[ia])){
      aux[iaux++] = v[ib++];
    }else{
      aux[iaux++] = v[ia++];
    }
  }

  while(ia<=m){
    aux[iaux++] = v[ia++];
  }

  while(ib<=r){
    aux[iaux++] = v[ib++];
  }

  iaux = 0;

  for(int i = l; i <= r; i++){
    v[i] = aux[iaux++];
  }
}

void mergeSort(Item *v, int l, int r){
  if(l >= r) return;

  int m = (l+r)/2;
  mergeSort(v,l,m);
  mergeSort(v,m+1,r);
  merge(v,l,r);
}

int main(void){

  int num[1000], i=0;

  while(scanf("%d", &num[i]) == 1){
    i++;
  }

  mergeSort(&num[0], 0, i-1);

  for(int j = 0; j < i; j++){
    printf("%d ", num[j]);
  }

  printf("\n");

  return 0;
}

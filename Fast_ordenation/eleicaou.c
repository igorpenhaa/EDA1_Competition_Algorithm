#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int num;
  int qnt;
}Item;

#define key(A) (A)
#define lesseq(A,B) (key(A) <= key(B))
#define less(A,B) (key(A) < key(B))
#define bigeq(A,B) (key(A) >= key(B))
#define big(A,B) (key(A) > key(B))
#define lesss(A,B) (key(A.qnt) < key(B.qnt))
#define exch(A,B){Item t = A; A = B; B = t;}
#define compexch(A,B){if(lesss(B,A)){exch(A,B);}}

int BB(Item *v, int l, int r, int x){
  while(l <= r){
    int m = l + (r-l)/2;
    
    if(x==v[m].num){return m;}

    if(less(x, v[m].num)){
      l = m+1;
    }else{
      r = m-1;
    }
  }

  return -1;
}

void insertionSort(Item *v, int l, int r){
 
  for(int i = r; i > l; i--){
    if(big(v[i].qnt, v[i-1].qnt)){
      exch(v[i], v[i-1]);
    }
  }
  
  for(int i = l+2; i <= r; i++){
    int j = i; 
    Item m = v[j];

    while(big(m.qnt,v[j-1].qnt)){
      v[j] = v[j-1];
      j--;
    }

    v[j] = m;
  }
}

void merge(Item *v, int l, int r, int m){
  Item *v3 = malloc(sizeof(Item)*(r-l+1));
  int ia = l, ib = m+1, iaux = 0, j = 0;
  while(ia <= m && ib <= r){
    if(big(v[ia].num, v[ib].num)){
      v3[iaux++] = v[ia++];
    }else{
      v3[iaux++] = v[ib++];
    }
  }

  while(ia<=m){
    v3[iaux++] = v[ia++];
  }

  while(ib<=r){
    v3[iaux++] = v[ib++];
  }

  for(int i = 0; i < iaux; i++){
    v[i] = v3[j++];
  }

  free(v3);
}

int main(void){
  int sen, depf, depe, voto, i = 0, invalidos = 0, l = 0;
  Item v[150000];

  scanf("%d %d %d", &sen, &depf, &depe);

  while(scanf("%d", &voto) == 1){
    if(voto < 0){
      invalidos ++;
    }else if(voto > 0){
      l++;
      int x = BB(v, 0, i-1, voto);
      if(x == -1){
        v[i].num = voto;
        v[i].qnt = 1;
        merge(v, 0, i, i-1);
        i++;
      }else{
        v[x].qnt ++;
      }
    }
  }

  printf("%d %d\n", l, invalidos);

  int m = 0, n, p, q, j = 0;

  // for(int k = 0; k < i; k ++){
  //   printf("num: %d ", v[k].num);
  // }
  // printf("\n");

  while(v[j].num/10000 != 0){
    j++;
  }
  
  insertionSort(v, 0, j-1);

  n = j;
  while(v[j].num/1000 != 0){
    j++;
  }

  insertionSort(v, n, j-1);

  p = j;
  while(v[j].num/100 != 0){
    j++;
  }

  insertionSort(v, p, j-1);

  q = j;

  insertionSort(v, q, i-1);

  int y = v[q].qnt * 100;
  int soma = 0;
  
  while(j < i){
    soma = soma + v[j].qnt;
    j++;
  }

  // for(int k = 0; k < i; k ++){
  //   printf("num: %d ", v[k].num);
  // }
  // printf("\n");

  y = y/ soma;

  if(big(y, 50)){
    printf("%d\n", v[q].num);
  }else{
    printf("Segundo turno\n");
  }

  for(int k = p; k < (p+sen); k++){
    printf("%d ", v[k].num);
  }
  printf("\n");

  for(int k = n; k < (n+depf); k++){
    printf("%d ", v[k].num);
  }
  printf("\n");

  for(int k = 0; k < depe; k++){
    printf("%d ", v[k].num);
  }
  printf("\n");

  return 0;
}

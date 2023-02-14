#include<stdio.h>
#include<stdlib.h>

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))

int BB(Item *v, int l, int r, int x){
  while(l <= r){
    int m = l + (r-l)/2;
    
    if(x==v[m]){return m;}

    if(less(x, v[m])){
      r = m-1;
    }else{
      l = m+1;
    }
  }

  return -1;
}

Item * mergep(Item *v1, Item *v2, int l1, int r1, int l2, int r2){
  Item *v3 = malloc(sizeof(Item)*(r1-l1+r2-l2+2));
  int aux=0, i1 = l1, i2 = l2;
  while(i1 <= r1 && i2 <= r2){
    if(less(v1[i1], v2[i2])){
      v3[aux++] = v1[i1++];
    }else{
      v3[aux++] = v2[i2++];
    }
  }

  while(i1 <= r1){
    v3[aux++] = v1[i1++];
  }

  while(i2 <= r2){
    v3[aux++] = v2[i2++];
  }

  return v3;
}

void merge(Item *v, int l, int r, int m){
  
  int ia = l, ib = m+1, iaux = 0, j = 0;
  int *aux = malloc(sizeof(Item)*(r-l+1));

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
  if(l > r - 1){
    return;
  }

  int m = l + (r-l)/2;
  mergeSort(v, l, m);
  mergeSort(v, m+1, r);
  merge(v, l, r, m);
}

int main(void){

  int n = 0;
  scanf("%d", &n);
  int v[n+n/2+1];

  for(int i = 0; i<n; i++){
    scanf("%d", &v[i]);
  }

  mergeSort(v, 0, n-1);


  int novoi = 0;
  for(int i = 1; i<n; i++){
    if(v[i] != v[novoi]){
      v[++novoi] = v[i];
    }
  }

  if(novoi % 2 == 0){
    v[++novoi] = 1000000000;
  }


  int *nmu = malloc(sizeof(Item)*(n/2+1));
  int k=-1;
  for(int i = 0; i < novoi; i += 2){
    nmu[++k] = v[i] + v[i+1];
    if(BB(v,0,novoi, nmu[k]) != -1){
      k--;
    }
  }

  int *v2 = mergep(v, nmu, 0, novoi, 0, k);
  free(nmu);


  for(int i = 0; i <= novoi+k+1; i+=4){
    printf("%d\n", v2[i]);
  }

  printf("Elementos: %d\n", novoi+k+2);


  return 0;
}

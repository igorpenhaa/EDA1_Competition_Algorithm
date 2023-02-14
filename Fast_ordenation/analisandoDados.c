#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int posI, tamanhoS;
  char carac;
}Saida;

#define key(A) (A)
#define less(A,B) (key(A) < key(B))

void merge(Saida *v, int l, int r, int m){
  int ia = l, ib = m+1, iv3 = 0, j = 0;
  Saida *v3 = malloc(sizeof(Saida)*(r-l+1));

  while(ia <= m && ib <= r){
    if(less(v[ia].tamanhoS, v[ib].tamanhoS)){
      v3[iv3++] = v[ia++];
    }else{
      v3[iv3++] = v[ib++];
    }
  }

  while(ia<=m){
    v3[iv3++] = v[ia++];
  }

  while(ib<=r){
    v3[iv3++] = v[ib++];
  }

  for(int i = l; i<=r; i++){
    v[i] = v3[j++];
  }

}

void mergeSort(Saida *v, int l, int r){
  if(l > r-1){return;}

  int m = l + (r-l)/2;
  mergeSort(v, l, m);
  mergeSort(v, m+1, r);
  merge(v, l, r, m);
}


int main(void){
  char entrada[100001];
  Saida saida[100001];
  int j = 0, k = -1;

  scanf("%s", entrada);
  //printf("%s\n", entrada);

  while(entrada[j] != '\0'){
    if(entrada[j] == entrada[j-1]){
      saida[k].tamanhoS++;
    }else{
      k++;
      saida[k].tamanhoS = 1;
      saida[k].posI = j;
      saida[k].carac = entrada[j];
      //printf("tamanho: %d, caractere: %c, posicao: %d\n", saida[k].tamanhoS, saida[k].carac, saida[k].posI);
    }

    j++;
  }

  mergeSort(saida, 0, k);

  for(int i = k; i >= 0; i--){
    printf("%d %c %d\n", saida[i].tamanhoS, saida[i].carac, saida[i].posI);
  }
  return 0;
}

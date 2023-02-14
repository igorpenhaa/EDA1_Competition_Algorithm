#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int codigo;
  char keyWord[16];
}Instrucao;
#define key(A) (A.codigo)
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Instrucao t = A; A = B; B = t;}
#define compexch(A,B){if(less(B,A)) exch(A,B);}

buscaBin(Instrucao *v, int l, int r, int x){

  if(v[l].codigo == x){
    return l;
  }

  while(l<r-1){
    int m = l + (r-l)/2;
    if(v[m].codigo < x){
      l = m;
    }else{
      r = m;
    }
  }

  return r;
}

void insertionSort(Instrucao *v, int l, int r){
  for(int i = r; i > l; i--){
    compexch(v[i-1], v[i]);
  }

  for(int i=l+2; i<=r; i++){
    Instrucao q = v[i];
    int j = i;

    while(less(q, v[j-1])){
      v[j] = v[j-1];
      j--;
    }

    v[j] = q;
  }

}

int main(void){

  int n, busca;
  scanf("%d", &n);
  Instrucao bibli[n];

  for (int i = 0; i < n; i++){
    scanf("%d %s", &bibli[i].codigo, &bibli[i].keyWord);
  }

  insertionSort(&bibli[0], 0, n-1);
  
  while(scanf("%d", &busca) == 1){
    int x = buscaBin(bibli, 0, n-1, busca);

    if(bibli[x].codigo == busca){
      printf("%s\n", bibli[x].keyWord);
    }else{
      printf("undefined\n");
    }
  }
  

  return 0;
}

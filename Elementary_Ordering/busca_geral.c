#include <stdio.h>

typedef struct 
{
  /* data */
  int valor;
  int index;
}Dados;

int buscaBin(Dados *v, int l, int r, int procurado){

  if(v[l].valor == procurado){
    return 0;
  }
  
  if(l == r-1){
    return r;
  }
  int m = l + (r-l)/2;

  if(v[m].valor < procurado){
    return buscaBin(v, m, r, procurado);
  }else{
    return buscaBin(v, l, m, procurado);
  }

}

void insertionSort(Dados *v, int l, int r){
 
  for(int i = r; i > l; i--){
    if(v[i].valor < v[i-1].valor){
      Dados t = v[i];
      v[i] = v[i-1];
      v[i-1] = t;
    }
  }
  
  for(int i = l+2; i <= r; i++){
    int j = i; 
    Dados m = v[i];

    while(m.valor < v[j-1].valor){
      v[j] = v[j-1];
      j--;
    }

    v[j] = m;
  }
}

int main(void){

  int m = 0, n = 0, j = 0;
  scanf("%d %d", &n, &m);
  int busca;
  Dados salvos[n];
  
  for(int i = 0; i < n; i++){
    scanf("%d", &salvos[i].valor);
    salvos[i].index = i;
  }

  insertionSort(salvos, 0, n-1);
  
  for(int j = 0; j < m; j++){
    scanf("%d", &busca);

    int x = buscaBin(salvos, 0, n-1, busca);
    
    if(salvos[x].valor == busca){
      printf("%d\n", salvos[x].index);
    }else{
      printf("-1\n");
    }
  }

  return 0;
}

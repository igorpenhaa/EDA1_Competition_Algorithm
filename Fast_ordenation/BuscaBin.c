#include <stdio.h>


int BB(int *v, int l, int r, int x){

  if(v[l] > x){
    return 0;
  }

  if(v[r] < x){
    return r+1;
  }

  while(l < r-1){
    int m = l + (r-l)/2;
    if(v[m] < x){
      l = m;
    }else{
      r = m;
    }
  }

  return r;
}

int main(void){

  int m, n;
  scanf("%d %d", &n, &m);
  int lista[n], busca;

  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }

  for(int i = 0; i < m; i++){
    scanf("%d", &busca);
    printf("%d\n", BB(lista, 0, n-1, busca));
  }

  return 0;
}

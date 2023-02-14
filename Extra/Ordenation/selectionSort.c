#include<stdio.h>

//Algoritimo de ordenacao nao estavel

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Item t = A; A=B; B = t;}

void selectionSort(int *v, int l, int r){
  for(int i = l; i < r; i++){
    int min = i;
    for(int j = i+1; j <= r; j++){
      if(less(v[j], v[min])){
        min = j;
      }
    }
    exch(v[i], v[min]);
  }
}


int main(void){

  int num[1001], i = 0;
  while(scanf("%d", &num[i]) == 1){
    i++;
  }

  selectionSort(&num, 0, i-1);

  for(int j=0; j<i; j++){
    printf("%d ", num[j]);
  }

  printf("\n");

  return 0;
}

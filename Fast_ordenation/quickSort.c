#include <stdio.h>

typedef int Item;
#define key(A) (A)
#define lesseq(A,B) (key(A) <= key(B))
#define less(A,B) (key(A) < key(B))
#define exch(A,B){Item t = A; A = B; B = t;}
#define compexch(A,B){if(less(B,A)){exch(A,B);}}


int separai(Item *v, int l, int r){
  Item p = v[r];
  int i = l-1, j = r;

  for(;;){
    while(less(v[++i], p));
    while(less(p, v[--j])){
      if(j == l) break;
    }
    if(i>=j) break;
    exch(v[i], v[j]);
  }
  exch(v[i], v[r]);

  return i;
}

int separa(Item *v, int l, int r){
  Item p = v[r];
  int i = l;

  for(int k = l; k < r; k++){
    if(lesseq(v[k], p)){
      exch(v[k], v[i]);
      i++;
    }
  }

  exch(v[i], v[r]);

  return i;
}

void quickSort(Item *v, int l, int r){
  if(r <= l) return;

  compexch(v[(l+r)/2], v[r]);
  compexch(v[l], v[(l+r)/2]);
  compexch(v[r], v[(l+r)/2]);

  int j = separa(v, l, r);
  quickSort(v, l, j-1);
  quickSort(v, j+1, r);
}



int main(void){
  int n;
  scanf("%d", &n);
  int v[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  quickSort(v, 0, n-1);

  printf("%d", v[0]);

  for(int i = 1; i < n; i++){
    printf(" %d", v[i]);
  }

  printf("\n");

  return 0;
}

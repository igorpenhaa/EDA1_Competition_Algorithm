#include <stdio.h>

#define key(A) (A)
#define less(A,B) (key(A) < key(B))

typedef struct{
  int e;
  int d;
} bota;

int main(){
  int n;
    
  while (scanf("%d", &n) == 1){
    int par = 0;
    bota bota[60];
    
    for (int i = 30; i < 61; i++){
      bota[i].d = 0;
      bota[i].e = 0;
    }

    for (int i = 0; i < n; i++){
      int num;
      char pe;
      scanf("%d %c", &num, &pe);
      
      if(pe == 'D'){
        bota[num].d++;
      }
      else{
        bota[num].e++;
      }
    }

    for (int i = 30; i < 61; i++){
      if(less(bota[i].e, bota[i].d)){
        par += bota[i].e;
      }else{
        par += bota[i].d;
      }
    }
    
    printf("%d\n", par);
  }

  return 0;
}

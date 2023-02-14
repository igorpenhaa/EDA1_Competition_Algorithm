#include<stdio.h>

int main(){
  //Atributos:
  int n_rest = 0;
  int index = 0, star[10000], cod[10000];


  while(scanf("%d", &n_rest) != EOF){
    int r_i[2 * n_rest];
    star[index] = -1;
    cod[index] = -1;
    
    for(int i = 0; i < n_rest; i++){
      int restaurante = 0, estrela = 0;
      scanf("%d %d", &restaurante, &estrela);
      r_i[2*i] = restaurante;
      r_i[2*i + 1] = estrela;
    }

    for(int j = 0; j < 2*n_rest; j++){
      if(j % 2 == 1){
        if(r_i[j] > star[index]){
          star[index] = r_i[j];
          cod[index] = r_i[j-1];
        }
        if(r_i[j] == star[index] && r_i[j-1] < cod[index]){
          star[index] = r_i[j];
          cod[index] = r_i[j-1];
        }
      }
    }
    
    index++;
  }

  for(int k = 0; k < index; k++){
    int a = 0;
    a = k + 1;
    printf("Dia %d\n", a);
    printf("%d\n", cod[k]);
    printf("\n");
  }

  return 0;

}

#include<stdio.h>
#include<string.h>

int somar(char *num, int soma){
  if(*num == '\0'){
    return soma;
  }

  soma = somar(num+1, soma) + *num - 48;
  return soma;
}

int somar_int(int num, int soma){
  if(num < 1){
    return soma;
  }
  int resto = num % 10;
  soma = soma + resto;
  return somar_int(num/10, soma);
}

int degree9(int soma, int degree){
  if(soma < 9){
    return degree;
  }else if(soma == 9){
    degree++;
    return degree;
  }else {
    degree++;
    soma = somar_int(soma, 0);
    return degree9(soma, degree);
  }

}

int main(void){
  char num[1001];
  int soma = 0, degree = 0;

  scanf("%s", &num);
  while(*num != '0'){
   
    soma = somar(&num, 0);

    if(soma % 9 == 0){
      degree = degree9(soma,0);
      printf("%s is a multiple of 9 and has 9-degree %d.\n", num, degree);
    }else{
      printf("%s is not a multiple of 9.\n", num);
    }

    scanf("%s", &num);
  }

  return 0;
}

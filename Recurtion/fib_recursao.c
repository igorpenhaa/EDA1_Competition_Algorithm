#include <stdio.h>

long int fib[250];

long long int fibonacci(int x){
  
  if(x==1||x==2){
    return 1;
  }
  
  if(fib[x] != 0){
    return fib[x];
  } 

  fib[x] = fibonacci(x-2)+fibonacci(x-1);

  return fib[x];
}

int main(void){

  printf("%ld\n", fibonacci(15));

}

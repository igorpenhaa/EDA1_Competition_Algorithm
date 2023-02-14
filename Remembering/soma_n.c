#include <stdio.h>

int main()
{
    int qtd_num;
    int num1;
    int soma;
    int i;
    
    soma = 0;
    scanf("%d", &qtd_num);
    for(i = 0; i < qtd_num; i++)
    {
      scanf("%d", &num1);
      soma = soma + num1;
    }

    printf("%d\n", soma);

    return 0;
}

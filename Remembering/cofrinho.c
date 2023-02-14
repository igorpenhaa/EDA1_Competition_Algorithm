#include <stdio.h>

int main()
{
    int n = 1, index = 0, index1[100];
    int Joao[100], Ze[100], soma[100][100];

    while (n != 0)
    {
        index1[index] = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int din1 = 0, din2 = 0;
            scanf("%d%d", &din1, &din2);
            Joao[i] = din1;
            Ze[i] = din2;
            if (i == 0)
            {
                soma[index][i] = Joao[i] - Ze[i];
            }
            else
            {
                soma[index][i] = soma[index][i - 1] + Joao[i] - Ze[i];
            }

            index1[index]++;
        }
        if (n != 0)
        {
            index++;
        }
    }

    for (int i = 1; i <= index; i++)
    {
        printf("Teste %d\n", i);
        for (int j = 0; j < index1[i - 1]; j++)
        {
            printf("%d\n", soma[i - 1][j]);
        }
    }

    return 0;
}

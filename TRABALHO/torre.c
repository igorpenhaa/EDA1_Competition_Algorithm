#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int linha, coluna;
}Item;

void main() {
    int i = 0, n, m, tortam = 0, h, acc = 0;
    scanf("%d %d", &n, &m);
    Item torre[n*m];
    char lacuna[n][m], aux;
    while (i < n) {
        for (int j = 0; j < m; j++)  {
            scanf("%c", &aux);
            if  (aux == '\n') 
                scanf("%c", &aux);
            lacuna[i][j] = aux;
            if  (aux == 't') 
                torre[tortam++] = (Item){i, j};
        }
        i++;
    }
    i = 0;
    while (i < tortam) {
        scanf("%d", &h);
        for (int j = torre[i].linha - h; j <= torre[i].linha + h; j++)
            for (int k = torre[i].coluna - h; k <= torre[i].coluna + h; k++)
                if (j >= 0 && j < n && k >= 0 && k < m && lacuna[j][k] == '#') {
                    acc++;
                    lacuna[j][k] = '.';
                }
        i++;
    }
    printf("%d\n", acc);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%c", lacuna[i][j]);        
        printf("\n");
    }
}
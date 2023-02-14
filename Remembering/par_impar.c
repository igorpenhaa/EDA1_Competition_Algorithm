#include <stdio.h>

int main() {
	int n = 1, j = 0, beto[100], alice[100];

	while (n != 0) {
		scanf("%d", &n);
		
		int lst[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &lst[i]);
		}
		
		int b_vit = 0, a_vit = 0;
		for (int i = 0; i < n; i++) {
			if (lst[i] == 0) {
				a_vit++;
			}
			if (lst[i] == 1) {
				b_vit++;
			}
		}
		alice[j] = a_vit;
		beto[j] = b_vit;
		j++;
	}

	for (int i = 0; i < j; i++) {
			if (alice[i] || beto[i] != 0) { 
				printf("Alice ganhou %d e Beto ganhou %d\n", alice[i], beto[i]);
			}
	}	
	return 0;
}

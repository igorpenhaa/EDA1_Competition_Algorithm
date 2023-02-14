#include <stdio.h>
#include <string.h>

int main() {
	int n_formulario = 0, resp_sim = 0, n_triagem = 0;
	char str[4];

	while (scanf("%s", str) != EOF) {
		n_formulario++;
		if (!strcmp(str, "sim")) {
			resp_sim++;
		}
		if (n_formulario == 10) {
			if (resp_sim >= 2) {
				n_triagem++;
			}
			resp_sim = 0;
			n_formulario = 0;
		}
	}
	printf("%d\n", n_triagem);
	return 0;
}
#include <stdio.h>
#include <string.h>

//Síntese: fzr o jogo lumberjack;
//Entradas: - inteiro 5 < L < 1000 - numero total de linhas;
//          - inteiro 2 < G < L/2  - numero de galhos;
//          - inteiro G_linha      - em qual linha os galhos estão posicionados;
//          - char    G_lado       - em qual lado o galho está (D ou E); 
//          - string  C[2003]      - recebe os comandos do lenhador (T ou B);
//
//Saída: - imagem do jogo;
//       - **beep**   - se trocar de lado e tiver um galho;
//       - **morreu** - se o galho bater na cabeça do lenhador;
//       - mostrar apenas 5 linhas de cada vez entre 11 ~ ;   

void flush_in()
{
	int ch;
	do
	{
		ch = fgetc(stdin);
	}
	while (ch != EOF && ch != '\n');
}

int main(){

  int L = 0, G = 0, G_linha = 0, pos_l = 0, pos_t = 0;
  char movimento[2003],G_lado, L_lado;

  scanf("%d", &L);

  char image[L+6][11];

  for(int i = 0; i < L + 5; i++){
    image[i][0] = 32; //space da tabela ascii
    image[i][1] = 32; //space da tabela ascii
    image[i][2] = 32; //space da tabela ascii
    image[i][3] = 32; //space da tabela ascii
    image[i][4] = 32; // | da tabela ascii
    image[i][5] = 32; // | da tabela ascii
    image[i][6] = 32; // | da tabela ascii
    image[i][7] = 32; //space da tabela ascii
    image[i][8] = 32; //space da tabela ascii
    image[i][9] = 32; //space da tabela ascii
    image[i][10] = 32; //space da tabela ascii
  }

  for(int i = 0; i < L; i++){
    image[i][0] = 32; //space da tabela ascii
    image[i][1] = 32; //space da tabela ascii
    image[i][2] = 32; //space da tabela ascii
    image[i][3] = 32; //space da tabela ascii
    image[i][4] = 124; // | da tabela ascii
    image[i][5] = 124; // | da tabela ascii
    image[i][6] = 124; // | da tabela ascii
    image[i][7] = 32; //space da tabela ascii
    image[i][8] = 32; //space da tabela ascii
    image[i][9] = 32; //space da tabela ascii
    image[i][10] = 32; //space da tabela ascii
  }

  scanf("%d", &G);

  for(int i = 0; i < G; i++){
    flush_in();
    scanf("%c", &G_lado);
    scanf("%d", &G_linha);

    if(G_lado == 68){
      image[G_linha-1][7] = 45;
      image[G_linha-1][8] = 45;
      image[G_linha-1][9] = 45;
    }else if(G_lado == 69){
      image[G_linha-1][1] = 45;
      image[G_linha-1][2] = 45;
      image[G_linha-1][3] = 45;
    }
  }

  flush_in();
  scanf("%c", &L_lado);

  if(L_lado == 68){
    image[0][8] = 76;
    image[1][8] = 76;
    pos_l = 8;
    pos_t = 2;
  }else if(L_lado == 69){
    image[0][2] = 76;
    image[1][2] = 76;
    pos_l = 2;
    pos_t = 8;
  }

  flush_in();
  scanf("%s", &movimento);

  int topo = 4, base = 0, var = 1;

  for(int i = 0; i < strlen(movimento)+1; i++){
    if(var != 0){
      printf("~~~~~~~~~~~\n");
      for(int k = topo; k >= base; k--){
        for(int j = 0; j < 11; j++){
          printf("%c", image[k][j]);
        }
        printf("\n");
      }
      printf("~~~~~~~~~~~\n");
    }

    if(movimento[i] == 66){
      if(pos_l == 2 && image[base][4] == 124){
        image[base][4] = 62;
        var = 1;
      } else if(pos_l == 8 && image[base][6] == 124){
        image[base][6] = 60;
        var = 1;
      } else if(pos_l == 2 && image[base][4] == 62){
        topo++;
        base++;
        var = 1;
        if(image[base+1][pos_l] == 45){
          printf("**morreu**\n");
          return 0;
        }else{
          image[base+1][pos_l] = 76;
        }
      }else if(pos_l == 8 && image[base][6] == 60){
        topo++;
        base++;
        var = 1;
        if(image[base+1][pos_l] == 45){
          printf("**morreu**\n");
          return 0;
        }else{
          image[base+1][pos_l] = 76;
        }
      }
    }else if(movimento[i] == 84){
      
      if(image[base][pos_t] == 45 || image[base+1][pos_t] == 45){
        printf("**beep**\n");
        var = 0;
      }else {
        image[base][pos_t] = 76;
        image[base+1][pos_t] = 76;
        image[base][pos_l] = 32;
        image[base+1][pos_l] = 32;
        pos_l = pos_t;
        var = 1;
        
        if(pos_l == 2){
          pos_t = 8;
        }else{
          pos_t = 2;
        }
      }
    }

    
  }

  return 0;
}
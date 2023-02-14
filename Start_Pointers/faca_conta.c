
int faz_conta_direito(int parcela, char operacao){
  int conta[parcela], soma = 0;

  if(operacao == '+'){
    for(int i = 0; i < parcela; i++){
      scanf("%d", &conta[i]);
      soma = soma + conta[i];
    }
  }else{
    for(int i = 0; i < parcela; i++){
      scanf("%d", &conta[i]);
      if(i == 0){
        soma = soma + conta[i];
      }else{
        soma = soma - conta[i];
      }
    }
  }
  return soma;
}

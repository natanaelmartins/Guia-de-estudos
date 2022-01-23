# Pretendo colocar aqui os exercícios mais simples da faculdade

#include <stdio.h>
#include <ctype.h>

int main(void) {

  int opcao, opcao2, CPF[9], i, Digitos = 0, somaproduto, somaproduto2, DV1, DV2, numerocontrole;

  Começo:

  printf("\nAlgoritmo para verificar o dígito verificador do seu CPF.");

  printf("\n\nEscolha a opção desejada: ");
  printf("\n\n1. Verificar o dígito verificador do CPF\n2. Informações dos desenvolvedores\n3. Sair do algoritmo\n\n");
  scanf("%d", &opcao);

  if(opcao == 1)
  {
    
    printf("\nInsira seu CPF, digito por digito, sem os dois últimos numeros: \n");
    for(i=0;i<9;++i)
    {
      scanf("%d", &CPF[i]);
    }

    printf("\nSeu CPF (com os digitos verificadores): ");


    for(i=0;i<9;++i)
    {
      printf("%d", CPF[i]);
    }

    somaproduto = (CPF[8]*2 + CPF[7]*3 + CPF[6]*4 + CPF[5]*5 + CPF[4]*6 + CPF[3]*7 + CPF[2]*8 + CPF[1]*9 + CPF[0]*10)*10;
    if(somaproduto % 11 == 10)
    {
      DV1 = 0;
    }
    else 
    {
      DV1 = somaproduto % 11;
    }

    somaproduto2 = ((CPF[8]*3 + CPF[7]*4 + CPF[6]*5 + CPF[5]*6 + CPF[4]*7 + CPF[3]*8 + CPF[2]*9 + CPF[1]*10 + CPF[0]*11) + DV1 * 2)*10;
    if(somaproduto2 % 11 == 10)
    {
      DV2 = 0;
    }
    else 
    {
      DV2 = somaproduto2 % 11;
    }

    numerocontrole = (DV1 * 10) + DV2;

    printf("-%d", numerocontrole);

    printf("\n\nDeseja voltar ao menu? Digite 1 para sim ou 2 para não\n");
    scanf("%d", &opcao2);

    if(opcao2 == 1)
    {
      goto Começo;
    }
    else
    {
      return 0;
    }
  }

  if(opcao == 2)
  {
    printf("\nDesenvolvedor: Natanael Martins");

    printf("\n\n\n\nDeseja voltar ao menu? Digite 1 para sim ou 2 para não\n");
    scanf("%d", &opcao2);

    if(opcao2 == 1)
    {
      goto Começo;
    }
    else
    {
      return 0;
    }
  }

  if(opcao == 3)
  {
    return 0;
  }

  return 0;
}

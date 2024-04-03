//main.c
//Programa pra testar a ABB criada

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void PreOrdem(NoArvore *no)
{
	if(no != NULL)
	{
		printf("%d ", no->Valor);
		PreOrdem(no->Esquerda);
		PreOrdem(no->Direita);
	}
}

void EmOrdem(NoArvore *no)
{
	if(no != NULL)
	{
		EmOrdem(no->Esquerda);
		printf("%d ", no->Valor);
		EmOrdem(no->Direita);
	}
}

void PosOrdem(NoArvore *no)
{
	if(no != NULL)
	{
		PosOrdem(no->Esquerda);
		PosOrdem(no->Direita);
		printf("%d ", no->Valor);
	}
}

int main(void)
{
	Arvore *a = ArvoreNovo();

	int x = 1;
	
	while(x != 0)
	{
		system("cls");
		
		printf("PRE: ");
		PreOrdem(a->Raiz);
				
		printf("\n EM: ");
		EmOrdem(a->Raiz);
				
		printf("\nPOS: ");
		PosOrdem(a->Raiz);
		
		printf("\n\nTamanho: %d", a->Tamanho);
		
		printf("\n\n>> ");
		scanf("%d", &x);
		
		if(x == 0)
			break;
		
		if(x > 0)
			ArvoreInserir(a, x);
		else
			ArvoreRemover(a, -x);
	}
	
	
	return 0;
}

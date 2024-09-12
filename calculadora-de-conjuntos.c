#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define MAX 1000

/// OPERA��ES CENTRAIS
int digitar(){
    int n;
    scanf("%d", &n);
    return n;
}

void inserir(int *vetor, int *tamanho){
    
    printf("Quantos n�meros voc� deseja inserir no vetor? ");
    int n = digitar();
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Insira: ");
        vetor[i] = digitar();
        (*tamanho)++;
    }
    

}

void imprimir(int *vetor, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    
}

int pesquisar(int *vetor, int tamanho, int pesquisa){
    printf("pesquise: ");
    int i;
    for (i = 0; i < tamanho + 1; i++){
        if (vetor[i] == pesquisa){
            return i;
        }       
    }
    return -1;
    
}

void remover(int *vetor, int escolha, int *tamanho){
    int i;
    for ( i = escolha ; i < *tamanho - 1; i++){
        vetor[i] = vetor [i + 1];
    }
    (*tamanho)--;
}

/// FUN��ES PARA O PROGRAMA 
int opcao(){

    int op;
    printf("Digite qual opera��o voce deseja fazer:\n\n");

    printf("[1] Uni�o\n");
    printf("[2] Intercess�o\n");
    printf("[3] A - B\n");
    printf("[4] B - A\n");
    printf("[5] Diferenca sim�trica de A e B\n");
    printf("[6] A x B\n\n");

    printf("Op��o: ");
    scanf("%d", &op);

    return op;
}
/*
void operecao(int *vetor, int *tamanho){
    int op = opcao();
    switch (op)
    {
    case 1:
        printf("oi");
        break;
    
    default:
        break;
    }
}
*/
int main(){

    setlocale(LC_ALL, "portuguese");

    /*cria��o de vetores*/

    /*A*/
    int vetorA[MAX];
    int tamanho_vetorA = 0;

    /*B*/
    int vetorB[MAX];
    int tamanho_vetorB = 0;

    inserir(vetorA, &tamanho_vetorA);
    inserir(vetorB, &tamanho_vetorB);
   


    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define MAX 1000

/// OPERAÇÕES CENTRAIS
int digitar(){
    int n;
    scanf("%d", &n);
    return n;
}

void inserir(int *vetor, int *tamanho){
    
    printf("Quantos números você deseja inserir no vetor? ");
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

/// FUNÇÕES PARA O PROGRAMA 
int opcao(){

    int op;
    printf("Digite qual operação voce deseja fazer:\n\n");

    printf("[1] União\n");
    printf("[2] Intercessão\n");
    printf("[3] A - B\n");
    printf("[4] B - A\n");
    printf("[5] Diferenca simétrica de A e B\n");
    printf("[6] A x B\n\n");

    printf("Opção: ");
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

    /*criaï¿½ï¿½o de vetores*/

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


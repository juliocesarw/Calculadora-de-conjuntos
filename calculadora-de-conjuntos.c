#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*biblioteca usada para os caracteres*/
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


int pesquisar(int *vetor, int tamanho, int pesquisa){
    int i;
    for (i = 0; i < tamanho; i++){
        if (vetor[i] == pesquisa){
            return i;
        }       
    }
    return -1;
    
}

void imprimir(int *vetor, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        int pes = pesquisar(vetor, i, vetor[i]);
        if (pes < 0){
            printf("%d ", vetor[i]);
        } 
    }
    
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


///PARA COLOCAR O VETOR EM ORDEM

void ordem(int *vetor, int tamanho){
    for (size_t e = 0; e < (tamanho - 1); e++)
    {
        for (size_t i = 0; i < (tamanho - e - 1); i++)
        {
            if (vetor[i] > vetor[i + 1]){
                int troca = vetor[i + 1];
                vetor[i+1] = vetor[i];
                vetor[i] = troca;
            }
        }
    }
    
}

/// FUNÇÕES PARA AS OPERAÇÕES

void uniao(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){

    int vetor_c[MAX];
    int tamanho_c = 0;
    for (int i = 0; i < tamanho_A; i++)
    {
        vetor_c[i] = vetor_A[i];
        tamanho_c++;
    }
    for (int i = 0; i < tamanho_B; i++)
    {
        vetor_c[tamanho_A + i] = vetor_B[i];
        tamanho_c++;
    }
      
    ordem(vetor_c, tamanho_c);

    imprimir(vetor_c, tamanho_c);
}


void intercessao(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){

    int pes, tamanho_c;
    int vetor_c[MAX];
    tamanho_c = 0;
    
    for (int i = 0; i < tamanho_A; i++)
    {
        pes = pesquisar(vetor_B, tamanho_B, vetor_A[i]);
        if (pes >= 0){
            vetor_c[tamanho_c] = vetor_A[i];
            tamanho_c++;
        }
    }
    for (int i = 0; i < tamanho_B; i++)
    {
        pes = pesquisar(vetor_A, tamanho_A, vetor_B[i]);
        if (pes >= 0){
            vetor_c[tamanho_c] = vetor_B[i];
            tamanho_c++; 
        } 
    }
    
    ordem(vetor_c, tamanho_c);
    imprimir(vetor_c, tamanho_c);

}

void operacao(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){
    int op = opcao();
    switch (op)
    {
    case 1:
        printf("A U B: ");
        uniao(vetor_A, vetor_B, tamanho_A, tamanho_B);
        break;
    case 2:
        printf("A intercessao de A e B e: ");
        intercessao(vetor_A, vetor_B, tamanho_A, tamanho_B);
        break;
    /*case 3:
        a_menos_b();
        break;
    case 4:
        b_menos_a();
        break;
    case 5:
        diferenca(vetor_A, vetor_B, tamanho_A, tamanho_B);
        break;
    case 6:
        a_x_b();
        break;*/    
    default:
        printf("Invalido");
        break;
    }
}



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
    
    operacao(vetorA, vetorB, tamanho_vetorA, tamanho_vetorB);


    return 0;
}


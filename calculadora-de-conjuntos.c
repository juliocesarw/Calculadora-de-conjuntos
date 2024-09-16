#include <stdio.h>
#include <stdlib.h>

//TAMANHO DOS VETORES
#define MAX 1000

// BIBLIOTECA USADA PARA OS CARACTERES
#include <locale.h>

/// OPERA��ES CENTRAIS (DIGITAR, INSERIR, IMPRIMIR, PESQUISAR, REMOVER)
int digitar(){
    int n;
    scanf("%d", &n);
    return n;
}

void inserir(int *vetor, int *tamanho, char letra){
    
    printf("Quantos elementos voc� deseja inserir no conjunto %c? ", letra);
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



///PARA COLOCAR O VETOR EM ORDEM

void ordem(int *vetor, int tamanho){
    for (int e = 0; e < (tamanho - 1); e++)
    {
        for (int i = 0; i < (tamanho - e - 1); i++)
        {
            if (vetor[i] > vetor[i + 1]){
                int troca = vetor[i + 1];
                vetor[i+1] = vetor[i];
                vetor[i] = troca;
            }
        }
    }
    
}

/// FUN��ES PARA AS OPERA��ES

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

void calc_menos(int *vetor_1, int *vetor_2, int *vetor_3, int tamanho_1, int tamanho_2, int *tamanho_3){

    for (int i = 0; i < tamanho_1; i++)
    {
        int pes = pesquisar(vetor_2, tamanho_2, vetor_1[i]);
        if (pes < 0){
            vetor_3[*tamanho_3] = vetor_1[i];
            (*tamanho_3)++;
        }
    }

}

void menos(int *vetor_1, int *vetor_2, int tamanho_1, int tamanho_2){

    int vetor_3[MAX];
    int tamanho_3 = 0;

    calc_menos(vetor_1, vetor_2, vetor_3, tamanho_1, tamanho_2, &tamanho_3);

    ordem(vetor_3, tamanho_3);
    imprimir(vetor_3, tamanho_3);

}

void diferenca(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){
    
    int vetor_c[MAX];
    int tamanho_c = 0;

    calc_menos(vetor_A, vetor_B, vetor_c, tamanho_A, tamanho_B, &tamanho_c);
    calc_menos(vetor_B, vetor_A, vetor_c, tamanho_A, tamanho_B, &tamanho_c);

    ordem(vetor_c, tamanho_c);
    imprimir(vetor_c, tamanho_c);

}

void plano_cartesiano(int *vetor_1, int *vetor_2, int tamanho_1, int tamanho_2){

    for (int i = 0; i < tamanho_1; i++)
    {
        
        for (int x = 0; x < tamanho_2; x++)
        {
            /* code */

            if (x != (tamanho_2 - 1)){
                printf(" (%d, %d), ", vetor_1[i], vetor_2[x]);
            }
            else{
                printf("(%d, %d)", vetor_1[i], vetor_2[x]);                
            }
        }
        
    }
    

}

/// FUN��ES PARA O PROGRAMA 
int opcao(){

    int op;
    printf("\n\nDigite qual opera��o voc� deseja fazer:\n\n");

    printf("[1] Uni�o\n");
    printf("[2] Intercess�o\n");
    printf("[3] A - B\n");
    printf("[4] B - A\n");
    printf("[5] Diferen�a sim�trica de A e B\n");
    printf("[6] A x B\n");
    printf("[7] B x A\n");    
    printf("[8] Sair do programa\n\n");

    printf("Op��o: ");
    scanf("%d", &op);

    return op;
}


void operacao(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){
    
    int controle_loop = 1;

    while (controle_loop >= 1)
    {
        /* code */
        int op = opcao();
        switch (op)
        {
        case 1:
            printf("A U B: ");
            uniao(vetor_A, vetor_B, tamanho_A, tamanho_B);
            break;
        case 2:
            printf("A intercess�o de A e B �: ");
            intercessao(vetor_A, vetor_B, tamanho_A, tamanho_B);
            break;
        case 3:
            printf("A - B �: ");
            menos(vetor_A, vetor_B, tamanho_A, tamanho_B);
            break;
        case 4:
            printf("B - A �: ");
            menos(vetor_B, vetor_A, tamanho_B, tamanho_A);
            break;
        case 5:
            printf("A diferen�a sim�trica de A e B �: ");
            diferenca(vetor_A, vetor_B, tamanho_A, tamanho_B);
            break;
        case 6:
            printf("A x B: ");
            plano_cartesiano(vetor_A, vetor_B, tamanho_A, tamanho_B);
            break;
        case 7:
            printf("B x A: ");
            plano_cartesiano(vetor_B, vetor_A, tamanho_B, tamanho_A);
            break;
        case 8:
            printf("Volte sempre!!!");
            controle_loop = 0;
            break;
        default:
            printf("Invalido");
            break;
        }
    }
    
}


// PROGRAMA PRINCIPAL
int main(){

    setlocale(LC_ALL, "portuguese");

    /*cria��o de vetores*/

    /*A*/
    int vetorA[MAX];
    int tamanho_vetorA = 0;
    char vetA = 'A';

    /*B*/
    int vetorB[MAX];
    int tamanho_vetorB = 0;
    char vetB = 'B';

    inserir(vetorA, &tamanho_vetorA, vetA);
    inserir(vetorB, &tamanho_vetorB, vetB);
    
    operacao(vetorA, vetorB, tamanho_vetorA, tamanho_vetorB);


    return 0;
}


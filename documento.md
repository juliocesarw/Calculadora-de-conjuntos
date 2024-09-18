# Documento do código

O código descrito abaixo é de uma calculadora de conjuntos numéricos, escrito na linguagem C.

## Bibliotecas

``` c
#include <stdio.h>
#include <stdlib.h>
```
A biblioteca `stdio.h` é usada para realizar operações de entrada e saída e a `stdlib.h` é usada para operações de gerenciamento de memória, controle de processos e conversões.

```c
#include <locale.h>
```
A biblioteca `locale.h` é usada para que o código em C suporte acentuações nos textos e após incluir a biblioteca, deve-se escrever seu comando na função principal, como ilustrado abaixo: 

```c
int main(){
    setlocale(LC_ALL, "portuguese");
    return 0;
}
```
## Funções das Operações Centrais 

Essas funções fazem as operações principais dentro de um vetor, como digitar, inserir, pesquisar, imprimir e remover.

### Digitar

```c
int digitar(){
    int n;
    scanf("%d", &n);
    return n;
}
```

Essa função é especificamente para a entrada de valores em qualquer lugar que ela seja chamada. O valor é lido pelo `scanf` e armazenado na variavel `n`, após a variável `n` é retornada para variável que chamou a função `digitar`.

### Inserir

```c
void inserir(int *vetor, int *tamanho, char letra){
    printf("Quantos elementos você deseja inserir no conjunto %c? ", letra);
    int n = digitar();
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Insira: ");
        vetor[i] = digitar();
        (*tamanho)++;
    }
}
```

Essa função, por ser do tipo `void`, não retorna nada. Seus parâmetros são o vetor, que receberá os valores, o seu tamanho e sua identificação (A ou B). Ela é usada para a entrada de valores no vetor. Inicialmente é perguntado quantos elementos o usuário deseja inserir, logo após, é feita a chamada da função `digitar` para ler a quantidade de elementos e em seguida, o valor é guardado na variável `n`. Depos de ler a quantidade, é declarada a variável `i` do tipo `int` como índice do laço de repetição `for`. O for vai rodar até um número abaixo do número elementos fornecido pelo usuário (isso se deve ao fato de que em vetores (arrays), a alocação de dados começa pela posição 0) repetindo a chamada da função `digitar`, guardando no vetor na posição do índice. 

### Pesquisar

```c
int pesquisar(int *vetor, int tamanho, int pesquisa){
    int i;
    for (i = 0; i < tamanho; i++){
        if (vetor[i] == pesquisa){
            return i;
        }       
    }
    return -1;   
}
```

A função pesquisar é chamada quando o usuário quer saber o elemento x existe dentro do vetor. Ela compara o elemento passado como parâmetro ao elemento dentro do vetor na posição do índice, se existir, retorna a posição, se não, retorna um número negativo.

### Imprimir

```c
void imprimir(int *vetor, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++){
        int pes = pesquisar(vetor, i, vetor[i]);
        if (pes < 0){
            printf("%d ", vetor[i]);
        } 
    }
}
```

A função `imprimir` recebe o vetor e seu tamanho como parâmetro, e roda imprimindo cada elemento do vetor na posição do índice. Porém, ela já foi programada para caso a variável de pesquisa retornar um número positivo, ela não imprimir. A variável `pes` chama a função imprimir, tendo como parâmetros o vetor, o número do índice e o elemento do vetor na posição do índice. Na função pesquisar, é verificado no vetor apenas o número de elementos passados pelo número de indice. Por exemplo: caso seja primeiro número e o índice for zero, vai imprimir o primeiro valor do vetor porque o tamanho do vetor (passado pelo índice) não é maior que o indice da função pesquisar, mas a partir do segundo número do vetor, começa a verificação. Caso o número se repita dentro do vetor, ele não é impresso porque a função pesquisar retorna um número maior ou igual a zero e na condicional da função imprimir, está que só será impresso caso o valor guardado em pes for menor que zero (caso não seja encontrado).

### Remover

```c
void remover(int *vetor, int escolha, int *tamanho){
    int i;
    for ( i = escolha ; i < *tamanho - 1; i++){
        vetor[i] = vetor [i + 1];
    }
    (*tamanho)--;
}
```

A função `remover` recebe o vetor, seu tamanho e a posição do número que o usuário deseja exluir (O usuário usa a função pesquisar para saber a posição do número que ele escolheu remover) que o usuário deseja excluir. O for começa a partir da posição do número que deve ser excluído e pega o valor da próxima posição e altera o valor da posição atual, exluindo assim o número desejado. 

Obs: essa função foi adicionada para possíveis upgrades no projeto.

### Colocar o vetor em ordem

```c
void ordem(int *vetor, int tamanho){
    int i, e;
    for (e = 0; e < (tamanho - 1); e++)
    {
        for (i = 0; i < (tamanho - e - 1); i++)
        {
            if (vetor[i] > vetor[i + 1]){
                int troca = vetor[i + 1];
                vetor[i+1] = vetor[i];
                vetor[i] = troca;
            }
        }
    }
}
```
Essa função pega o vetor por inteiro e compara o valor de uma posição com a sua próxima (isso não é feito na última posição). Se for maior, troca as posições, e repetindo isso até o último valor, o vetor fica em ordem. Isso é chamado de Bubble Sort ou Método de Flutuação.

## Funções Operacionais

### União

```c
void uniao(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){
    int vetor_c[MAX];
    int i;
    int tamanho_c = 0;
    for (i = 0; i < tamanho_A; i++)
    {
        vetor_c[i] = vetor_A[i];
        tamanho_c++;
    }
    for (i = 0; i < tamanho_B; i++)
    {
        vetor_c[tamanho_A + i] = vetor_B[i];
        tamanho_c++;
    }  
    ordem(vetor_c, tamanho_c);
    imprimir(vetor_c, tamanho_c);
}
```
Essa função faz a união de dois `vetores A e B`. Ela recebe os dois vetores e seus respectivos tamanhos como parâmetro. No início da função, é declarado o `vetor C`, que receberá a união dos dois vetores A e B, e uma variável como seu tamanho. O primeiro, adiciona todos os valores do `vetor A` a partir da posição do ìndice. O segundo, adiciona todos os números do `vetor B` no vetor C a partir da posição que corresponde o tamanho do vetor A + o número do índice. No final é chama a função ordem, para que seja ordenado e na hora de imprimir, é retirado os repetidos para que não apareça na tela.

### Intercessão

```c
void intercessao(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){

    int pes, tamanho_c;
    int vetor_c[MAX];
    tamanho_c = 0;
    int i;
    for (i = 0; i < tamanho_A; i++)
    {
        pes = pesquisar(vetor_B, tamanho_B, vetor_A[i]);
        if (pes >= 0){
            vetor_c[tamanho_c] = vetor_A[i];
            tamanho_c++;
        }
    }
    for (i = 0; i < tamanho_B; i++)
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
```
Essa função faz a intercessão de dois `vetores A e B`. Ela recebe os dois vetores e seus respectivos tamanhos como parâmetro. No início da função, é declarado o `vetor C`, que receberá a intercessão dos dois vetores A e B, e uma variável como seu tamanho. Dentro do primeiro for, incialmente, é feito a pesquisa pela chamada da função pesquisar pela variável `pes`, caso o valor da posição do índice no vetor A seja encontrado no vetor B, o valor é adicionado no vetor C na posição que corresponde ao seu tamanho (inicialmente zero). O segundo for funciona de forma semelhante, porém verificado a partir do vetor B comparado ao vetor A. No final o vetor C é ordenado e é impresso sem as repetições.

### Diferença

```c
void menos(int *vetor_1, int *vetor_2, int tamanho_1, int tamanho_2){
    int vetor_3[MAX];
    int tamanho_3 = 0;
    calc_menos(vetor_1, vetor_2, vetor_3, tamanho_1, tamanho_2, &tamanho_3);
    ordem(vetor_3, tamanho_3);
    imprimir(vetor_3, tamanho_3);
}

void calc_menos(int *vetor_1, int *vetor_2, int *vetor_3, int tamanho_1, int tamanho_2, int *tamanho_3){
    int i;
    for (i = 0; i < tamanho_1; i++)
    {
        int pes = pesquisar(vetor_2, tamanho_2, vetor_1[i]);
        if (pes < 0){
            vetor_3[*tamanho_3] = vetor_1[i];
            (*tamanho_3)++;
        }
    }
}
```

A função `menos` tem como objetivo fazer mostrar diferença entre dois vetores. Ela recebe esses dois vetores e seus respectivos tamanhos como parâmetro. Inicialmente é declarado o `vetor 3`, e uma variável para seu tamanho, que receberá os valores da diferença dos dois. Partindo desse ponto, foi criado uma função apenas para realizar o calculo da diferença, `calc_menos`. Essa função, que recebe os três vetores e seus respectivos tamanhos (tamanho do vetor 3 é passado como ponteiro), pesquisa no `vetor 2`, o valor da posição no `vetor 1` passada pelo índice, e caso não seja encontrado, a variável `pes` retorna -1, que passando pela condicional, é adicionado no vetor 3, na posição de seu tamanho. No final, o vetor 3 é ordenado e impresso.

### Diferença Simétrica

```c
void diferenca(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){
    int vetor_c[MAX];
    int tamanho_c = 0;
    calc_menos(vetor_A, vetor_B, vetor_c, tamanho_A, tamanho_B, &tamanho_c);
    calc_menos(vetor_B, vetor_A, vetor_c, tamanho_B, tamanho_A, &tamanho_c);
    ordem(vetor_c, tamanho_c);
    imprimir(vetor_c, tamanho_c);
}
```

Essa função recebe os `vetores A e B` e seus respectivos tamanhos como parâmetros. No início é declarado o `vetor C`, e uma variável para seu tamanho. Logo após, é chamada a função `calc_menos`, que faz a diferença entre dois vetores, recebendo como parâmetro o vetor A sendo `Vetor 1`, vetor B sendo `Vetor 2` e vetor C sendo `Vetor 3` e seus respectivos tamanhos (o tamanho do vetor C é passado como ponteiro). A função calc_menos é chamada novamente, porém sendo o vetor B o vetor 1 e o vetor A o vetor 2. Depois de chamar a função duas vezes, a diferença simétrica dos vetores A e B está guardada no vetor C. O vetor é ordenado e impresso.

### Plano Cartesiano

```c
void plano_cartesiano(int *vetor_1, int *vetor_2, int tamanho_1, int tamanho_2){
    int i, x;
    for (i = 0; i < tamanho_1; i++)
    {     
        for (x = 0; x < tamanho_2; x++)
        {
            if (x != (tamanho_2 - 1)){
                printf(" (%d, %d), ", vetor_1[i], vetor_2[x]);
            }
            else{
                printf("(%d, %d)", vetor_1[i], vetor_2[x]);                
            }
        }    
    }
}
```

Essa função recebe dois vetores, e seus respectivos tamanhos, como parâmetros. Ela tem 2 comandos  for, um dentro do outro. O primeiro roda o primeiro vetor e o segundo, o segundo vetor. É impresso na tela o valor da posição do índice no vetor 1 e o valor da posição do índice no vetor 2. Sendo assim, caso o primeiro índice tenha o valor 1, e no segundo vetor tenha os valores n, m e p, imprimirá na tela `(1,n),(1,m),(1,p)`, quando acabar de executar o segundo for, o índice do primeiro passará a ser o próximo valor, por exemplo 2, e imprimirá na tela `(2,n),(2,m),(2,p)`.

## Funções do Programa

### Opções

```c
int opcao(){

    int op;
    printf("\n\nDigite qual operação você deseja fazer:\n\n");

    printf("[1] União\n");
    printf("[2] Intercessão\n");
    printf("[3] A - B\n");
    printf("[4] B - A\n");
    printf("[5] Diferença simétrica de A e B\n");
    printf("[6] A x B\n");
    printf("[7] B x A\n");    
    printf("[8] Sair do programa\n\n");

    printf("Opção: ");
    scanf("%d", &op);

    return op;
}
```

Essa função pede ao usuário para digitar a operação que ele deseja fazer, e por ser uma função do tipo int, ela vai retornar o valor digitado para a variável da chamada.

### Função das Chamadas das Opções

```c
void chamada(int *vetor_A, int *vetor_B, int tamanho_A, int tamanho_B){
    
    int controle_loop = 1;

    while (controle_loop >= 1)
    {
        int op = opcao();
        switch (op)
        {
        case 1:
            printf("A U B: ");
            uniao(vetor_A, vetor_B, tamanho_A, tamanho_B);
            break;
        case 2:
            printf("A intercessão de A e B é: ");
            intercessao(vetor_A, vetor_B, tamanho_A, tamanho_B);
            break;
        case 3:
            printf("A - B é: ");
            menos(vetor_A, vetor_B, tamanho_A, tamanho_B);
            break;
        case 4:
            printf("B - A é: ");
            menos(vetor_B, vetor_A, tamanho_B, tamanho_A);
            break;
        case 5:
            printf("A diferença simétrica de A e B é: ");
            diferenca_simetrica(vetor_A, vetor_B, tamanho_A, tamanho_B);
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
            printf("Inválido");
            break;
        }
    }
    
}

```
Essa função recebe como parâmetro os vetores A e B e seus respectivos tamanhos. Ela tem a finalidade, de através da opção guardada na variável `op`, executar o comando que está na opção correspondente do switch. Exemplo: `op = 1`, no switch o `case 1` chama a função `uniao`, que por sua vez, faz a união de dois conjuntos. 

## Programa Principal

```c
int main(){

    setlocale(LC_ALL, "portuguese");

    /*criação de vetores*/

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
    
    chamada(vetorA, vetorB, tamanho_vetorA, tamanho_vetorB);

    return 0;
}
```

Aqui é criado os vetores A e B. Logo após, é chamada a função inserir para ambos os vetores, e logo após é chamada a função que faz a chamada das demais funções das operações.

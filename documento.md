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

Essa função é especificamente para a entrada de valores em qualquer lugar que ela seja chamada. O valor é lido pelo `scanf` e colocado na variavel `n`, após a variável `n` é retornada para variável que chamou a função `digitar`.

### Inserir

```c
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
```

Essa função, por ser do tipo `void`, não retorna nada. Ela é usada para a entrada de valores no vetor. Inicialmente é perguntado quantos elementos o usuário deseja inserir, logo após, é feita a chamada da função `digitar` para ler a quantidade de elementos e em seguida, o valor é guardado na variável `n`. Depos de ler a quantidade, é declarada a variável `i` do tipo `int` como índice do laço de repetição `for`. O for vai rodar até um número abaixo do número elementos fornecido pelo usuário (isso se deve ao fato de que em vetores (arrays), a alocação de dados começa pela posição 0) repetindo a chamada da função `digitar`, guardando no vetor na posição do índice.
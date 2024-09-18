# Esse trabalho é uma calculadora de conjuntos numéricos em C
## Sobre os caracteres:

Em C, você precisa de uma biblioteca para que os caracteres apareçam de forma normal. Nesse código, eu usei a biblioteca locale. h :


<p align="center">
  <img src="imagens/locale.png" alt="Logo do Projeto"/>
</p>


escrevendo o codigo setlocale(LC_ALL, "portuguese") na função 
main:  


<p align="center">
  <img src="imagens/set-locale.png" alt="Logo do Projeto"/>
</p>


após, vá no canto inferior direito do editor de código (VSCDODE) e clique em UTF -8:    


<p align="center">
  <img src="imagens/UTF-8.png" alt="Logo do Projeto"/>
</p>


depois clique em open with Encoding e, logo após, em ISO 8859-1.

OBS: Talvez você tenha que editar as palavras após esse processo.

## Sobre o código:
Na execução, ele te mostra o menu da calculadora de conjuntos e cada número corresponde a uma operação:

<p align="center">
  <img src="imagens/menu.png" alt="Logo do Projeto"/>

</p>  


### Exemplo de cada sendo A = {1, 2, 3, 4}  e B = {3, 4, 5, 6} :

#### União

<p align="center">
  <img src="imagens/uniao.png" alt="Logo do Projeto"/>

</p>

### Intercessão

<p align="center">
  <img src="imagens/intercessao.png" alt="Logo do Projeto"/>

</p>

### A - B

<p align="center">
  <img src="imagens/a - b.png" alt="Logo do Projeto"/>

</p>

### B - A

<p align="center">
  <img src="imagens/b - a.png" alt="Logo do Projeto"/>

</p>

### Diferença simétrica

<p align="center">
  <img src="imagens/diferenca.png" alt="Logo do Projeto"/>

</p>

### A x B

<p align="center">
  <img src="imagens/a x b.png" alt="Logo do Projeto"/>

</p>

### B x A

<p align="center">
  <img src="imagens/b x a.png" alt="Logo do Projeto"/>

</p>
 

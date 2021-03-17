<h1>Exercício programa 1 - MAC2166</h1>
<h2>Enunciado</h2>
<div>
Neste Primeiro Exercício Programa, você deve entregar um programa em C que resolva um
problema muito parecido com o de um famoso jogo conhecido pelo nome de senha, (mastermind é
o nome original).
</div>

<div>
Segundo a descrição presente na Wikipedia, o jogo tem pinos de seis cores diferentes, aleatórias, exceto preto e branco. Os pinos pretos e
brancos são menores. Há quatro buracos grandes em cada fileira, em 10 fileiras, uma abaixo da outra. E ao lado delas, um quadrado menor, com quatro buracos menores, dois em cima
de dois. Uma fileira, que seria a décima primeira, tem um defletor que esconde seus buracos. O desafiador faz uma combinação com quatro pinos coloridos, sem repetir as cores de cada pino, e as põe na décima primeira fileira e levanta o defletor, escondendo a senha. Então, o desafiado tenta adivinhar a senha, pondo quatro pinos que ele acha que são a senha na primeira fileira, e o desafiador põe os pinos pretos e brancos no quadrado menor ao lado. A regra dos pinos pretos e
brancos são essas: o branco significa que há uma cor certa mas lugar errado; o preto significa que há uma cor certa no lugar certo; e nenhum pino significa que uma das cores não é contida na senha. O desafiado vai tentando adivinhar, se
guiando pelos pinos pretos e brancos. Se o desafiado não acertar até a 10ª fileira, o desafiador fecha o defletor e revela a senha, mas se adivinhar, o desafiador põe quatro pinos pretos e revela a senha.1
</div>

<div>
Muitas vezes encontram-se versões do jogo com pequenas variantes, sobre o número de cores, ou
sobre a possibilidade de repetir cores. Neste EP, por exemplo, NÃO SERÃO CALCULADOS
PINOS BRANCOS. No restante, você irá implementar uma versão bastante geral que permitirá a
representação de até nove cores, para os pinos coloridos. A quantidade k de pinos usados para
compor a senha também é flexível e as posições destes pinos são numeradas de 0 a k-1. Cada cor
dentre as c cores será representada por dígitos de 1 a 9, e cada senha é representada por um número
inteiro, cuja representação decimal usa k dígitos e codifica a sequência de pinos da seguinte forma:
o dígito menos significativo é o pino da posição 0; o segundo dígito menos significativo (o das
dezenas) é o pino da posição 1; e assim por diante.
</div>

<div>
Por exemplo: o número 5347 representa a senha com pinos de cores 7, 4, 3, e 5 nas posições 0, 1, 2
e 3, respectivamente.
</div>

<div>
Para resolver o EP, você deve resolver este subproblema: Dados dois inteiros positivos, senha e
palpite, representando duas sequências de k pinos coloridos, calcular o números de pinos pretos
correspondentes, ou seja, quantos dígitos aparecem nas duas sequências nas mesmas posições. A
tabela mostra o número de pinos pretos (dígitos coincidentes na mesma posição) contados para
diversos pares de valores de senha e palpite:
</div>

<div align="center">
    <table border="1">
        <tr>
            <th>senha</th>
            <th>palpite</th>
            <th>pinos pretos</th>
        </tr>
        <tr style="text-align:center">
            <td> 5335 </td>
            <td> 3335 </td>
            <td> 3 </td>
        </tr>
        <tr style="text-align:center">
            <td> 5335 </td>
            <td> 5335 </td>
            <td> 4 </td>
        </tr>
        <tr style="text-align:center">
            <td> 5335 </td>
            <td> 3553 </td>
            <td> 0 </td>
        </tr>
        <tr style="text-align:center">
            <td> 5335 </td>
            <td> 3535 </td>
            <td> 2 </td>
        </tr>
    </table>
</div>

<div>
Depois de resolvido o subproblema, você deve escrever a função main do programa C que em
diversas tentativas pede inteiros representando até um número limitado de palpites. Com cada palpite, resolve-se um subproblema, calculando-se e imprimindo-se quantos pinos pretos correspondem a esta tentativa de quebrar a senha. Em conformidade com o formato dos exemplos de execução fornecidos a seguir, o programa deve primeiro solicitar os seguintes parâmetros: o número de dígitos k, o número de cores c e o número máximo de palpites. Em seguida, o programa deve pedir uma senha. Se a senha digitada for zero, o programa deverá gerar uma senha aleatória. Para tanto, inclua no seu programa o código a seguir:
</div>

```
printf("Entre com a senha de %d digitos (0 para valor aleatorio): ", k);
scanf("%d",&senha);
if (senha == 0) {
 srand(time(NULL));
 for (i=0; i<k; i++)
 senha = senha*10 + (rand() % c + 1);
}
```
<div>
Note que, se o usuário digitar uma senha e portanto, esta não for gerada aleatoriamente, o programa
não fará uso da informação fornecida sobre o número de cores $c$. Para poder usar as funções
time, rand e srand, você deve incluir no seu programa, logo abaixo do #include<stdio.h>, as
linhas #include<time.h> e # include<stdlib.h>
</div>

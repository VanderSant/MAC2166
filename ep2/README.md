# **Introdução à Ciência da Computação**

<h1>Exercício programa 2 - MAC2166</h1>

# Las Begas

O dono de um cassino de “Las Begas”, em “ABUSA”, pretente fazer uma máquina jogadora de
“Seven & Half” para jogar contra seus clients, digo, seus clientes. O dono do cassino, Mr. H. R. Whole,
deseja que o jogador aposte contra a máquina (que faz as vezes da banca) como descreveremos abaixo.

## Regras do jogo

Daremos primeiramente a descrição do jogo como normalmente é jogado em ABUSA.

• Antes de qualquer sorteio, o apostador aposta x dólas (pronuncia-se dó-las) e a banca “banca”
a aposta, ou seja, faz uma aposta de mesmo valor. Ao final do jogo, o vencedor leva todo o
dinheiro: 2x dólas.

• Tanto a banca quanto o apostador são genericamente chamados de jogador.

• Dizemos que a pontuação de um jogador é o total dos valores das cartas que foram sorteadas
para este jogador. Vence aquele jogador cuja pontuação for maior. Em caso de empate, vence
aquele que fez a pontuação com o menor número de cartas. Caso ainda haja empate a banca
embolsa o dinheiro.

• A banca administra o baralho e sorteia, suponha que honestamente, as cartas. Primeiro, tantas
cartas quanto o apostador quiser; em seguida, tantas cartas quanto a banca desejar para si.

• A cada novo sorteio, a carta sorteada é virada sobre a mesa de modo que o jogador e a banca a
vejam.

• O baralho possui quarenta cartas — é um baralho comum em que foram retiradas as cartas oito,
nove e dez de qualquer dos quatro náipes usuais 1.

• O ás vale 1, as figuras (rei, dama e valete) valem 1/2, as demais cartas valem o número correspondente.

• Caso a pontuação de um jogador supere 7(1/2), situação em que se diz que o jogador estourou, o
jogador perde automaticamente.

• Após um jogo, o vencedor leva os 2x dólas apostados e os jogadores podem reiniciar outro jogo
caso o apostador assim o deseje.

## Estratégias dos jogadores

Cada jogador possui um objetivo e uma estratégia. O objetivo de cada jogador é vencer. Quanto
 às estratégias, estas não são muito mais complicadas.

A estratégia do apostador é pedir que a banca sorteie uma nova carta para ele enquanto achar
necessário. O apostador sabe que precisa ter a maior pontuação possível, sem no entanto estourar.
Assim, adotaremos uma estratégia simples: adotaremos um teto para o apostador. Se sua pontação
corrente for menor que o teto, ele pede mais uma carta; caso contrário, ele diz  à banca que não
quer mais nenhuma carta e, caso o apostador não tenha estourado, ela passa a sortear cartas para si
própria.

A estratégia da banca é mais simples ainda. Se o apostador não tiver estourado (caso contrário a
banca já teria ganho) ela vai sorteando cartas para si enquanto a pontuação obtida não lhe garantir
a vitória sobre o apostador e houver ainda alguma chance de obter uma pontuação vencedora com um
novo sorteio. Ao final, a banca terá feito uma pontuação que lhe garanta a vitória sobre o apostador,
ou terá estourado.

## A simulação

O dono do cassino, Mr. Whole, decidiu contratar vocês para fazer um programa que simule o jogo
de suas máquinas de “Seven n Half”. Como vimos antes, o apostador joga contra a máquina que por
sua vez faz o papel da banca.

Por simplicidade 2, após sortear uma carta qualquer, o jogador em questão contabiliza os pontos
da carta que foi sorteada para si e a carta é devolvida ao baralho. O mesmo é então honestamente
embaralhado antes de um novo sorteio de uma carta, caso seja necessário. Assim, o sorteio de uma
segunda carta é completamente independente da carta sorteada na vez anterior. Pode inclusive repetirse a mesma carta.

Na próxima seção explicamos como deve ser feito o sorteio.

Mr. Hole, digo Mr. Whole, deseja saber se a sua máquina de Seven & Half auferirá bons lucros,
qualquer que seja a estratégia adotada pelo apostador. Por isto, o dono do cassino 3 quer fazer um
programa em C que simule os jogos de suas máquinas. Seu programa deve testar as estratégias do
apostador e da banca CONFORME descrito anteriormente, para todos os valores possíveis que teto
possa assumir. Para cada valor de teto, de 1/2
a 7(1/2)
(em passos de tamanho 1/2
), o programa deve simular
N=10000 jogos e computar em quantos jogos o apostador venceu. Chamemos de derrotas o número
de vezes que o apostador venceu (portanto o número de vezes que a máquina de Mr. Hole Rule Whole
perdeu). Para cada um destes testes com teto em 0.5, 1.0, 1.5, 2.0, . . . , 7.5, o programa deve imprimir
uma linha dizendo qual valor de teto que está sendo considerado, quantas vezes o apostador venceu
(o valor de derrotas) e, em seguida, uma quantidade de caracteres ’*’ que represente o valor de
derrotas, de forma que sejam impressos 100 caracteres quando derrotas for N. Assim, para chao(x)
sendo uma função que devolve o maior inteiro não maior que um real não negativo x, DEVERAO ser ˜
impressos exatamente chao( 100*(derrotas/N) + 0.5 ) caracteres ’*’. Se para teto=2.5 e teto=3
os valores encontrados de derrotas forem, respectivamente, 2049 e 2850, deverão ser impressas linhas
como as abaixo, com 20 e 29 caracteres " * ".

Fazer bons sorteios por computador, que deixem um estatístico satisfeito, é bem difícil, e neste EP
usaremos o seguinte algoritmo.

Adotaremos uma caixa mágica, que contém um número real, e, a cada sorteio, o valor dessa caixa
é alterado conforme as regras:

rifa = 9821.0 * RaizCubica(caixa) + 0.211327

caixa = rifa - chao( rifa )

RaizCubica(x) é uma função que computa a raiz cúbica do real x.
Note que a biblioteca matemática já tem as funções floor e pow que permitem computar
as funções acima. Só que não é para usá-las, nem semelhantes! é parte do
EP implementar as funções acima mencionadas. A partir da definição, é fácil codifícar chao. Para a função RaizCubica, você deve adotar uma aproximação obtida pela
recorrência rn definida como:

Rn = x, se n=0,

Rn = (2/3)*R(n-1) + ((x/3) * ( 1/(R²(n-1) ) ), se n>0

As fórmulas em (1) e (2), executadas nesta ordem, fornecem-nos um número real caixa no intervalo
[0; 1[. Assim define-se a função NovaCaixa, que recebe um real caixa como par^ametro e devolve uma
nova caixa. Para obter um número inteiro entre 1 e 10 em função do novo valor de caixa, basta fazer
a seguinte conta:

carta = chao( caixa*10 + 1 );

Isto nos fornece uma carta, sendo que 8, 9 e 10 representam respectivamente uma dama, valete e
rei. Observe que os naipes não interessam. Sempre que for desejado o sorteio de uma nova carta, o
programa DEVE primeiro obter NovaCaixa(caixa), uma nova caixa em função da corrente, para em
seguida usar o passo (3) de forma a obter a carta correspondente á nova caixa obtida.

Observe que, durante as repetições dos passos (1) e (2), o valor da variável caixa vai sendo
alterado e portanto os valores sorteados para as cartas vão se alterando.

Note que o valor da caixa depende do anterior, mas é preciso começar com algo, também chamado
de semente. Para isso, seu programa deve ler (do teclado) um número inteiro. Em seguida, deve ser
colocado em caixa o número real que decorre de colocar um ponto decimal na frente do desse inteiro
lido.

Ex: se foi lido 12343, caixa = .12343




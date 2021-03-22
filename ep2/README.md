# **Introdução à Ciência da Computação**

<h1>Exercício programa 2 - MAC2166</h1>

# Las Begas

O dono de um cassino de “Las Begas”, em “ABUSA”, pretente fazer uma m´aquina jogadora de
“Seven & Half” para jogar contra seus clients, digo, seus clientes. O dono do cassino, Mr. H. R. Whole,
deseja que o jogador aposte contra a m´aquina (que faz as vezes da banca) como descreveremos abaixo.

## Regras do jogo

Daremos primeiramente a descri¸c˜ao do jogo como normalmente ´e jogado em ABUSA.

• Antes de qualquer sorteio, o apostador aposta x d´olas (pronuncia-se d´o-las) e a banca “banca”
a aposta, ou seja, faz uma aposta de mesmo valor. Ao final do jogo, o vencedor leva todo o
dinheiro: 2x d´olas.

• Tanto a banca quanto o apostador s˜ao genericamente chamados de jogador.

• Dizemos que a pontua¸c˜ao de um jogador ´e o total dos valores das cartas que foram sorteadas
para este jogador. Vence aquele jogador cuja pontua¸c˜ao for maior. Em caso de empate, vence
aquele que fez a pontua¸c˜ao com o menor n´umero de cartas. Caso ainda haja empate a banca
embolsa o dinheiro.

• A banca administra o baralho e sorteia, suponha que honestamente, as cartas. Primeiro, tantas
cartas quanto o apostador quiser; em seguida, tantas cartas quanto a banca desejar para si.

• A cada novo sorteio, a carta sorteada ´e virada sobre a mesa de modo que o jogador e a banca a
vejam.
• O baralho possui quarenta cartas — ´e um baralho comum em que foram retiradas as cartas oito,
nove e dez de qualquer dos quatro n´aipes usuais1
.

• O ´as vale 1, as figuras (rei, dama e valete) valem 1
2
, as demais cartas valem o n´umero correspondente.

• Caso a pontua¸c˜ao de um jogador supere 7 1
2
, situa¸c˜ao em que se diz que o jogador estourou, o
jogador perde automaticamente.

• Ap´os um jogo, o vencedor leva os 2x d´olas apostados e os jogadores podem reiniciar outro jogo
caso o apostador assim o deseje.

## Estrat´egias dos jogadores

Cada jogador possui um objetivo e uma estrat´egia. O objetivo de cada jogador ´e vencer. Quanto
`as estrat´egias, estas n˜ao s˜ao muito mais complicadas.

A estrat´egia do apostador ´e pedir que a banca sorteie uma nova carta para ele enquanto achar
necess´ario. O apostador sabe que precisa ter a maior pontua¸c˜ao poss´ıvel, sem no entanto estourar.
Assim, adotaremos uma estrat´egia simples: adotaremos um teto para o apostador. Se sua ponta¸c˜ao
corrente for menor que o teto, ele pede mais uma carta; caso contr´ario, ele diz `a banca que n˜ao
quer mais nenhuma carta e, caso o apostador n˜ao tenha estourado, ela passa a sortear cartas para si
pr´opria.

A estrat´egia da banca ´e mais simples ainda. Se o apostador n˜ao tiver estourado (caso contr´ario a
banca j´a teria ganho) ela vai sorteando cartas para si enquanto a pontua¸c˜ao obtida n˜ao lhe garantir
a vit´oria sobre o apostador e houver ainda alguma chance de obter uma pontua¸c˜ao vencedora com um
novo sorteio. Ao final, a banca ter´a feito uma pontua¸c˜ao que lhe garanta a vit´oria sobre o apostador,
ou ter´a estourado.

## A simulação

O dono do cassino, Mr. Whole, decidiu contratar vocˆes para fazer um programa que simule o jogo
de suas m´aquinas de “Seven n Half”. Como vimos antes, o apostador joga contra a m´aquina que por
sua vez faz o papel da banca.
Por simplicidade2
, ap´os sortear uma carta qualquer, o jogador em quest˜ao contabiliza os pontos
da carta que foi sorteada para si e a carta ´e devolvida ao baralho. O mesmo ´e ent˜ao honestamente
embaralhado antes de um novo sorteio de uma carta, caso seja necess´ario. Assim, o sorteio de uma
segunda carta ´e completamente independente da carta sorteada na vez anterior. Pode inclusive repetirse a mesma carta.
Na pr´oxima se¸c˜ao explicamos como deve ser feito o sorteio.
Mr. Hole, digo Mr. Whole, deseja saber se a sua m´aquina de Seven & Half auferir´a bons lucros,
qualquer que seja a estrat´egia adotada pelo apostador. Por isto, o dono do cassino3 quer fazer um
programa em C que simule os jogos de suas m´aquinas. Seu programa deve testar as estrat´egias do
apostador e da banca CONFORME descrito anteriormente, para todos os valores poss´ıveis que teto
possa assumir. Para cada valor de teto, de 1
2
a 7 1
2
(em passos de tamanho 1
2
), o programa deve simular
N=10000 jogos e computar em quantos jogos o apostador venceu. Chamemos de derrotas o n´umero
de vezes que o apostador venceu (portanto o n´umero de vezes que a m´aquina de Mr. Hole Rule Whole
perdeu). Para cada um destes testes com teto em 0.5, 1.0, 1.5, 2.0, . . . , 7.5, o programa deve imprimir
uma linha dizendo qual valor de teto que est´a sendo considerado, quantas vezes o apostador venceu
(o valor de derrotas) e, em seguida, uma quantidade de caracteres ’*’ que represente o valor de
derrotas, de forma que sejam impressos 100 caracteres quando derrotas for N. Assim, para chao(x)
sendo uma fun¸c˜ao que devolve o maior inteiro n˜ao maior que um real n˜ao negativo x, DEVERAO ser ˜
impressos exatamente chao( 100*(derrotas/N) + 0.5 ) caracteres ’*’. Se para teto=2.5 e teto=3
os valores encontrados de derrotas forem, respectivamente, 2049 e 2850, dever˜ao ser impressas linhas
como as abaixo, com 20 e 29 caracteres ’*’, respectivamente:
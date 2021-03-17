/***************************************************************/
/**                                                           **/
/**   Vanderson da Silva dos Santos           NUSP:11259715   **/
/**   Exercício-Programa 3                                    **/
/**   Professor: Alair                                        **/
/**   Turma: 3                                                **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define MMAX 90
#define NMAX 90
#define RAND_MAX 12345

//Declacao das funcoes
void MioloDotabuleiro(char comando,int i,int j,int m, int n, int a[MMAX][NMAX],char b[MMAX][NMAX]);
char LetraMaiscula(char a);
void ComecoDoTabuleiro(int n);
void FinalDoTabuleiro(int n);

int main(){
  int m;                    //numero de linhas do campo minado
  int n;                    //numero de colunas do campo minado
  int z;                    //numero de bombas do campo minado
  int i;                    //coordenada da linha dada pelo jogador
  int j;                    //coordenada da coluna dada pelo jogador
  int CaL=0;                //Casas Livres na matriz(A)
  int CaM=0;                //Casas Marcadas na matriz(*)
  int vl;                   //Variavel de passagem para definir quando o cammpo minado deve ser impresso na tela
  int vl2=0;                //variavel de passagem para definir quando o efeito cascata deve continuar
  int verificador=0;        //Variavel de passagem para definir quando a partida terminou
  char comando;             //comando dado pelo jogador para o programa
  int numero;               //variavel para guardar o numero aleatorio gerado
  int cont=0;               //contador 1
  int cont2=0;              //contador 2
  double s;                 //semente
  int mp[MMAX][NMAX]={0};   // matriz principal(armazenerá a quantidade de bombas vizinhas de cada casa do campo minado)
  char mc[MMAX][NMAX];      //matriz que mostra a condição da matriz(aberta, fechada ou marcada);


  printf("Numero de linhas (3 <= m <= 90): ");
  scanf("%d", &m);
  while((m>MMAX)||(m<3)){
     printf("Numero de linhas invalido \n");
     printf("Favor digitar um numero entre 3 e %d \n", MMAX);
     printf("Numero de linhas (3 <= m <= 90): ");
     scanf("%d", &m);}

  printf("Numero de colunas (3 <= n <= 90): ");
  scanf("%d", &n);
  while((n>NMAX)||(n<3)){
     printf("Numero de colunas invalido \n");
     printf("Favor digitar um numero entre 3 e %d \n", NMAX);
     printf("Numero de colunas (3 <= n <= 90): ");
     scanf("%d", &n);}

  printf("Numero de minas (1 <= z <=%d): ", (m*n)-1);
  scanf("%d", &z);
  while((z>((m*n)-1))||(z<1)){
     printf("Numero de minas invalidos \n");
     printf("Favor digitar um numero de bombas entre 1 e %d \n", ((m*n)-1));
     printf("Numero de minas (1 <= z <=%d): ", (m*n)-1);
     scanf("%d", &z);}

  printf("Semente (1 <= s <= 12345): ");
  scanf("%lf",&s);
  while((s<1)||(s>12345)){
    printf("Semente invalida \n");
    printf("Favor digitar uma semente entre 1 e 12345 \n");
    printf("Semente (1 <= s <= 12345): ");
    scanf("%lf",&s);}
  printf("Bem vindo ao Caca-Minas! \n");

  // a contagens das casas comeam pela posicao (1,1) para facilitar a contegem das bombas vizinhas
    for(i=0;i<MMAX;i++){
        for(j=0;j<NMAX;j++){
            mp[i][j]=9;}}
       for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            mc[i][j]='f';
            mp[i][j]=0;}}
    srand(s);
    i=0;
    j=0;
  while(cont!=z){
     numero=rand();
     i=(numero%m)+1;
     j=((numero/m)%n)+1;
     while((mp[i][j]==-1)||(i>m)||(j>n)||(i<1)||(j<1)){
      numero=rand();
      i=(numero%m)+1;
      j=((numero/m)%n)+1;}
      mp[i][j]=-1;
      cont=cont+1;}

  for(i=1;i<=m;i++){
    for(j=1;j<=n;j++){
     if(mp[i][j]!=-1){
        if(mp[i-1][j-1]==-1){
            mp[i][j]=mp[i][j]+1;}
        if(mp[i-1][j]==-1){
            mp[i][j]=mp[i][j]+1;}
        if(mp[i-1][j+1]==-1){
            mp[i][j]=mp[i][j]+1;}
        if(mp[i][j-1]==-1){
            mp[i][j]=mp[i][j]+1;}
        if(mp[i][j+1]==-1){
            mp[i][j]=mp[i][j]+1;}
        if(mp[i+1][j-1]==-1){
            mp[i][j]=mp[i][j]+1;}
        if(mp[i+1][j]==-1){
            mp[i][j]=mp[i][j]+1;}
        if(mp[i+1][j+1]==-1){
            mp[i][j]=mp[i][j]+1;}}}}
    CaL=(m*n)-z;
 //Para evitar colocar uma função dentro da outra ou deixar uma funçao muito grande eu separei a
 //impressao do campo minado em tres funcoes
 ComecoDoTabuleiro(n);
 printf("\n");
 MioloDotabuleiro(comando,i,j,m,n,mp,mc);
 FinalDoTabuleiro(n);
 verificador=1;

 while(verificador!=0){
    vl=0;          //caso vl seja diferente de zero o campo nao sera impresso
    vl2=0;         //caso vl2 seja  zero o efeito cascata de abertura das casas continua
    printf("\n");
    printf("Proximo chute: ");
    scanf(" %c", &comando);
    scanf("%d", &i);
    scanf("%d", &j);
    comando=LetraMaiscula(comando);
    if((comando=='A')&&(mp[i][j]==-1)){
        printf("BOOOOM! Voce acaba de pisar numa mina!.\n");
        verificador=0;}
    if((comando=='M')&&(mc[i][j]=='M')){
        printf("Sem Efeito.\n");
        vl=-1;}
    if((comando=='M')&&(mc[i][j]=='A')){
        printf("Sem Efeito.\n");
        vl=-1;}
    if((comando=='D')&&(mc[i][j]=='A')){
        printf("Sem Efeito.\n");
        vl=-1;}
    if((comando=='D')&&(mc[i][j]=='f')){
        printf("Sem Efeito.\n");
        vl=-1;}
    if((comando=='A')&&(mc[i][j]=='A')){
        printf("Sem Efeito.\n");
        vl=-1;}
    if((comando=='M')&&(CaM==z)){
        printf("Numero maximo de marcacoes.\n");
        printf("Sem Efeito.\n");
        vl=-1;}

  while(vl==0){
    CaM=0;
    CaL=0;
    if((comando=='D')&&(mc[i][j]=='M')){comando='f';}
    mc[i][j]=comando;

    if((mc[i][j]=='A')&&(mp[i][j]==0)){
        while(vl2==0){
        vl2=-1;
        for(cont=1;cont<=m;cont++){
            for(cont2=1;cont2<=n;cont2++){
                    if((mp[cont][cont2]==0)&&(mc[cont][cont2]=='A')){
                       if((mc[cont-1][cont2-1]=='f')){
                          mc[cont-1][cont2-1]='A';
                          vl2=0;}
                       if((mc[cont][cont2-1]=='f')){
                          mc[cont][cont2-1]='A';
                          vl2=0;}
                       if((mc[cont+1][cont2-1]=='f')){
                          mc[cont+1][cont2-1]='A';
                          vl2=0;}
                       if((mc[cont-1][cont2]=='f')){
                          mc[cont-1][cont2]='A';
                          vl2=0;}
                       if((mc[cont+1][cont2]=='f')){
                          mc[cont+1][cont2]='A';
                          vl2=0;}
                       if((mc[cont-1][cont2+1]=='f')){
                          mc[cont-1][cont2+1]='A';
                          vl2=0;}
                       if((mc[cont][cont2+1]=='f')){
                          mc[cont][cont2+1]='A';
                          vl2=0;}
                       if((mc[cont+1][cont2+1]=='f')){
                          mc[cont+1][cont2+1]='A';
                          vl2=0;}
            }}}}}

    if(verificador!=0){                // aqui sera contado o nemero de casa marcadas e casas livre
     for(cont=1;cont<=m;cont++){
        for(cont2=1;cont2<=n;cont2++){
            if(mc[cont][cont2]=='A'){
                CaL=CaL+1;}
            if(mc[cont][cont2]=='M'){
                CaM=CaM+1;}}}
    if((m*n-z-CaL)==0){verificador=0;}
     printf("Por enquanto: %d/%d marcadas, %d livres.\n",CaM,z,(m*n)-z-CaL);}

    ComecoDoTabuleiro(n);
    printf("\n");
    MioloDotabuleiro(comando,i,j,m,n,mp,mc);
    FinalDoTabuleiro(n);
    vl=2;}}
    if((m*n-z-CaL)==0){
        printf("\nParabens, voce atravessou o campo minado sem perder nenhuma parte do corpo!\n");
    }

 return 0;
 }

 //funcoes
void ComecoDoTabuleiro(int n){
  int cont;
  if(n<=10){
   printf("      ");
   for(cont=1;cont<=n;cont++){
       printf("%d  ",cont);}
   printf("  \n   +");
   for(cont=1;cont<=(n*3+2);cont++){
       printf("-");}
   printf("+");}
  if(n>10){
   printf("      ");
   for(cont=1;cont<=10;cont++){
       printf(" %d  ",cont);}
   for(cont=11;cont<=n;cont++){
       printf("%d  ",cont);}
   printf("  \n   +");
   for(cont=1;cont<=(n*4+4);cont++){
       printf("-");}
   printf("+");}
}

void FinalDoTabuleiro(int n){
  int cont;
  if(n<=10){
    printf("   +");
  for(cont=1;cont<=(n*3+2);cont++){
    printf("-");}
  printf("+ \n      ");
  for(cont=1;cont<=n;cont++){
      printf("%d  ",cont);}
  printf("  \n");
}
if(n>10){
    printf("   +");
  for(cont=1;cont<=(n*4+4);cont++){
    printf("-");}
  printf("+ \n      ");
  for(cont=1;cont<=10;cont++){
      printf(" %d  ",cont);}
  for(cont=11;cont<=n;cont++){
      printf("%d  ",cont);}
  printf("  \n");
}}

void MioloDotabuleiro(char comando,int i,int j,int m, int n, int a[MMAX][NMAX],char b[MMAX][NMAX]){
 int cont1;
 int cont2;
   if((b[i][j]=='A')&&(a[i][j]==-1)){
    for(cont1=1;cont1<=m;cont1++){
        for(cont2=1;cont2<=n;cont2++){
            b[cont1][cont2]='A';}}}
   for(cont1=1;cont1<=m;cont1++){
        if((m<10)&&(n<10)){printf("  %d|  ",cont1);}
        if((m<10)&&(n==10)){
            if(cont1<10){
                printf("  %d|  ", cont1);}
            if(cont1>=10){
                printf(" %d|  ",cont1);}
                }
        if((m>=10)&&(n<=10)){
            if(cont1<10){
                printf("  %d|  ", cont1);}
            if(cont1>=10){
                printf(" %d|  ",cont1);}
                }
        if((m<10)&&(n>10)){
            if(cont1<10){
                printf("  %d|   ", cont1);}
            if(cont1>=10){
                printf(" %d|   ",cont1);}
                }
        if((m>10)&&(n>10)){
            if(cont1<10){
                printf("  %d|   ", cont1);}
            if(cont1>=10){
                printf(" %d|   ",cont1);}
                }
    for(cont2=1;cont2<=n;cont2++){
        if((b[cont1][cont2]=='A')){
            if(a[cont1][cont2]!=-1){
              printf("%d", a[cont1][cont2]);}
            if(a[cont1][cont2]==-1){
              printf("@");}}
        if(b[cont1][cont2]=='f'){
            printf(".");}
        if((b[cont1][cont2]=='M')){
            printf("*");}
        if((b[cont1][cont2]=='D')){
            printf(".");}
       if(n<=10){printf("  ");}
       if(n>10){printf("   ");}
        }
 if((m<10)&&(n<10)){printf("|%d \n", cont1);}
 if((m>=10)&&(n<=10)){printf("|%d \n", cont1);}
 if((m<10)&&(n>10)){printf(" |%d \n", cont1);}
 if((m<10)&&(n==10)){printf("|%d \n", cont1);}
 if((m>10)&&(n>10)){printf(" |%d \n", cont1);}}


}

char LetraMaiscula(char a){
  if((a=='a')||(a=='m')||(a=='d')){
    a=a-32;}
return a;}


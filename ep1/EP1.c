/***************************************************************/
/**                                                           **/
/**   Vanderson da Silva dos Santos          NUSP: 11259715   **/
/**   Exercício-Programa 01                                   **/
/**   Professor: Alair                                        **/
/**   Turma: 3                                                **/
/**                                                           **/
/***************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int c;          //quantidade de cores diferentes
    int k;          // numero de casas do numero
    int senha;
    int palpite;
    int pinos=0;    //pinos pretos
    int Npalpites;  // contador de palpites(número de palpites)
    int CNpalpites; //copia do Npalpites
    int Cpalpite;   // copia de palpite
    int Csenha;     // copia da senha
    int a;          // descascador senha
    int b;          // descascador palpite
    int cont=0;     //contador de de tentativas
    int i;

    printf("Entre com o numero de digitos: ");
    scanf("%d", &k);
    printf("Entre com o numero de cores: ");
    scanf("%d", &c);
    printf("Entre com o numero maximo de palpites: ");
    scanf("%d", &Npalpites);
    printf("Entre com a senha de %d digitos (0 para valor aleatorio): ", k);
    scanf("%d",&senha);
    if (senha == 0) {
      srand(time(NULL));
      for (i=0; i<k; i++)
        senha = senha*10 + (rand() % c + 1);}
        CNpalpites= Npalpites;

    while((Npalpites !=0)&&(pinos!=k)){  // o looping só deve terminar quando os palpites acabarem ou a senha for acertada, ou seja, os pinos pretos for igual ao numero de digitos da senha
    printf("Digite seu palpite: ", k);
    scanf("%d", &palpite);
    Cpalpite=palpite;
    Csenha=senha;
    pinos=0;
    do{
        a=Cpalpite%10;
        b=Csenha%10;
        if(a==b){
            pinos= pinos+1;
            Cpalpite=Cpalpite/10;
            Csenha=Csenha/10;}
        else{
            Cpalpite=Cpalpite/10;
            Csenha=Csenha/10;}
        }while((a>0)||(b>0));  //enquanto o numero não for totalmente descascado o loopin irá continuar.
    pinos= pinos-1;
    printf("%d pretos \n", pinos);
    Npalpites= Npalpites-1;
    cont=cont+1;}
    if(pinos==k){
        printf("Parabens! Voce descobriu a senha em %d tentativas", cont);}
    else{
        printf("Sinto muito, mas nenhum dos %d palpites acertaram a senha %d!", CNpalpites,senha);}
    return(0);}

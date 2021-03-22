/**
 *                                                          
 *  @file   EP2.c                                       
 *  @author Vanderson Santos                                                                           
 *  @brief  Exercício Programa 2 - MAC2166 - 2019
 *                                        
 */   

//inicio do programa:
#include <stdio.h>
#include <stdlib.h>

// decla��es de fun��es
double NovaCaixa(double);
int chao(double);
double RaizCubica(double);
int chao(double);
void asteriscos(int);

int main(){
  float j1=0;       //jogador1
  float j2=0;       //jogador 2(banca)
  int vitorias=0;   //vitorias da banca
  int derrotas=0;   //derrotas da banca
  int N=10000;
  int cN=N;         //copia do N
  int na;           //numero de asteriscos
  float teto;
  double caixa;
  double semente;
  double carta;     //carta sorteada
  int n1cartas;     //numero de cartas do jogador 1(por partida)
  int n2cartas;     //numero de cartas do jogador 2(por partida)

  printf("entre uma semente: ");
  scanf("%lf",&semente);
  while(semente>=1){
    semente=(semente/10);
  }
  caixa=semente;

  for(teto=0.5;teto<=7.5;teto=teto+0.5){
    derrotas=0;
    vitorias=0;

    for(cN=10000;cN!=0;cN--){
      n1cartas=0;
      n2cartas=0;
      j1=0;
      j2=0;
      // vez do jogardor 1
      while ((j1<teto)&&(j1<7.5)){
        caixa=NovaCaixa(caixa);
        carta = chao(caixa*10 + 1);
        if(carta>=8){
            carta = 0.5;
        }
        j1=j1+carta;
        n1cartas=n1cartas+1;
        }
      if(j1>7.5){
        vitorias=vitorias+1;
      }
      else{
        // vez do jogador 2(banca)
        while((j1>=j2)&&(j2<7.5)){
          caixa=NovaCaixa(caixa);
          carta=chao(caixa*10 + 1);
          if(carta>=8){
             carta = 0.5;
          }
          j2=j2+carta;
          n2cartas=n2cartas+1;
        }
        if(j2>7.5){
          derrotas=derrotas+1;
        }
        if(j1==j2){
          if(n1cartas>=n2cartas){
            vitorias=vitorias+1;
          }
          if(n1cartas<n2cartas){
            derrotas=derrotas+1;
          }
        }
        if((j1!=j2)&&(j2<=7.5)){
          if(j1<j2){
            vitorias=vitorias+1;
          }
          else{
          derrotas=derrotas+1;}}
      }
    }
    N=10000;
    printf("%.1f  %d ",teto,derrotas);
    na=chao(((100*derrotas)/N)+0.5);
    asteriscos(na);     //fun��o void somente para criar-se os asteriscos.
    printf("\n"); 
  }
  return 0;
 }

// defini��es das fun��es
double RaizCubica(double x){
  double ep=1;      //epsilon
  double rn;        //r(n)
  rn=x;
  for(ep=1;ep>=0.00000001;ep=ep/10){
    rn=(((2*(rn))/3)+(x/(3*(rn*rn))));
  }
  return rn;
 }

double NovaCaixa(double caixa){
  double rifa;
  rifa = (9821.0* RaizCubica(caixa)) + 0.211327;
  caixa = rifa - chao(rifa);
  return caixa;
 }

int chao(double inteiro){
  return inteiro;
 }

void asteriscos(int na){
   while(na>0){
     printf("*");
     na=na-1;
     }
 }



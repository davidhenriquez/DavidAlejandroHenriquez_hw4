#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void onda(int L,float T,float p, int t, float  h_x, float h_y, int N_x, int N_y, float *S);
int main(void){
  int L = 100;
  float T = 40.0;
  float p = 10.0;
  int t = 200;
  float h_x = 4.0;
  float h_y = 1.0;
  int N_x = 25;
  int N_y = 200;
  float S[5201]; 
  
  onda( L, T, p, t, h_x, h_y, N_x, N_y, S);
   
  FILE *in;
  char file[] = "solucion.dat";
  in = fopen(file,"w");
  if(!in){
    exit(1);
  }
  for(int i = 0 ;i<5201; i++){
    fprintf(in,"%f\n",*(S+i));
    }
  fclose(in);
  
  return 0;
}

void onda(int L,float T,float p, int t, float  h_x, float h_y, int N_x, int N_y, float *S){
  float c = sqrt(T/p);
  float r = c*(h_y/h_x);
  for(int i = 0 ; i<5201;i++){
    if ((i>1) && ((i%(N_x+1) == 0) || (i%(N_x+1) == N_x))){
      S[i] = 0.0;
    }
    else if (i<=20){     
      S[i] = (1.25*(4*i))*(1.0/L);
      }
    else if ((i>20) && (i<=25)){
      S[i] = (5-5*(4*i)*(1.0/L));
    }
    else if ((i>25) && (i<52)){
      S[i] = (S[i-N_x-1] + (r*r)*(1.0/2)*(S[i-N_x-1+1]-2*S[i-N_x-1]+S[i-N_x-1-1]));
    }
    else{
      S[i] = (2.0*(1-r*r)*S[i-N_x]-S[i-2*N_x]+(r*r)*(S[i-N_x+1]+S[i-N_x-1]));
    }
  }
}

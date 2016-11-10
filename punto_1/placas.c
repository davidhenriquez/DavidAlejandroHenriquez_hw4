#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void condensador(int L,int l,int d, float h, int  V_0, int N,int n, int t, float *V);
void campo_electrico(float *potencial,float *E_x,float *E_y, int n);
int main(void){
  int L = 5;
  int l = 2;
  int d = 1;
  float h = 0.02;
  int V_0 = 100;
  int N = 2*(L/h)*(L/h);
  int n = 250;
  int t = 63001;
  float V[63001]; 
  float *E_x = malloc(63001*sizeof(float));
  float *E_y = malloc(63001*sizeof(float));
  
  condensador( L, l, d, h, V_0, N, n, t, V);
  campo_electrico( V, E_x, E_y, n);
   
  FILE *in1;
  char file1[] = "potencial.dat";
  in1 = fopen(file1,"w");
  if(!in1){
    exit(1);
  }
  for(int i = 0 ;i<63001; i++){
    fprintf(in1,"%f\n",*(V+i));
  }
  fclose(in1);
    
  FILE *in2;
  char file2[] = "E_x.dat";
  in2 = fopen(file2,"w");
  if(!in2){
    exit(1);
  }
  for(int i = 0 ;i<63001; i++){
    fprintf(in2,"%f\n",*(E_x+i));
  }
  fclose(in2);
  
  FILE *in3;
  char file3[] = "E_y.dat";
  in3 = fopen(file3,"w");
  if(!in3){
    exit(1);
  }
  for(int i = 0 ;i<63001; i++){
    fprintf(in3,"%f\n",*(E_y+i));
  }
  fclose(in3);
  
  return 0;
}

void condensador(int L,int l,int d, float h, int  V_0, int N,int n, int t, float *V){
  float *anterior = malloc(63001*sizeof(float));
  float *cond_iniciales = malloc(63001*sizeof(float));
  for (int i = 0;i<t;i++){
    if (25175<=i && i<25275){
      cond_iniciales[i] =  50.0;
    }
    else if (37725<=i && i<37825){
	cond_iniciales[i] =  -50.0;
    }
    else{
      cond_iniciales[i] = 0.0;
    }
  }
  float *actual = malloc(63001*sizeof(float));
  for(int m = 0 ; m<N;m++){
    if (m==0){     
      for(int z = 0;z<t;z++){
	  V[z] = cond_iniciales[z];
      }
    }
    else{
      for(int z = 0;z<t;z++){
	anterior[z] = V[z];
      }
      for (int k = 0;k<63001;k++){
	if (k<250 || ((k>62750) && (k<63001)) || k%251 == 0 || k%251 == 250){
	    actual[k] = 0.0;
	      }
	  else if (k>=25175 && k<25275){
	    actual[k] =  50.0;
	      }
	  else if (k>=37725 && k<37825){
	    actual[k] =  -50.0;
	      }
	  else {
	      int i = (int) (k/251);
	      int j = k%251;
	      actual[k] = (1.0/4)*(anterior[(i+1)*251+j]+anterior[(i-1)*251+j]+anterior[i*251+j+1]+anterior[i*251+j-1]);  
	      }
	}
	for(int z = 0;z<t;z++){
	  V[z] = actual[z];
	}
    }
  }
}


void campo_electrico(float *potencial,float *E_x,float *E_y, int n){
    for(int i=0;i<62500;i++){
      if(i<250 || ((i>62750 ) && (i<63001)) || i%251 == 0 || i%251 == 250){
	E_x[i]= 0.0;
	E_y[i] = 0.0;
      }
      else{
	E_x[i] = -(*(potencial+i+1)-*(potencial+i))*(1/0.02);
	E_y[i] = -(*(potencial+i+n)-*(potencial+i))*(1/0.02);
      }
    }
    
}


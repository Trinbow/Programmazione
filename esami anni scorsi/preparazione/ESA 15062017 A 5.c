#include <stdio.h>
#include <stdlib.h>

#define N 3

void stampa_matrice(int M[N][N]){
	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%i ", M[i][j]);
		}
		printf("\n");
	}
};
void stampa_vettore(float * a, int length){
	int i;
	for(i=0; i<length; i++){
		printf("%f ", a[i]);
	}
	printf("\n");
};
//prototipi delle funzioni 
float * media_colonne(int M[N][N]);
float * media_righe(int M[N][N]);
void somma(float * C, float * R, float * S,int length);

void main(){
	int M[N][N] = { {1,3,6}, {2,4,8}, {5,7,9} };
	printf("La matrice e':\n");
	stampa_matrice(M);
	
	printf("La media sulle colonne e':\n");
	float * C = media_colonne(M);
	stampa_vettore(C,N);
	
	printf("La media sulle righe e':\n");
	float * R = media_righe(M);
	stampa_vettore(R,N);
	
	printf("La somma di C end R e':\n");
	float S[N];
	somma(C,R,S,N);
	stampa_vettore(S,N);
}
//calcolo la media sulle colonne 
float * media_colonne(int M[N][N]){
	float *a=(float*)malloc(N*sizeof(float));
        float som=0.0;
        for(int i=0;i<N;i++){
		som=0.0;
		for(int j=0;j<N;j++){
			som=som+M[i][j];
		}
		*(a+i)=(float)som/N;
	}
	return a;
}
//calcolo la media sulle righe 
float * media_righe(int M[N][N]){
	float *b=(float*)malloc(N*sizeof(float));
	float som;
	for(int i=0;i<N;i++){
		som=0.0;
		for(int j=0;j<N;j++){
			som=som+M[j][i];
		}
		*(b+i)=(float)som/N;
	}   
	return b;
}
//calcolo la somma delle due array e lo metto nell array S in modo ricorsivo 
void somma(float * C, float * R, float * S,int i){
	
        if(i>0){
		*S= *C + *R ;
		somma(C+1,R+1,S+1,i-1);		
	}
        else{
		printf("\n");
	}
}

#include<stdio.h>
#include<math.h>
#include<complex.h>

#define SIZE 256
#define PI 3.141592653589

void dft(float* x, complex* X, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            X[i] += x[j]*cexp(-I*2*PI*(((float)i)/((float)N))*j);
        }
    }
}

int main(){
    float x[SIZE];
    complex X[SIZE];
    for(int i = 0; i < SIZE; i++){
        x[i] = sin(2*PI*((float)i/(float)SIZE));
    }
    dft(x, X, SIZE);
    for(int i = 0 ; i < SIZE; i++){
        printf("%f\n", cimagf(X[i]));
    }
    return 0;
}
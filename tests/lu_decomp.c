#include<stdio.h>
#include"../matrix.h"

int main(){
    float A[4] = {4, 3, 6, 3};
    float alpha[4] = {0, 0, 0, 0};
    float beta[4] = {0, 0, 0, 0};
    lu_decomp(A, alpha, beta, 2, 2);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%f ", A[i*2+j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%f ", alpha[i*2+j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%f ", beta[i*2+j]);
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
#include"../matrix.h"

int main(){
    float A[9] = {1, 3, 1, 9, 1, 1, -1, 1, 3};
    float alpha[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    float beta[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    lu_decomp(A, alpha, beta, 3, 4);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%f ", A[i*4+j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%f ", alpha[i*4+j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%f ", beta[i*4+j]);
        }
        printf("\n");
    }
    return 0;
}
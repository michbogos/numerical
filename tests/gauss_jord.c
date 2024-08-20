#include<stdio.h>
#include"../matrix.h"

int main(){
    float A[12] = {1, 2, 3, 2, 3, 4};
    gauss_jord(A, 2, 3);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%f ", A[i*3+j]);
        }
        printf("\n");
    }
    return 0;
}
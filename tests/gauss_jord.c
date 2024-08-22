#include<stdio.h>
#include"../matrix.h"

int main(){
    float A[12] = {1, 3, 1, 9, 1, 1, -1, 1, 3, 11, 5, 35};
    gauss_jord(A, 3, 4);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%f ", A[i*4+j]);
        }
        printf("\n");
    }
    return 0;
}
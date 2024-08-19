#include<stdio.h>
#include"../matrix.h"

int main(){
    float A[12] = {3, -2, 1, 1, -1, 1, -1, 2, 5, 2, 10, 39};
    gauss_jord(A, 3, 4);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%f ", A[i*4+j]);
        }
        printf("\n");
    }
    return 0;
}
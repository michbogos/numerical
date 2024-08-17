#include<immintrin.h>

void matmul(float* A, float* B, float* C, int N, int M, int K){
    int masks[16];
    for(int i = 0; i < 8; i++){
        masks[i] = ~(0);
    }
    for(int i = 8; i < 16; i++){
        masks[i] = 0;
    }

    __m256i large_masks[8];
    for(int i = 0; i < 8; i++){
        large_masks[i] = _mm256_set_epi32(masks[i+7], masks[i+6],masks[i+5],masks[i+4],masks[i+3],masks[i+2],masks[i+1],masks[i+0]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            __m256 a = _mm256_set1_ps(A[i*M+j]);
            for(int k = 0; k < (K/8)*8; k+=8){
                // mask = K-k < 8 ? large_masks[8-(K-k)]:large_masks[0];
                _mm256_storeu_ps(&C[i*K+k], _mm256_fmadd_ps(a, _mm256_loadu_ps(&B[j*K+k]),_mm256_loadu_ps(&C[i*K+k])));
                // mat3[i*K+k] += mat1[i*M+j]*mat2[j*K+k];
            }
        }
    }
    if(K%8!=0){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                __m256 a = _mm256_set1_ps(A[i*M+j]);
                int k = (K/8)*8;
                __m256i mask = large_masks[8-(K-k)];
                _mm256_maskstore_ps(&C[i*K+k], mask, _mm256_fmadd_ps(a, _mm256_maskload_ps(&B[j*K+k], mask),_mm256_maskload_ps(&C[i*K+k], mask)));
            }
        }
    }
}
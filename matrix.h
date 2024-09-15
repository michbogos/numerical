#include<immintrin.h>
#include<math.h>

float* mat_translate4x4(){

}

float* mat_scale4x4(){

}

float* mat_rotation4x4(){

}

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

void pivot_row(float A[], int N, int M, int row1, int row2){
    float tmp[M];
    for(int i = 0; i < M; i++){
        tmp[i] = A[row1*M+i];
        A[row1*M+i] = A[row2*M+i];
    }
    for(int i = 0; i < M; i++){
        A[row2*M+i] = tmp[i];
    }
}

void gauss_jord(float A[], int N, int M){ // Linear equation in matrix form with appended solution
    for(int i = 0; i < N; i++){
        if(fabs(A[i*M+i])<0.0001f){
            int idx = i;
            float mag = 0.0f;
            for(int m = i; m < N; m++){
                if(fabsf(A[m*M+i])>mag){
                    idx = m;
                    mag = fabsf(A[m*M+i]);
                }
            }
            pivot_row(A, N, M, i, idx);
        }
        float coeff = A[i*M+i];
        if(fabs(coeff)<0.00001){
            continue;
        }
        for(int j = i; j < M; j++){
            A[i*M+j]/=coeff;
        }
        for(int k = i+1; k < N; k++){
            if(fabsf(A[k*M+i]) < 0.0001){
                if(fabsf(A[k*M+i]) < 0.0001 && k==N-1){
                    continue;
                }
                int idx = k;
                float mag = 0.0f;
                for(int m = k; m < N; m++){
                    if(fabsf(A[m*M+i])>mag){
                        idx = m;
                        mag = fabsf(A[m*M+i]);
                    }
                }
                pivot_row(A, N, M, k, idx);
            }
            float subcoeff = A[k*M+i];
            if(fabsf(subcoeff) < 0.0001f){
                continue;
            }
            for(int  l = i; l < M; l++){
                A[k*M+l]-=subcoeff*A[i*M+l];
            }
        }
    }

    for(int i = N-1; i >= 0; i--){
        if(fabsf(A[i*M+i])<0.00001f) continue;
        float coeff = A[(i-1)*M+i];
        for(int j = i; j < M; j++){
            A[(i-1)*M+j] -= coeff*A[i*M+j];
        }
    }
}

void lu_decomp(float A[], float* alpha, float*  beta, int N, int M){
    for(int i = 0; i < N; i++){
        alpha[i*M+i] = 1.0f;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            beta[i*M+j] = A[i*M+j];
            for(int k = 0; k < i-1; k++){
                beta[i*M+j] -= alpha[i*M+k]*beta[k*M+j];
            }
            alpha[i*M+j] = A[i*M+j];
            for(int k = 0; k < j-1; k++){
                alpha[i*M+j] -= alpha[i*M+k]*beta[k*M+j];
            }
            alpha[i*M+j] /= beta[j*M+j];
        }
    }
}

void mat_free(float* mat){
    free(mat);
}
#include<stdio.h>
#include<math.h>
#include<complex.h>

#define SIZE 4096
#define PI 3.141592653589




int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void dft(float* x, complex* X, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            X[i] += x[j]*cexp(-I*2*PI*(((float)i)/((float)N))*j);
        }
    }
}

//Broken
void ditfft(float* x, complex* X, int N, int s){
    if(N==1){
        X[0] = x[0];
    }
    ditfft(x, X, N/2, 2*s);
    ditfft(x+s, X+s, N/2, 2*s);
    for(int k = 0; k < N/2; k++){
        complex p = X[k];
        complex q = cexpf((-2*PI*I/N)*k)*X[k+N/2];
        X[k] = p+q;
        X[k+N/2] = p-q;
    }
}

void fft(complex* x, int N){
    int log_n = 0;
    while((1<<log_n) < N){
        log_n ++;
    }
    for(int i = 0; i < N; i++){
        int rev = reverse(i, log_n);
        if(i < rev){
            float tmp = x[i];
            x[i] = x[rev];
            x[rev] = tmp;
        }
    }
    for (int len = 2; len <= N; len <<= 1) {
        double ang = 2 * PI / len;
        complex wlen = cos(ang)+I*sin(ang);
        for (int i = 0; i < N; i += len) {
            complex w = 1.0;
            for (int j = 0; j < len / 2; j++) {
                complex u = x[i+j];
                complex v = x[i+j+len/2] * w;
                x[i+j] = u + v;
                x[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
}

int main(){
    complex x[SIZE];
    complex X[SIZE];
    for(int i = 0; i < SIZE; i++){
        if((i/101)%2){
            x[i] = 1;
        }
        else{
            x[i] = 0;
        }
    }
    fft(x, SIZE);
    for(int i = 0 ; i < SIZE; i++){
        printf("%f\n", cabsf(x[i]));
    }
    return 0;
}
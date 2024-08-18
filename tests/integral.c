#include<stdio.h>
#include<math.h>
#include<assert.h>
#include"../integral.h"

#define PI 3.1415926

float f(float x){
    return sin(x);
}

int main(){
    assert(fabsf(qsimpf(f, 0, 3.14159265, 1000)-2) < 0.00001);
    return 0;
}
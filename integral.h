float qsimpf(float(*func)(float), float a, float b, int N){
    float h = (a-b)/(float)N;
    float res = func(a);
    for(int i = 1; i < N; i++){
        res += func(a+(h*i))*h*((i&1)?4.0f:2.0f);
    }
    res += func(b);
    res /= 3.0f;
    return res;
}
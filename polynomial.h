float poly_eval(float* coeffs, int num_coeffs, float x){
    float res = coeffs[num_coeffs-1];
    for(int i = num_coeffs-2 ; i > 0; i--) res = res*x+coeffs[i];
    return res;
}
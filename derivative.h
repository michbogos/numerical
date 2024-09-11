float deriv_central(float(*func)(float), float x, float h){
    return (func(x+h/2)-func(x-h/2))/h;
}
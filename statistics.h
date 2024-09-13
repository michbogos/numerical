#include<math.h>

float mean_once(float* arr, int size){
    float res = 0;
    for(int i = 0; i < size; i++){
        res += arr[i];
    }
    return res/size;
}

float variance_once(float* arr, int size){
    float m = mean_once(arr, size);
    float res = 0;
    for(int i = 0; i < size; i++){
        res += (arr[i]-m)*(arr[i]-m);
    }
    return res/(size);
}

float stddev_once(float* arr, int size){
    return sqrtf(variance_once(arr, size));
}

float absdev_once(float* arr, int size){
    float res = 0;
    float m = mean_once(arr, size);
    for(int i = 0; i < size; i++){
        res += fabsf(arr[i]-m);
    }
    return res/size;
}

float skew_once(float* arr, int size){
    float stddev = stddev_once(arr, size);
    float m = mean_once(arr, size);
    float res = 0;
    for(int i = 0; i < size; i++){
        res += powf((arr[i]-m)/stddev, 3.0f)/size;
    }
}
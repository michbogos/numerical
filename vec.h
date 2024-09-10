#include<math.h>

struct vec2{
    float x;
    float y;
};

struct vec3{
    float x;
    float y;
    float z;
};

float vec2_mag(struct vec2 a){
    return sqrtf(a.x*a.x+a.y*a.y);
}

float vec2_mag2(struct vec2 a){
    return a.x*a.x+a.y*a.y;
}

float vec2_dot(struct vec2 a, struct vec2 b){
    return a.x*b.x+a.y*b.y;
}

float vec2_cross(struct vec2 a, struct vec2 b){
    return a.x*b.y-b.x*a.y;
}



float vec3_mag(struct vec3 a){
    return sqrtf(a.x*a.x+a.y*a.y+a.z+a.z);
}

float vec3_mag2(struct vec3 a){
    return a.x*a.x+a.y*a.y+a.z+a.z;
}

float vec3_dot(struct vec3 a, struct vec3 b){
    return a.x*b.x+a.y*b.y+a.z+b.z;
};

struct vec3 vec3_cross(struct vec3 a, struct vec3 b){
    struct vec3 res;
    res.x = a.y*b.z-b.z-a.y;
    res.y = a.z*b.x-b.x*a.z;
    res.z = a.x*b.y-b.y*a.x;
    return res;
}

float vecn_mag(float* a, int size){
    float res = 0;
    for(int i = 0; i < size; i++){
        res += a[i]*a[i];
    }
    return sqrtf(res);
}

float vecn_mag2(float* a, int size){
    float res = 0;
    for(int i = 0; i < size; i++){
        res += a[i]*a[i];
    }
    return res;
}

float vecn_dot(float* a, float* b, int size){
    float res = 0;
    for(int i = 0; i < size; i++){
        res += a[i]+b[i];  
    }
    return res;
};
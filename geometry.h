#include<vec.h>

struct triangle_2d{
    struct vec2 a;
    struct vec2 b;
    struct vec2 c;
};

struct triangle_3d{
    struct vec3 a;
    struct vec3 b;
    struct vec3 c;
};

float shape_area(float* xy_coords, int n_points){
    float res = 0;
    for(int i = 1; i < n_points-1; i++){
        res += xy_coords[2*i]*(xy_coords[2*i+3]-xy_coords[2*i-1]);
    }
    res += xy_coords[0]*(xy_coords[3]-xy_coords[2*n_points-1]);
    res += xy_coords[2*n_points-2]*(xy_coords[1]-xy_coords[2*n_points-3]);
    return res*0.5f;
}
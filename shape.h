float shape_area(float* xy_coords, int n_points){
    float res = 0;
    for(int i = 1; i < n_points-1; i++){
        res += xy_coords[2*i]*(xy_coords[2*i+3]-xy_coords[2*i-1]);
    }
    res += xy_coords[0]*(xy_coords[3]-xy_coords[2*n_points-1]);
    res += xy_coords[2*n_points-2]*(xy_coords[1]-xy_coords[2*n_points-3]);
    return res*0.5f;
}
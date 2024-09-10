struct rand_state{
    unsigned long long state;
    unsigned long long inc;
};

unsigned int rand_uint(struct rand_state* rng){
    unsigned long long oldstate = rng->state;
    rng->state = oldstate * 6364136223846793005ULL + (rng->inc|1);
    unsigned int xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    unsigned int rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

float randf(struct rand_state* rng, float min, float max){
    return max > min ? min+((float)rand_uint(rng)/(float)(__UINT32_MAX__))*(max-min) : max+((float)rand_uint(rng)/(float)(__UINT32_MAX__))*(min-max);
}

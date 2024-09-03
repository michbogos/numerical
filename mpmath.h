#include<stdlib.h>

struct mp_num{
    unsigned char* data;
    unsigned int size;
};

struct mp_num mp_zero(unsigned int precision){
    unsigned char* data = (unsigned char*)malloc(precision);
    struct mp_num num;
    num.data = data;
    num.size = precision;
    return num;
}

void mp_resize(struct mp_num* num){
    realloc(num->data, num->size*2);
    num->size *= 2;
}

struct mp_num mp_add(struct mp_num a, struct mp_num b){
    struct mp_num c;
    unsigned char carry = 0;
    unsigned int maxsize = a.size > b.size ? a.size : b.size;
    unsigned int minsize = a.size < b.size ? a.size : b.size;

    c = mp_zero(maxsize);

    for(int i = 0; i < minsize; i++){
        unsigned char tmpa = a.data[i];
        unsigned char tmpb = b.data[i];
        c.data[i] = a.data[i]+b.data[i]+carry;
        carry = (int)(a.data[i]+b.data[i]+carry)>255 ? 1 : 0;
    }
    if(carry && (minsize==maxsize)){
        mp_resize(&c);
        c.data[minsize] = carry;
    }
    if(carry && (minsize < maxsize)){
        c.data[minsize] = carry;
    }
    return c;
}

struct mp_num mp_sub(struct mp_num a, struct mp_num b){
    struct mp_num c;
    unsigned char carry = 0;
    unsigned int maxsize = a.size > b.size ? a.size : b.size;
    unsigned int minsize = a.size < b.size ? a.size : b.size;

    c = mp_zero(maxsize);

    for(int i = 0; i < minsize; i++){
        unsigned char tmpa = a.data[i];
        unsigned char tmpb = b.data[i];
        c.data[i] = a.data[i]-b.data[i]-carry;
        carry = (int)(a.data[i]-b.data[i]-carry)<0 ? 1 : 0;
    }
    if(carry && (minsize==maxsize)){
        mp_resize(&c);
        c.data[minsize] -= carry;
    }
    if(carry && (minsize < maxsize)){
        c.data[minsize] -= carry;
    }
    return c;
}

struct mp_num mp_smul(struct mp_num a, unsigned char b){
    struct mp_num c;
    unsigned char carry = 0;
    unsigned int size = a.size;

    c = mp_zero(size);

    for(int i = 0; i < size; i++){
        c.data[i] = a.data[i]*b+carry;
        carry = (int)(a.data[i]*b+carry)-c.data[i];
    }
    if(carry){
        mp_resize(&c);
        c.data[size] -= carry;
    }
    return c;
}


void mp_free(struct mp_num num){
    free(num.data);
}
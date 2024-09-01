#include<stdlib.h>

struct mp_num{
    char* data;
    unsigned int size;
};

struct np_num mp_zero(){
    char* data = (char*)malloc(16);
    struct mp_num num;
    num.data = data;
    num.size = 16;
    return num;
}

void mp_resize(struct mp_num* num){
    realloc(num->data, num->size*2);
}

void mp_free(struct mp_num num){
    free(num.data);
}
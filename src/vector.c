#include <stdlib.h>
#include "stdio.h"
#include "vector.h"
#include "func.h"

vector_t *vector_init(size_t len){
    vector_t *vec = calloc(1, sizeof(vector_t));
    vec->len = len;
    vec->vector = calloc(len, sizeof(void*));
    vec->cursor = 0;
    return vec;
}

void vector_free(vector_t *vec){
    free(vec->vector);
    free(vec);
}

void vector_append(vector_t *vec, void *data){
    vec->vector[vec->cursor++] = data;
    if((float)(vec->len - vec->cursor)/(float)vec->len * 100 > 80){
        vec->vector = realloc(vec->vector, vec->len * 1.75 * sizeof(void*));
        vec->len *= 1.75;
    }
}

void vector_insert(vector_t *vec, void *data, size_t i){
    if(vec->len < i){
        vec->vector = realloc(vec->vector, (vec->len + i) * 1.75 * sizeof(void*));
        vec->len = (vec->len + i) * 1.75;
        vec->vector[i] = data;
    }
    else {
        vec->vector[vec->cursor] = data;
        puts((char*)data);
        if((float)(vec->len - vec->cursor)/(float)vec->len * 100 > 80){
            vec->vector = realloc(vec->vector, vec->len * 1.75 * sizeof(void*));;
            vec->len *= 1.75;
        }
    }
}

either_t *vector_at_index(vector_t *vec, size_t i){
    if(vec->len < i){
        error_t *er = calloc(1, sizeof(error_t));
        er->err = VEC_ERR_OUT_OF_RANGE;
        er->str = "vector index out of range";
        return LEFT(er);
    }
    return RIGHT(vec->vector[i]);
}

#ifndef __VECTOR_H__
    #define __VECTOR_H__

    #include "func.h"

    typedef struct {
        void **vector;
        size_t len;
        size_t cursor;
    } vector_t;

    enum vector_error_codes {
        VEC_ERR_OUT_OF_RANGE = -1,  
    };

    vector_t *vector_init(size_t len);
    void vector_free(vector_t *vec);
    void vector_append(vector_t *vec, void *data);
    void vector_insert(vector_t *vec, void *data, size_t i);
    either_t *vector_at_index(vector_t *vec, size_t i);

#endif

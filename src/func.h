#ifndef __FUNC_H__
    #define __FUNC_H__

    #define S_LEFT 0
    #define S_RIGHT 1

    #define LEFT(data) (either_init(S_LEFT, data))
    #define RIGHT(data) (either_init(S_RIGHT, data))

    typedef struct {
        int side;
        union {
            void *left;
            void *right;
        };
    } either_t;

    typedef struct {
        int err;
        const char *str;
    } error_t;

    size_t map(void **array, size_t len, void (*func)(void*));
    size_t filter(void **array, void **res, size_t len, int (*func)(void*));
    float average(int *array, size_t len);
    size_t reduce(void **array, void *res, size_t len, void (*func)(void*, void*));

    either_t *either_init(int side, void *data);
    either_t *either(either_t *e, void *(*l)(void*), void *(*r)(void*));
    int isright(either_t *e);
    int isleft(either_t *e);

    error_t *error_init(int n);
#endif

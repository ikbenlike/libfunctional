#ifndef __FUNC_H__
    #define __FUNC_H__

    int map(void **array, size_t len, void (*func)(void*));
    int filter(void **array, void **res, size_t len, int (*func)(void*));
    float average(int *array, size_t len);
#endif

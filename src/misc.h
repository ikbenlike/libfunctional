#ifndef __MISC_H__
    #define __MISC_H__

    either_t *ew_calloc(size_t nmemb, size_t size);
    either_t *ew_malloc(size_t size);
    either_t *ew_realloc(void *ptr, size_t size);
    either_t *ew_getenv(const char *name);
    either_t *ew_memchr(const void *s, int c, size_t n);
    either_t *ew_strchr(const char *s, int c);
    either_t *ew_strrchr(const char *s, int c);
    either_t *ew_puts(const char *s);

#endif

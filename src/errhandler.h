#ifndef ERRHANDLER_H
#define ERRHANDLER_H

#define F_UNKNOWN -1
#define S_SUCCESS 0
#define F_ALLOCATION 1
#define F_INVALID_INDEX 2

#include <stddef.h>

typedef struct {
    int type;
    void *data;
    size_t size;
} Result;

Result *create_result(int type, void *data, size_t size);
int destroy_result(Result *res);
void *unwrap(Result *res);

#endif

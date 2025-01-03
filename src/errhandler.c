#include "errhandler.h"
#include <stdlib.h>
#include <string.h>

void *unwrap(Result *res) {
    if (!res) return NULL;
    if (!res->data) return NULL;
    return res->data;
}

Result *create_result(int type, void *data, size_t size) {
    Result *res = (Result *)malloc(sizeof(Result));
    if (!res) return NULL;

    res->type = type;
    res->size = size;
    if (data && size > 0) {
        res->data = malloc(size);
        if (!res->data) {
            free(res);
            return NULL;
        }
        memcpy(res->data, data, size);
    } else {
        res->data = NULL;  // Don't allocate if there's no data
    }

    return res;
}

int destroy_result(Result *res) {
    if (!res) return 1;
    free(res->data);
    free(res);
    return 0;
}

#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include "errhandler.h"

typedef struct {
    size_t dimensions;
    float *data;
} Vector;

Result *vec(size_t dimensions);

Result *vecdestroy(Vector *vec);

Result *vecset(Vector *vec, size_t dimention, float value);

Result *vecget(Vector *vec, size_t dimention);

Result *vecadd(Vector *left, Vector *right);

Result *vecsub(Vector* left, Vector *right);

Result *vecdot(Vector *left, Vector *right);

Result *vecmagnitude(Vector *vec);

Result *vecnormalize(Vector *vec);

#endif

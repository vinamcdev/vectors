#include "vectors.h"
#include "errhandler.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

Result *vec(size_t dimensions) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if (!vec) create_result(F_ALLOCATION, NULL, sizeof(NULL));

    vec->data = (float *)malloc(sizeof(float) * dimensions);
    if (!vec->data) { free(vec); return create_result(F_ALLOCATION, NULL, sizeof(NULL)); }
    vec->dimensions = dimensions;

    for (size_t i = 0; i < dimensions; ++i) {
        vec->data[i] = 0.0f;
    }
    return create_result(S_SUCCESS, vec, sizeof(Vector));
}

Result *vecdestroy(Vector *vec) {
    if (!vec) return create_result(F_ALLOCATION, NULL, sizeof(NULL));
    free(vec->data);
    free(vec);
    return create_result(S_SUCCESS, NULL, sizeof(NULL));
}

Result *vecset(Vector *vec, size_t dimension, float value) {
    if (vec->dimensions < dimension) return create_result(F_INVALID_INDEX, NULL, sizeof(NULL));
    vec->data[dimension] = value;
    return create_result(S_SUCCESS, NULL, sizeof(NULL));
}

Result *vecget(Vector *vec, size_t dimension) {
    if (vec->dimensions < dimension) return create_result(F_INVALID_INDEX, NULL, sizeof(NULL));
    float data = vec->data[dimension];
    return create_result(S_SUCCESS, &data, sizeof(float));
}

Result *vecadd(Vector *left, Vector *right) {
    if (!left || !right) return create_result(F_ALLOCATION, NULL, sizeof(NULL));
    if (left->dimensions != right->dimensions) return create_result(F_UNKNOWN, NULL, sizeof(NULL));
    Vector *result = unwrap(vec(left->dimensions));
    for (size_t i = 0; i < left->dimensions; ++i) {
        result->data[i] = left->data[i] + right->data[i];
    }
    return create_result(S_SUCCESS, result, sizeof(Vector));
}

Result *vecsub(Vector *left, Vector *right) {
    if (!left || !right) return create_result(F_ALLOCATION, NULL, sizeof(NULL));
    if (left->dimensions != right->dimensions) return create_result(F_UNKNOWN, NULL, sizeof(NULL));
    Vector *result = unwrap(vec(left->dimensions));
    for (size_t i = 0; i < left->dimensions; ++i) {
        result->data[i] = left->data[i] - right->data[i];
    }
    return create_result(S_SUCCESS, result, sizeof(Vector));
}

Result *vecdot(Vector *left, Vector *right) {
    if (!left || !right) return create_result(F_ALLOCATION, NULL, sizeof(NULL));
    if (left->dimensions != right->dimensions) return create_result(F_UNKNOWN, NULL, sizeof(NULL));
    float result = 0.0f;
    for (size_t i = 0; i < left->dimensions; ++i) {
        result += left->data[i] * right->data[i];
    }
    return create_result(S_SUCCESS, &result, sizeof(float));
}

Result *vecmagnitude(Vector *vec) {
    if (!vec) return create_result(F_ALLOCATION, NULL, sizeof(NULL));
    float result = 0.0f;
    for (size_t i = 0; i < vec->dimensions; ++i) {
        result += vec->data[i] * vec->data[i];
    }
    result = sqrt(result);
    return create_result(S_SUCCESS, &result, sizeof(float));
}

Result *vecnormalize(Vector *vec) {
    if (!vec) return create_result(F_ALLOCATION, NULL, sizeof(NULL));
    for (size_t i = 0; i < vec->dimensions; ++i) {
        float data;
        memcpy(&data, vecmagnitude(vec)->data, sizeof(float));
        vec->data[i] /= data;
    }
    return create_result(S_SUCCESS, NULL, sizeof(NULL));
}

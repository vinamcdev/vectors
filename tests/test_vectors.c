#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../src/vectors.h"  // Assuming the vector functions are defined here

// Test for creating a vector
void test_create_vector() {
    Vector *v = unwrap(vec(3));  // Create a vector of size 3
    CU_ASSERT(v != NULL);  // Ensure the vector is not NULL
    CU_ASSERT(v->dimensions == 3);  // Ensure it has 3 dimensions
    CU_ASSERT(v->data != NULL);  // Ensure the data pointer is not NULL
    for (int i = 0; i < 3; ++i) {
        CU_ASSERT(v->data[i] == 0.0f);  // Ensure it's initialized to 0
    }
    vecdestroy(v);  // Clean up after test
}

// Test for setting values in a vector
void test_set_vector_values() {
    Vector *v = unwrap(vec(3));  // Create a vector of size 3
    vecset(v, 0, 1.0f);  // Set value at index 0
    vecset(v, 1, 2.0f);  // Set value at index 1
    vecset(v, 2, 3.0f);  // Set value at index 2

    // Check the set values
    CU_ASSERT(v->data[0] == 1.0f);
    CU_ASSERT(v->data[1] == 2.0f);
    CU_ASSERT(v->data[2] == 3.0f);

    vecdestroy(v);  // Clean up after test
}

// Test for getting values from a vector
void test_get_vector_values() {
    Vector *v = unwrap(vec(3));  // Create a vector of size 3
    vecset(v, 0, 1.0f);  // Set value at index 0
    vecset(v, 1, 2.0f);  // Set value at index 1
    vecset(v, 2, 3.0f);  // Set value at index 2

    Result *res = vecget(v, 0);  // Get value at index 0
    CU_ASSERT(res->type == S_SUCCESS);  // Ensure the result is successful
    float value = *(float *)unwrap(res);
    CU_ASSERT(value == 1.0f);  // Ensure the value matches
    destroy_result(res);

    res = vecget(v, 1);  // Get value at index 1
    value = *(float *)unwrap(res);
    CU_ASSERT(value == 2.0f);  // Ensure the value matches
    destroy_result(res);

    res = vecget(v, 2);  // Get value at index 2
    value = *(float *)unwrap(res);
    CU_ASSERT(value == 3.0f);  // Ensure the value matches
    destroy_result(res);

    vecdestroy(v);  // Clean up after test
}

// Test for vector addition
void test_vector_addition() {
    Vector *v1 = unwrap(vec(3));  // Create vector 1
    Vector *v2 = unwrap(vec(3));  // Create vector 2
    vecset(v1, 0, 1.0f);  // Set values in vector 1
    vecset(v1, 1, 2.0f);
    vecset(v1, 2, 3.0f);
    vecset(v2, 0, 4.0f);  // Set values in vector 2
    vecset(v2, 1, 5.0f);
    vecset(v2, 2, 6.0f);

    Result *res = vecadd(v1, v2);  // Add the two vectors
    CU_ASSERT(res->type == S_SUCCESS);  // Ensure the result is successful
    Vector *sum = unwrap(res);

    // Check the sum of the vectors
    CU_ASSERT(sum->data[0] == 5.0f);
    CU_ASSERT(sum->data[1] == 7.0f);
    CU_ASSERT(sum->data[2] == 9.0f);

    vecdestroy(v1);  // Clean up after test
    vecdestroy(v2);
    vecdestroy(sum);
    destroy_result(res);
}

// Test for vector magnitude
void test_vector_magnitude() {
    Vector *v = unwrap(vec(3));  // Create a vector of size 3
    vecset(v, 0, 3.0f);  // Set values in the vector
    vecset(v, 1, 4.0f);
    vecset(v, 2, 12.0f);

    Result *res = vecmagnitude(v);  // Get the magnitude of the vector
    CU_ASSERT(res->type == S_SUCCESS);  // Ensure the result is successful
    float magnitude = *(float *)unwrap(res);

    // Check the magnitude (should be 13.0 for this vector)
    CU_ASSERT(fabs(magnitude - 13.0f) < 0.0001f);

    vecdestroy(v);  // Clean up after test
    destroy_result(res);
}

// Main function for running tests
int main() {
    // Initialize CUnit's registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add test suites
    CU_pSuite pSuite = CU_add_suite("Vector Operations Test Suite", 0, 0);

    // Add tests to the suite
    CU_add_test(pSuite, "Test Vector Creation", test_create_vector);
    CU_add_test(pSuite, "Test Set Vector Values", test_set_vector_values);
    CU_add_test(pSuite, "Test Get Vector Values", test_get_vector_values);
    CU_add_test(pSuite, "Test Vector Addition", test_vector_addition);
    CU_add_test(pSuite, "Test Vector Magnitude", test_vector_magnitude);

    // Run the tests
    CU_basic_run_tests();

    // Clean up and return
    CU_cleanup_registry();
    return 0;
}

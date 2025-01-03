# ~~lib~~vectors
> a small vector mathematics library

# Documentation
## vectors.h
### Functions Overview
#### `vec(size_t dimensions)`
- **Description**: Creates a new vector with the given number of dimensions, initialized with zeros.
- **Parameters**:
  - `dimensions`: The number of dimensions for the vector.
- **Returns**: A `Result` containing a pointer to the newly created `Vector` or an error code.

#### `vecdestroy(Vector *vec)`
- **Description**: Destroys the given vector, freeing all allocated memory for the vector and its components.
- **Parameters**:
  - `vec`: The vector to be destroyed.
- **Returns**: A `Result` indicating success or failure.

#### `vecset(Vector *vec, size_t dimension, float value)`
- **Description**: Sets the value of a specific dimension in the vector.
- **Parameters**:
  - `vec`: The vector in which to set the value.
  - `dimension`: The index of the dimension to modify.
  - `value`: The value to set at the specified dimension.
- **Returns**: A `Result` indicating success or failure. If the index is out of bounds, it returns an error.

#### `vecget(Vector *vec, size_t dimension)`
- **Description**: Retrieves the value at a specific dimension in the vector.
- **Parameters**:
  - `vec`: The vector to retrieve the value from.
  - `dimension`: The index of the dimension to retrieve.
- **Returns**: A `Result` containing the value at the specified dimension or an error code.

#### `vecadd(Vector *left, Vector *right)`
- **Description**: Adds two vectors together element-wise.
- **Parameters**:
  - `left`: The left-hand side vector.
  - `right`: The right-hand side vector.
- **Returns**: A `Result` containing the resulting vector or an error code (e.g., if the vectors have different dimensions).

#### `vecsub(Vector *left, Vector *right)`
- **Description**: Subtracts the right vector from the left vector element-wise.
- **Parameters**:
  - `left`: The left-hand side vector.
  - `right`: The right-hand side vector.
- **Returns**: A `Result` containing the resulting vector or an error code (e.g., if the vectors have different dimensions).

#### `vecdot(Vector *left, Vector *right)`
- **Description**: Calculates the dot product of two vectors.
- **Parameters**:
  - `left`: The left-hand side vector.
  - `right`: The right-hand side vector.
- **Returns**: A `Result` containing the dot product as a float or an error code (e.g., if the vectors have different dimensions).

#### `vecmagnitude(Vector *vec)`
- **Description**: Calculates the magnitude (length) of the vector.
- **Parameters**:
  - `vec`: The vector whose magnitude is to be calculated.
- **Returns**: A `Result` containing the magnitude of the vector as a float.

#### `vecnormalize(Vector *vec)`
- **Description**: Normalizes the vector so that its magnitude is 1.
- **Parameters**:
  - `vec`: The vector to normalize.
- **Returns**: A `Result` indicating success or failure. If the vector has a magnitude of 0, it returns an error.

## errhandler.h
### Functions Overview
#### `unwrap(Result *res)`
- **Description**: Returns the data, ignoring the result type (`type`)
- **Parameters**:
  - `res`: The result to unwrap.
- **Returns**: A `void *` pointing to the data that is wrapped (ambiguous)

#### `create_result(int type, void *data, size_t size)`
- **Description**: Creates a new result wrapper with the specified information.
- **Parameters**:
  - `type`: The return type, non-zero ouputs are failures.
  - `data`: Any data that is wanted to pass alongside the `type` parameter.
  - `size`: The size of the data type.
- **Returns**: A `Result` containing all data specified.

#### `destroy_result(Result *res)`
- **Description**: Destroys and frees the memory allocated to the result.
- **Parameters**:
  - `res`: The result to destroy.
- **Returns**: An `int` specifying its success or failure.

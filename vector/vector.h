#include <string.h>

#ifndef LIB_VECTOR_H
#define LIB_VECTOR_H

// Simple dynamic array
typedef struct vector
{
    // total number of array elements
    size_t count;
    // the number of bytes occupied by one element
    size_t block_size;
    char *data;
} vector;

// Creating a dynamic structure
vector *make_v(size_t block_size);
// Memory release occupied by the structure
void free_v(vector *v);
// Return of the value of the specified element of the structure data array
void *get_v(vector *v, size_t idx);
// Adding an element to the end of the structure array
void push_v(vector *v, void *data);
// Changing the specified structure element
void set_v(vector *v, size_t count, void *data);
// Deleting the specified structure element
void delete_v(vector *v, size_t idx);
// Clearing data
void clear_v(vector *v);
#endif //VECTOR_VECTOR_H

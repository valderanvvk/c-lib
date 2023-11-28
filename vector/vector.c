#include "vector.h"
#include <stdlib.h>

// PRIVATE
void free_data(vector *v) {
  if (v->data) free(v->data);
}

// PUBLIC

vector *make_v(size_t block_size)
{
  vector *v = (vector *)malloc(sizeof(vector));
  v->count = 0;
  v->block_size = block_size;
  v->data = NULL;
  return v;
}

void *get_v(vector *v, size_t idx) {
  if (v->count <= 0) return &v->data;
  size_t num = idx > (v->count - 1) ? v->count - 1 : idx;
  return &v->data[num * v->block_size];
}

void push_v(vector *v, void *data) {
  v->count++;
  v->data = (char *)realloc(v->data, v->count * v->block_size);
  memcpy(&v->data[(v->count - 1) * v->block_size], data, v->block_size);
}

void set_v(vector *v, size_t idx, void *data) {
  size_t num = (idx > v->count) ? v->count - 1 : idx;
  memcpy(&v->data[num * v->block_size], data, v->block_size);
}

void delete_v(vector *v, size_t idx) {
  if (idx > v->count - 1) idx = v->count - 1;
  for (int i = idx; i < v->count - 1; i++) {
    set_v(v, i, get_v(v, i+1));
  }
  v->count--;
  v->data = (char*)realloc(v->data, v->count * v->block_size);
}

void clear_v(vector *v) {
  v->count = 0;
  free_data(v);
}

void free_v(vector *v) {
  if (v) {
    free_data(v);
    free(v);
  }
}
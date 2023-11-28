#include <stdio.h>

#include "vector.h"

void print_v(vector *v)
{
  for (size_t i = 0; i < v->count; i++)
    printf("[%zu]:%d ", i, *(int *)get_v(v, i));
  printf("\n");
}


int main() {

  printf("Create empty vector\n");
  vector *v = make_v(sizeof (int));

  printf("Filling the array with 21 elements\n");
  for (int i = 0; i <= 20; i++)
  {
    push_v(v, &i);
  }
  printf("length: %zu\n", v->count);
  print_v(v);

  printf("\nchanging the value of the 3rd element to 7\n");
  int change = 7;
  set_v(v, 3, &change);
  printf("3d el: %d\n", *(int*)get_v(v, 3));
  print_v(v);

  printf("\nDelete el: 0\n");
  printf("length before delete: %zu\n", v->count);
  delete_v(v, 0);
  printf("length after delete: %zu\n", v->count);
  print_v(v);

  printf("\nClear\n");
  clear_v(v);
  printf("length: %zu\n", v->count);

  printf("\nAdd 1 elem\n");
  push_v(v, &change);
  print_v(v);

  free_v(v);
  return 0;
}

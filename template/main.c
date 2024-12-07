#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 100

struct SizedArray {
  size_t size;
  int values[ARR_SIZE];
};

void swap(struct SizedArray *arr, size_t i, size_t j) {
  int tmp = arr->values[j];
  arr->values[j] = arr->values[i];
  arr->values[i] = tmp;
}

int contains(struct SizedArray *arr, int el) {
  for (size_t i = 0; i < arr->size; i++) {
    if (arr->values[i] == el) {
      return 1;
    }
  }

  return 0;
}

int append(struct SizedArray *arr, int el) {
  arr->values[arr->size] = el;
  arr->size++;

  return 1;
}

int append_uniq(struct SizedArray *arr, int el) {
  if (contains(arr, el)) {
    return 0;
  }

  arr->values[arr->size] = el;
  arr->size++;

  return 1;
}

int pop(struct SizedArray *arr) {
  arr->size--;
  return arr->values[arr->size];
}

void sized_array_print(char prefix[], struct SizedArray *arr) {
  printf("%s", prefix);

  for (size_t i = 0; i < arr->size; i++) {
    printf("%d ", arr->values[i]);
  }

  printf("\n");
}

int main(void) {
  int total = 0;
  char line[256];

  FILE *file = fopen("input", "r");
  if (file == NULL) {
    perror("No input file");
    return EXIT_FAILURE;
  }

  while (fgets(line, sizeof(line), file)) {
    printf("Line: %s", line);
  }

  pclose(file);

  printf("total: %d\n", total);
}

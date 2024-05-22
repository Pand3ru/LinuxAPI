#include <stdio.h>
#include <stdlib.h>

void HeapGrowth();
int *StackGrowth(int *prev, int d);

int main() {
  StackGrowth(NULL, 0);
  HeapGrowth();
  return -1;
}

void HeapGrowth() {
  int *a = malloc(25);
  int *b = malloc(25);

  if (a > b) {
    printf("Shrinks\n===\n\tAddr p1: %p\n\tAddr p2: %p\n", (void *)a,
           (void *)b);
  } else {
    printf("Grows\n===\n\tAddr p1: %p\n\tAddr p2: %p\n", (void *)a, (void *)b);
  }
  free(a);
  free(b);
}

int *StackGrowth(int *prev, int d) {
  int n;

  if (d > 0) {
    if (prev > &n) {
      printf("Shrinks\n===\n\tAddr p1: %p\n\tAddr p2: %p\n", (void *)prev,
             (void *)&n);
    } else {
      printf("Grows\n===\n\tAddr p1: %p\n\tAddr p2: %p\n", (void *)prev,
             (void *)&n);
    }
  }

  if (d < 1) {
    StackGrowth(&n, d + 1);
  }
  return &n;
}

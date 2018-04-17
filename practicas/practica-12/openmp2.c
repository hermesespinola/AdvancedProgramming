#include <stdio.h>
#include <omp.h>

#define SIZE 20000
// export OMP_NUM_THREADS=400

int main(int argc, char const *argv[]) {
  int a[SIZE];
  int b[SIZE];
  int c[SIZE];
  int chunk = 100;
  int j;

  for (size_t i = 0; i < SIZE; i++) {
    a[i] = i;
    b[i] = 2 * i;
  }

  #pragma omp parallel shared(a, b, c, chunk) {
    #pragma omp for schedule(dynamic, chunk) nowait
    for (j = 0; j < SIZE; j++) {
      c[j] = a[j] + b[j];
    }
  }
  return 0;
}

#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 20

void *helloThread(void *args) {
  long id = (long) args;
  printf("Hello world %ld\n", id);
  return NULL;
}

int main(int argc, char const *argv[]) {
  pthread_t threads[MAX_THREADS];
  for (size_t i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, helloThread, (void *) i);
  }
  for (size_t i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}

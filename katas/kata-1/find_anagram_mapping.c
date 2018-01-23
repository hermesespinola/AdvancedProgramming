#include <stdio.h>
#include <stdlib.h>

int* anagramMappings(int* A, int ASize, int* B, int BSize, int* returnSize) {
  if (ASize != BSize) {
    printf("ASize and BSize should be the same number\n");
    return NULL;
  }
  int * result =(int*) malloc(sizeof(int) * ASize);
  for (int i = 0; i< ASize; i++) {
    for (int j = 0;j < BSize; j++) {
      if(A[i] == B[j]) {
        result[i]=j;
      }
    }
  }
  *returnSize = ASize;
  return result;
}


int main(void) {
    int A[5] = {12, 28, 46, 32, 50};
    int B[5] = {50, 12, 32, 46, 28};
    int *size;
    int *result = anagramMappings(A, 5, B, 5, size);
    for(int i = 0; i < 3; i++) {
        printf("%d \n",result[i]);
    }
}

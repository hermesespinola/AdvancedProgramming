#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int *) malloc(sizeof(int) * 2);
    int x, y;

    for (int i = 0; i < numsSize; i++) {
    	x = nums[i];
    	for (int j= i + 1; j < numsSize; j++) {
    		y = nums[j];

    		if (x + y == target) {
    			result[0] = i;
    			result[1] = j;
          printf("%i + %i = %i\n", x, y, target);
    			return result;
    		}
    	}
    }
    return result;
}

int main(int argc, char const *argv[]) {
  int nums[] = { 2, 7, 11, 15 };
  int target = 9;
  twoSum(nums, 4, target);
  return 0;
}

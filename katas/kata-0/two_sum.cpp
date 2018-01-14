#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> set(nums.begin(), nums.end());
        std::set<int>::iterator found;
        int currentPos;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            currentPos = it - nums.begin();
            cout << "found: " << *it << " + " << target - *it << " = " << target;
            ptrdiff_t pos = find(nums.begin(), nums.end(), target - *it) - nums.begin();
            if (pos < nums.size() && currentPos != pos) {
                return vector<int>(currentPos, pos);
            }
        }
        return vector<int>();
    }
};

int main(int argc, char const *argv[]) {
  int _nums[] = { 2, 7, 11, 15 };
  vector<int> nums(_nums, _nums + sizeof(_nums) / sizeof(int));
  int target = 9;
  Solution().twoSum(nums, target);
  return 0;
}

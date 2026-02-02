#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = i+1; j < (int)nums.size(); ++j) {
            int x = nums[i];
            int y = target - x;

            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
        return {};
    }
};

int main() {
    int n;
    cin >> n;                 

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cin >> target;

    vector<int> ret = Solution().twoSum(arr, target);

    if (!ret.empty()) {
        cout << "[" << ret[0] << "," << ret[1] << "]\n";
    } else {
        cout << "No solution\n";
    }
    return 0;
}
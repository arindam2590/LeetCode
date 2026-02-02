#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                return {i, hash[complement]};
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
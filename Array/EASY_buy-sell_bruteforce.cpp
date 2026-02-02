// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int maxProfit = 0;

        for (int i = 0; i < (int)prices.size(); ++i) {
            int buyPrice = prices[i];

            for (int j = i + 1; j < (int)prices.size(); ++j) {
                int profit = prices[j] - buyPrice;
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ret = Solution().maxProfit(arr);
    
    cout << "Maximum Profit: " << ret<< "\n";
    
    return 0;
}
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxProfit(const vector<int>& prices) {
        if (prices.size() < 2) return {};     // no trade possible

        vector<int> buy_sell_price;           // keep empty unless profit found
        int maxProfit = 0;

        for (int i = 0; i < (int)prices.size(); ++i) {
            int buyPrice = prices[i];

            for (int j = i + 1; j < (int)prices.size(); ++j) {
                int profit = prices[j] - buyPrice;
                if (profit > maxProfit) {
                    maxProfit = profit;
                    buy_sell_price = {buyPrice, prices[j]};
                }
            }
        }
        return buy_sell_price;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ret = Solution().maxProfit(arr);
    
    if (!ret.empty()) {
        cout << "[" << ret[0] << "," << ret[1] << "]\n";
    } else {
        cout << "No solution\n";
    }
    
    return 0;
}

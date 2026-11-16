
#include <stdio.h>

// Function to calculate maximum profit
int maxProfit(int* prices, int pricesSize) {

    if (pricesSize < 2)
        return 0;

    int minPrice = prices[0];
    int maxProfitValue = 0;

    for (int i = 1; i < pricesSize; i++) {

        // Update minimum buying price
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Calculate profit if sold today
        int profit = prices[i] - minPrice;

        // Update maximum profit
        if (profit > maxProfitValue) {
            maxProfitValue = profit;
        }
    }

    return maxProfitValue;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, pricesSize);

    printf("Maximum Profit: %d\n", result);

    return 0;
}

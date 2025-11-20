#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][1001];

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] <= W)
        dp[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
                       knapsack(W, wt, val, n - 1));
    else
        dp[n][W] = knapsack(W, wt, val, n - 1);

    return dp[n][W];
}

int main() {
    int val[] = {20, 25, 60};
    int wt[] = {2, 4, 8};
    int W = 12;

    int n = sizeof(val) / sizeof(val[0]);

    memset(dp, -1, sizeof(dp));

    cout << "Maximum Profit: " << knapsack(W, wt, val, n) << endl;

    return 0;
}

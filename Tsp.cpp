#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int cost[10][10];
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<int> cities;
    for (int i = 1; i < n; i++)  // start city is fixed as 0
        cities.push_back(i);

    int minCost = INT_MAX;
    vector<int> bestPath;

    do {
        int currentCost = 0;
        int k = 0;  // start from city 0

        for (int i = 0; i < cities.size(); i++) {
            currentCost += cost[k][cities[i]];
            k = cities[i];
        }

        currentCost += cost[k][0];  // return to start

        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    cout << "\nMinimum travel cost: " << minCost << endl;
    cout << "Path: 0 -> ";
    for (int city : bestPath)
        cout << city << " -> ";
    cout << "0\n";

    return 0;
}

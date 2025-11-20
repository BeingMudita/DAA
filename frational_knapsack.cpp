#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

// Comparison function for sorting by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;  // sort in descending order
}

double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items by value/weight ratio
    sort(arr, arr + n, cmp);

    double finalValue = 0.0;  // result

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            // take whole item
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            // take fraction of item
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break;  // knapsack is full
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    Item arr[100];
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].weight >> arr[i].value;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, arr, n);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}

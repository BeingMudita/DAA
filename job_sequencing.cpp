#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit if job is done before or on deadline
};

// Comparison: sort jobs by descending profit
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[100];
    cout << "Enter job id, deadline, profit for each job:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Sort jobs by profit
    sort(jobs, jobs + n, cmp);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Time slots (initialized as free: -1 means empty)
    vector<int> slot(maxDeadline + 1, -1);

    int totalProfit = 0;
    int countJobs = 0;

    // Assign jobs to slots greedily
    for (int i = 0; i < n; i++) {
        // find a free slot for this job (starting from its deadline)
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }

    cout << "\nSelected jobs (by ID): ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1) cout << slot[i] << " ";
    }
    cout << "\nTotal jobs done = " << countJobs;
    cout << "\nTotal profit = " << totalProfit << endl;

    return 0;
}

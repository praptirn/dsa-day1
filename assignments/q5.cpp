/*
5. The "Optimal Resource Allocation" (Bitmask DP)

Problem:
Assign N workers to N tasks such that total cost is minimum.

Complexity:
O(2^N * N^2) using state compression (Bitmask DP)
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int assignTasks(vector<vector<int>>& cost) {
    int n = cost.size();
    int N = 1 << n;

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    for(int mask = 0; mask < N; mask++) {

        int task = __builtin_popcount(mask);

        if(task >= n) continue;

        for(int w = 0; w < n; w++) {
            if(!(mask & (1 << w))) {

                int newMask = mask | (1 << w);

                dp[newMask] = min(
                    dp[newMask],
                    dp[mask] + cost[w][task]
                );
            }
        }
    }

    return dp[N - 1];
}

int main() {
    int n;

    cout << "Enter number of workers/tasks (N < 20): ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix (" << n << " x " << n << "):\n";
    cout << "(Rows = workers, Columns = tasks)\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int result = assignTasks(cost);

    cout << "\nMinimum total cost = " << result << endl;

    return 0;
}
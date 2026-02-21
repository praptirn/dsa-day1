/*5. The "Optimal Resource Allocation" (Bitmask DP)
○ Problem: You have N tasks and N workers (where N < 20). Each worker has a specific
cost for each task. Assign exactly one worker to each task such that the total cost is
minimized.
○ Complexity Requirement: Improve upon the O(N!) brute force to O(2^N . N^2) using
state compression.

Solution:
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int assignTasks(vector<vector<int>>& cost) {
    int n = cost.size();
    int N = 1<<n;

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    for(int mask=0; mask<N; mask++) {
        int task = __builtin_popcount(mask);

        if(task >= n) continue;

        for(int w=0; w<n; w++) {
            if(!(mask & (1<<w))) {
                int newMask = mask | (1<<w);
                dp[newMask] = min(dp[newMask],
                                  dp[mask] + cost[w][task]);
            }
        }
    }
    return dp[N-1];
}

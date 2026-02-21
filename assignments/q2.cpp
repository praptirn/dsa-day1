/* 
2. The "Streaming Max" Analytics (Deques/Monotonic Queue)

Problem:
Given a stream of server latency data and a window size K,
calculate the maximum latency in every window.

Complexity:
Each element is processed in amortized O(1) time.
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;   // stores indices
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) {

        // Remove indices خارج the window
        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements from back
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Window formed
        if(i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter window size (k): ";
    cin >> k;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "\nMaximum in each sliding window:\n";
    for(int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}
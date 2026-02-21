/* 
4. The "Range Performance Monitor" (Segment Trees)
Problem:
Support two operations:
1) update(index, value)
2) queryMax(L, R)
Complexity:
Both operations run in O(log N)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int l, int r) {
        if(l == r) {
            tree[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if(idx <= mid)
            update(2*node, l, mid, idx, val);
        else
            update(2*node+1, mid+1, r, idx, val);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(qr < l || ql > r)
            return INT_MIN;

        if(ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(2*node, l, mid, ql, qr),
            query(2*node+1, mid+1, r, ql, qr)
        );
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n-1);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }

    int queryMax(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(arr);

    int choice;

    while(true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Update value\n";
        cout << "2. Query Max in range\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            int idx, val;
            cout << "Enter index and new value: ";
            cin >> idx >> val;
            st.update(idx, val);
            cout << "Updated successfully.\n";
        }
        else if(choice == 2) {
            int l, r;
            cout << "Enter range (L R): ";
            cin >> l >> r;
            cout << "Maximum value = " << st.queryMax(l, r) << endl;
        }
        else if(choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
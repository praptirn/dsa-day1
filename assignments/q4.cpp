/*4. The "Range Performance Monitor" (Segment Trees)
○ Problem: Design a system for a stock exchange that handles two operations:
update(index, value) for a stock price and queryMax(L, R) to find the highest price in
a time range.
○ Complexity Requirement: Both operations must be O(\log N).

Solution:
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr,int node,int l,int r){
        if(l==r){
            tree[node]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(arr,2*node,l,mid);
        build(arr,2*node+1,mid+1,r);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }

    void update(int node,int l,int r,int idx,int val){
        if(l==r){
            tree[node]=val;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid) update(2*node,l,mid,idx,val);
        else update(2*node+1,mid+1,r,idx,val);

        tree[node]=max(tree[2*node],tree[2*node+1]);
    }

    int query(int node,int l,int r,int ql,int qr){
        if(qr<l || ql>r) return INT_MIN;
        if(ql<=l && r<=qr) return tree[node];

        int mid=(l+r)/2;
        return max(query(2*node,l,mid,ql,qr),
                   query(2*node+1,mid+1,r,ql,qr));
    }

public:
    SegmentTree(vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        build(arr,1,0,n-1);
    }

    void update(int idx,int val){
        update(1,0,n-1,idx,val);
    }

    int queryMax(int l,int r){
        return query(1,0,n-1,l,r);
    }
};

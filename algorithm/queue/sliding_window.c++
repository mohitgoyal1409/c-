#include<iostream>
#include<queue>
using namespace std;
#include<vector>

vector<int> slidingWindowMaximum(vector<int>& arr,int k=3) {
    vector<int> ans;
    deque<int> dq;
    
    for(int i = 0;i<k;i++) {
        while(dq.size() > 0 && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i = k; i<arr.size();i++) {
        ans.push_back(arr[dq.front()]);
        // remove not part of curr window
        while(dq.size() > 0 && dq.front() <= i-k) {
            dq.pop_front();
        }
    //    remove smaller elements from back
        while(dq.size() > 0 && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    return ans;
}

int main() {
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = slidingWindowMaximum(arr,3);
    for(int i = 0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}
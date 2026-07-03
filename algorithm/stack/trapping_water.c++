#include<iostream>
#include<vector>
using namespace std;

int trappingWater(vector<int>& height) {
     vector<int> lmax(height.size(),0);
    vector<int> rmax(height.size(),0);
    
    lmax[0] = height[0];
    rmax[height.size()-1] = height[height.size()-1];
    for(int i = 1; i<height.size();i++) {
        lmax[i] = max(lmax[i-1],height[i]);
    }
    for(int i = height.size()-2; i>=0;i--) {
        rmax[i] = max(rmax[i+1],height[i]);
    }

    int ans = 0;
    for(int i = 0; i<height.size();i++) {
        ans += min(lmax[i],rmax[i]) - height[i];
    }
    return ans;
}


int main() {
    vector<int> height = {4,2,0,3,2,5};
    cout<<trappingWater(height)<<endl; // return 9
}
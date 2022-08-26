#include<bits/stdc++.h>
using namespace std;

// longest bitonic subsequence
int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp1(n,1), dp2(n,1);

    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(nums[i] > nums[j] and dp1[i] < dp1[j] + 1) {
                dp1[i] = dp1[j] + 1;
            }
        }
    }   
   
    for(int i = n-2; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] > nums[j] and dp2[i] < dp2[j] + 1) {
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i < n; i++) {
        if(dp1[i] != 1 and dp2[i] != 1) {
            ans =  max(ans, dp1[i] + dp2[i] - 1);
        }
    }
    return n - ans;
}


int main() {
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout << minimumMountainRemovals(nums) << endl;
}


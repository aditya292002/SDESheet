#include<bits/stdc++.h>
using namespace std;


// Minimum Number of Removals to Make Mountain Array
// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/


int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp1(n,1), dp2(n,1);


    // dp1[i] --> will store the longest increasing subsequence till the length i , similarly

    // dp2[i] --> will store the longest decreasing subsequence till the length i

    // max length of bitonic subsequence = dp1[i] + dp2[i] - 1  (bcz the element at index i is considered twice hence -1)


    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(nums[j] < nums[i] and  dp1[i] < dp1[j] + 1) {
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    int maxi = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] > nums[j] and dp2[i] < dp2[j] + 1) {
                dp2[i] = dp2[j] + 1;
            }
        }

        if(dp1[i] != 1 && dp2[i] != 1)   // bcz the mountain array can't be just decreasing or just increasing
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }


    // int maxi = 0;
    // for(int i = 0; i < n; i++) {
    //     if(dp1[i] != 1 && dp2[i] != 1)   // bcz the mountain array can't be just decreasing or just increasing
    //         maxi = max(maxi, dp1[i] + dp2[i] - 1);
    // }

    return n - maxi;
}



int main() {
    vector<int> nums = {9,8,1,7,6,5,4,3,2,1};
    // vi nums = {2,1,1,5,6,2,3,1};
    cout<<minimumMountainRemovals(nums)<<endl;
}


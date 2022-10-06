#include<bits/stdc++.h>
using namespace std;


// Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1);

    int maxi = 1;
    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(nums[i] > nums[j]){
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if(dp[i] == dp[j] + 1) {       
                    cnt[i] += cnt[j];
                }
            }
        }
        maxi = max(maxi, dp[i]);
    }   

    int noOfLIS = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] == maxi) {
            noOfLIS += cnt[i];
        }
    }
    return noOfLIS;
}

int main() {
    vector<int> nums = {2,2,2,2,2};
    cout<<findNumberOfLIS(nums)<<endl;
}


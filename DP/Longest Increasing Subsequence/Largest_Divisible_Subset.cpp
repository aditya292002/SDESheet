#include<bits/stdc++.h>
using namespace std;

// Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    vector<int> hash(n,-1);
    int last = 0;
    int maxi = 1;
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }

            if(dp[i] >= maxi) {
                maxi = dp[i];
                last = i;
            }
        }
    }

    vector<int> ans(maxi);
    int i = last;
    int ind = maxi - 1;

    while(i != -1) {
        ans[ind] = nums[i];
        ind--;
        i = hash[i];
    }
    return ans;
}



int main() {
    vector<int> nums = {3,17};


    vector<int> ans = largestDivisibleSubset(nums);

    // print ans
}


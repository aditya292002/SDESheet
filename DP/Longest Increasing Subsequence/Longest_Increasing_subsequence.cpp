#include<bits/stdc++.h>
using namespace std;


int lengthOfLISUtil(vector<int>& nums, int i, int prevI, vector<vector<int>> &dp) {

    if(i == nums.size()) return 0;

    if(dp[i][prevI + 1] != -1) return dp[i][prevI + 1];    // we can't store dp[x][-1] so we did -> dp[x][-1 + 1]  
                                                                /*****   Coordinate Shifting  *****/

    int take = 0;
    int notTake = lengthOfLISUtil(nums, i + 1, prevI, dp);

    if(prevI == -1 || nums[prevI] < nums[i]) {
        take = 1 + lengthOfLISUtil(nums, i + 1, i, dp);
    }

    return dp[i][prevI + 1] = max(take, notTake);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1,-1));
    return lengthOfLISUtil(nums, 0, -1, dp);    
}


// tabulation
int lengthOfLIS_Tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    
    for(int i = n-1; i >= 0; i--) {
        for(int prevI = -1; prevI < i ; prevI++) {
            int take = 0;
            int notTake = dp[i+1][prevI + 1];  

            if(prevI == -1 || nums[prevI] < nums[i]) {
                take = 1 + dp[i+1][i + 1];
            }

            dp[i][prevI+1] = max(take, notTake);
        }
    }

    return dp[0][-1 + 1];
}   


// space optimization

int lengthOfLIS_Tabulation_SO(vector<int>& nums) {
    int n = nums.size();
    // vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    
    vector<int> later(n+1,0);
    vector<int> curr(n+1,0);

    for(int i = n-1; i >= 0; i--) {
        for(int prevI = -1; prevI < i ; prevI++) {
            int take = 0;
            int notTake = later[prevI + 1];  

            if(prevI == -1 || nums[prevI] < nums[i]) {
                take = 1 + later[i + 1];
            }

            curr[prevI+1] = max(take, notTake);
        }
        later = curr;
    }

    return curr[-1 + 1];
} 


//--------------------------------------------------------------------------------------------------------------------
// another approach
// TC - O(N^2)   SC - O(N)

// this approah will help to (trace back LIS and print it)

int lengthOfLIS_(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    vector<int> hash(n,-1);
    // for(int i = 0; i <)

    int maxi = 1;
    int last; // to get the last index of increasing subsequence
    for(int i = 0; i < n; i++) {
        for(int j = i-1; j >= 0 ; j--) {
            if(nums[i] > nums[j] and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                maxi = max(maxi,dp[i]);
                last = i;

                hash[i] = j;
            }
        }
    }

    int i = last;
    vector<int> ans;
    while(i != -1) {
        ans.push_back(nums[i]);
        i = hash[i];
    }

    reverse(ans.begin(),ans.end());
    // print the ans 

    return maxi;
}

//--------------------------------------------------------------------------------------------------------------------

// approach 3  -- Binary Search 
// TC - O(N)
int lengthOfLIS__(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i = 1; i < n; i++) {
        if(nums[i] > temp.back()) {
            temp.push_back(nums[i]);
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();   // lower-bound --> less than equal to 
            temp[ind] = nums[i];
        }
    }

    return temp.size();
}




int main() {
    vector<int> nums = {5,4,11,1,16,18};  
    cout<<lengthOfLIS_(nums)<<endl;
}


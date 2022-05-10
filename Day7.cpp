#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(vector<vector<vector<T>>> vec){
for(auto iii : vec){
    cout<<"["<<endl;
    for(auto ii : iii){
        for(auto i : ii){
            cout<<i<<" ";
        }cout<<endl;
    }
    cout<<"]"<<endl;
}
}
void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}
int convert_string_int(string s){
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}

int mod =(int)1e9+7;

/*      
{
    TC = O(n)
    SC = O(n)
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------


// Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/




int f1(vector<int> arr){
    int n = arr.size();
    vi dp(n,1);
    int maxi = INT_MIN;
    for(int i = 0; i < n;i++){
        for(int j = 0; j <=i; j++){
            dp[j] = dp[j]*arr[i];
            // cout<<dp[j]<<" ";
            maxi = max(maxi,dp[j]);
        }
    }
    return maxi;
}


// int maxProductUtil(vect
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxi = nums[0];
    int mini = nums[0];
    int ans = nums[0];
    for(int i = 1; i < n;i++){
        if(nums[i] < 0){
            swap(maxi,mini);
        }
        maxi = max(nums[i],maxi*nums[i]);
        mini = min(nums[i],mini*nums[i]);
        ans = max(ans,maxi);
    } 
    return ans;
}       
//https://www.youtube.com/watch?v=tHNsZHXnYd4


//-------------------------------------------------------------------------------------------------------------------------

//Ones and Zeroes
// https://leetcode.com/problems/ones-and-zeroes/
// https://leetcode.com/submissions/detail/696644834/
int f(int ind,int m, int n, vector<pair<int,int>> &lenStr){
    if(ind == lenStr.size()-1){
        if(n-lenStr[ind].ss == 0 and m-lenStr[ind].ff >= 0){return 1;}
        else{return 0;}
    }
    
    
    int notpick = f(ind+1,m,n,lenStr);
    int pick = 0;
    if(n-lenStr[ind].ss >= 0 and m-lenStr[ind].ff >= 0){
        pick = 1 + f(ind + 1,m-lenStr[ind].ff,n-lenStr[ind].ss,lenStr);
    }
    
    return max(pick,notpick);
}

//
int f1(int ind,int m, int n, vector<pair<int,int>> &lenStr, vvvi &dp){
    //Both are the correcy base case

    //Base Case - 1 
    // if(ind == lenStr.size()-1){
    //     if(n-lenStr[ind].ss >= 0 and m-lenStr[ind].ff >= 0){
    //         return 1;}
    //     else{return 0;}
    // }

    //Base Case - 2 
    if(ind == lenStr.size() || m + n == 0){return 0;}
    

    if(dp[ind][m][n] != -1) return dp[ind][m][n];
    
    int notpick = f1(ind+1,m,n,lenStr,dp);
    int pick = 0;
    if(n-lenStr[ind].ss >= 0 and m-lenStr[ind].ff >= 0){
        pick = 1 + f1(ind + 1,m-lenStr[ind].ff,n-lenStr[ind].ss,lenStr,dp);
    }
    
    return dp[ind][m][n] = max(pick,notpick);
}

//this can be space optimized
int fT(vector<pair<int,int>> lenStr, int m,int n){
    int length = lenStr.size();

    //declare the same dp size array
    vvvi dp(length,vvi(m+1,vi(n+1,0)));

    //write the base case
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(j-lenStr[length-1].ss >= 0 and i - lenStr[length-1].ff >= 0){
                dp[length-1][i][j] = 1;
            }
        }
    }

    //copy the recurrance
    //indexing in opposite fashion
    for(int ind = length-2 ; ind>= 0; ind--){
        for(int m_ind = 0; m_ind <= m; m_ind++){
            for(int n_ind = 0; n_ind <= n; n_ind++){
                int notpick = dp[ind+1][m_ind][n_ind];
                int pick = 0;
                if(n_ind-lenStr[ind].ss >= 0 and m_ind-lenStr[ind].ff >= 0){
                    pick = 1 + dp[ind + 1][m_ind-lenStr[ind].ff][n_ind-lenStr[ind].ss];
                }
                dp[ind][m_ind][n_ind] = max(pick,notpick);
            }
        }
    }
    return dp[0][m][n];
}   
int findMaxForm(vector<string>& strs, int m, int n) {
    int length = strs.size();
    vector<pair<int,int>> lenStr;
    for(auto s : strs){
        int len = s.size();
        int cnt_0 = 0, cnt_1 = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == '1') cnt_1++;
            else cnt_0++;
        }
        lenStr.pb({cnt_0,cnt_1});
    }
    // vvvi dp(length,vvi(m+1,vi(n+1,-1)));   //we will pass m and n in the function so obviously m+1 and n+1 size array
                                                                                            //will be needed
    // return f1(0,m,n,lenStr,dp);
    // return f(0,m,n,lenStr);

    return fT(lenStr,m,n);
}

//-------------------------------------------------------------------------------------------------------------------------------------

//frog jump
int frogJump(int ind, vector<int> &heights, vi &dp){
    if(ind == heights.size()-1)return 0;

    if(dp[ind] != -1)return dp[ind];
    int oneJump = abs(heights[ind] - heights[ind+1]) + frogJump(ind+1,heights,dp);
    int twoJump = INT_MAX;
    if(ind+2 < heights.size()){
        twoJump = abs(heights[ind] - heights[ind+2]) + frogJump(ind+2,heights,dp);
    }
    return dp[ind] = min(oneJump,twoJump);
}

//works find
int frogJump_K(int ind, vector<int> &heights, int k){
    if(ind == heights.size()-1)return 0;

    int mini = INT_MAX;
    for(int i = 1; i <= k; i++){
        int cost = INT_MAX;
        if(ind + i < heights.size()){
            cost = abs(heights[ind] - heights[ind + i]) + frogJump_K(ind + i, heights, k);
        }
        mini = min(mini,cost);
    }
    return mini;
}
//testcase
// cout<<frogJump_K(0,arr,3)<<endl;
    // vi arr = {10 ,20 ,30 ,20};

//--------------------------------------------------------------------------------------------------------------------------------------


//maximum sum of non adjacent elements
int houseRobberUtil(int ind, vi &arr, vi &dp){
    if(arr.size() == 0){return 0;}
    if(ind == arr.size()-1)return arr[ind];
    //pick and not pick
    if(dp[ind] != -1){return dp[ind];}
    int notPick = houseRobberUtil(ind+1,arr,dp);
    int pick = arr[ind];
    if(ind + 2 < arr.size()){
        pick = houseRobberUtil(ind+2,arr,dp) + arr[ind];
    }
    return dp[ind] =   max(notPick,pick);
}   

//tabulation
int houseRobberUtil_T(vi &arr){
    int n = arr.size();
    vi dp(n,0);
    if(n == 0){return 0;}
    dp[n-1] = arr[n-1];
    for(int ind = n-2; ind >= 0; ind--){
        int notPick = dp[ind+1];
        int pick = arr[ind];
        if(ind + 2 < n){
            pick = dp[ind+2] + arr[ind];
        }
        dp[ind] = max(pick,notPick); 
    }

    return dp[0];
}

//House robber II 
int rob(vector<int>& nums) {
    int n = nums.size();
    vi nums1,nums2;
    for(int i = 0 ;i < n; i++){
        if(i != n - 1){
            nums1.push_back(nums[i]);
        }
        if(i != 0){
            nums2.push_back(nums[i]);
        }
    }
    if(n == 1){
        nums1.pb(nums[0]);
    }
    vi dp1(n-1,-1);
    vi dp2(n-1,-1);

    // int ans1 = houseRobberUtil(0,nums1,dp1);
    int ans1 = houseRobberUtil_T(nums1);

    // int ans2 = houseRobberUtil(0,nums2,dp2);
    int ans2 = houseRobberUtil_T(nums2);


    return max(ans1,ans2);
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Ninja’s Training
// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

int ninjaTraining1(int ind, vector<vector<int>> &points, int prev, vvi &dp){

    if(dp[ind][prev] != -1)return dp[ind][prev];

    if(ind == points.size() - 1){
        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++){
            if(i != prev){
                maxi = max(maxi,points[ind][i]);
            }
        }
        return dp[ind][prev] = maxi;
    }


    int maxi = INT_MIN;
    for(int i = 0; i < 3; i++){
        if(i != prev){
            maxi = max(maxi,points[ind][i] + ninjaTraining1(ind+1,points,i,dp));
        }
    }
    return dp[ind][prev] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vvi dp(n,vi(4,-1));
    return ninjaTraining1(0,points,3,dp);
}
/*
    vvi dp(n,vi(4,-1));
    return ninjaTraining1(0,points,3,dp);
*/

//-------------------------------------------------------------------------------------------------------------------------------

int main(){
    vi arr = {1,2,3,1};
    // vi arr = {0};
    int n = arr.size();
    // cout<<frogJump(0,arr)<<endl;
    vi dp(n,-1);
    // cout<<houseRobberUtil(0,arr,dp)<<endl;
    cout<<rob(arr);
    // cout<<houseRobberUtil_T(arr)<<endl;
}









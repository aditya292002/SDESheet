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
// https://leetcode.com/problems/burst-balloons/submissions/
//Burst Balloons
int maxCoinsUtil(int i, int j, vi &nums,vvi &dp){
    if(i > j)return 0;
    
    if(dp[i][j] != -1){return dp[i][j];}
    int maxi = INT_MIN; 
    for(int ind = i; ind <= j; ind++){
        int coins =  nums[i-1]*nums[ind]*nums[j+1] + maxCoinsUtil(i,ind-1,nums,dp) + maxCoinsUtil(ind+1,j,nums,dp);
        maxi = max(maxi,coins);
    }
    return  dp[i][j] = maxi;
}


//tabulation 
int maxCoinUtil_T(vi &nums){
    int n = nums.size();
    nums.pb(1);
    nums.insert(nums.begin(),1);
    vvi dp(n+2,vi(n+2,0)); //n+2 bcz, the ind+1 goes out of bounds when ind == n 
                                                // so dp of n+2 size is needed
                                            // or it can be vvi dp(n+2,vi(n+1,0)); 
                                            //also correct
    for(int i = n; i >= 1;i--){
        for(int j = 1; j <= n; j++){
            if(i > j) continue;
            int maxi = INT_MIN;
            for(int ind = i; ind <= j; ind++){
                int coins =  nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi,coins);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];        //bcz, return sol after busting the baloons from 1 to n.
}
int maxCoins(vector<int>& nums) {
    // int n = nums.size();
    // nums.pb(1);
    // nums.insert(nums.begin(),1);
    // int n = nums.size();
    // vvi dp(n-1,vi(n-1,-1));
    // return maxCoinsUtil(1,n-2,nums,dp);
    return maxCoinUtil_T(nums);
}

//-------------------------------------------------------------------------------------------------------------------------
//Evaluate Boolean Expression to True

//code studio link
//https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// int mod = 1000000007;
int evaluateTrue(int i,int j, int isTrue, string exp, vector<vector<vector<ll>>> &dp){
    if(i > j)return 0;
    if(i == j){
        if(isTrue){
            return (exp[i] == 'T');
        }
        else return exp[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1){return dp[i][j][isTrue];}
    
    ll ways = 0;
    for(int ind = i+1; ind <= j-1; ind = ind + 2){
        ll lt = evaluateTrue(i,ind-1,1,exp,dp);
        ll lf = evaluateTrue(i,ind-1,0,exp,dp);

        ll rt = evaluateTrue(ind+1,j,1,exp,dp);  
        ll rf = evaluateTrue(ind+1,j,0,exp,dp);  

        if(exp[ind] == '&'){
            if(isTrue){
                ways = (ways + (lt*rt)%mod)%mod;
            } 
            else{
                ways = (ways + (lf*rt)%mod + (lt*rf)%mod + (lf*rf)%mod)%mod;
            }
        }
        else if(exp[ind] == '|'){
            if(isTrue){
                ways = (ways+ ((lt*rt)%mod) + ((lt*rf)%mod) + (lf*rt)%mod)%mod;
            } 
            else{
                ways = (ways + (lf*rf)%mod)%mod;
            }
        }
        else{
            if(isTrue){
                ways = (ways + (lt*rf)%mod + (lf*rt)%mod)%mod;
            }
            else{
                ways = (ways + (lt*rt)%mod + (lf*rf)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & S) {
    int n = S.size();
    // vvvi dp(n,vvi(n,vi(2,-1)));
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return evaluateTrue(0,n-1,1,S,dp);
}

//-----------------------------------------------------------------------------------------------------------------------------

//https://leetcode.com/problems/palindrome-partitioning-ii/submissions/
//Palindrome Partitioning II

bool isPalindrome(int i, int j, string s){
    while(i <= j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int minCutUtil(int i, string s, vector<int> &dp){
    if(i == s.size()){
        return 0;
    }
    if(dp[i] != -1){return dp[i];}
    int mini = INT_MAX;
    for(int j = i; j < s.size(); j++){
        if(isPalindrome(i,j,s)){
           mini = min(mini, 1 +  minCutUtil(j+1,s,dp));
       }
   }
   return dp[i] = mini;
}

//tabulation
int minCutUtil_T(string s){
    int n = s.size();
    vector<int> dp(n+1,0);
    dp[n] = 0;


    for(int i = n-1; i >= 0; i--){
        int mini = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(i,j,s)){
               mini = min(mini, 1 + dp[j+1]);
           }
       }
       dp[i] = mini;
   }
   return dp[0] - 1;
}
int minCut(string s) {
        // vector<int> dp(s.size(),-1);
        // return minCutUtil(0,s,dp)-1;
    return minCutUtil_T(s);
}

//------------------------------------------------------------------------------------------------------------------------
//leetcoe link
//https://leetcode.com/problems/climbing-stairs/submissions/

int f(int n, vi &dp){
    if(n == 0){return 1;}
    if(n < 0){return 0;}
    if(dp[n] != -1)return dp[n];
    dp[n] = f(n-1,dp) + f(n-2,dp);
    return dp[n];
}  
int fT1(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        if(i - 2>=0){
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}
int climbStairs(int n) {
    vector<int> dp(n+1,-1);

    return f(n,dp);
}

//------------------------------------------------------------------------------------------------------------------------------



int main(){
    // string s = "T^F|F";
    // string s1 = "T^T^F";
    // string s2 = "F|T^F";
    // string s3 = "T&T";
    // string s4 = "T|F^T&F|F&T";
    // cout<<countWays(12,s)<<endl;
    // cout<<countWays(12,s1)<<endl;
    // cout<<countWays(12,s2)<<endl;
    // cout<<countWays(12,s4)<<endl;
    // cout<<climbStairs(35)<<endl;
    // cout<<fT(35)<<endl;
    cout<<climbStairs(35)<<endl;
}
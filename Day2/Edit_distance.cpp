#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

//Edit Distance
//available on leetcode

int editDistanceUtil(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    if(i < 0) return j+1;
    if(j < 0) return i+1;
    
    if(dp[i][j] != -1){return dp[i][j];}
    
    if(s1[i] == s2[j]){
        return dp[i][j] = editDistanceUtil(s1,s2,i-1,j-1,dp);
    }
    
    int insert_ = 1 + editDistanceUtil(s1,s2,i,j-1,dp);
    int delete_ = 1 + editDistanceUtil(s1,s2,i-1,j,dp);
    int replace_ = 1 + editDistanceUtil(s1,s2,i-1,j-1,dp);
    
    return dp[i][j] = min(insert_,min(delete_,replace_));
}

//shifting of index
int editDistanceUtil_1(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    if(i == 0) return j;
    if(j == 0) return i;
    
    if(dp[i][j] != -1){return dp[i][j];}
    
    if(s1[i-1] == s2[j-1]){
        return dp[i][j] = editDistanceUtil_1(s1,s2,i-1,j-1,dp);
    }
    
    int insert_ = 1 + editDistanceUtil_1(s1,s2,i,j-1,dp);
    int delete_ = 1 + editDistanceUtil_1(s1,s2,i-1,j,dp);
    int replace_ = 1 + editDistanceUtil_1(s1,s2,i-1,j-1,dp);
    
    return dp[i][j] = min(insert_,min(delete_,replace_));
}

//tabulation
int editDistanceUtil_T(string &s1, string &s2){
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    for(int i = 0; i <= n2; i++){
        dp[0][i] = i;
    }
    for(int i = 0; i <= n1; i++){
        dp[i][0] = i;
    }

    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            
            else{
                int insert_ = 1 + dp[i][j-1];
                int delete_ = 1 + dp[i-1][j];
                int replace_ = 1 + dp[i-1][j-1];
                
                dp[i][j] = min(insert_,min(delete_,replace_));
            }

        }
    }

    return dp[n1][n2];
}


//space optimization 
int editDistanceUtil_T1(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();

    vector<int> prev(n2+1,0), curr(n2+1,0);
    for(int i = 0; i <= n2; i++){
        prev[i] = i;
    }


    for(int i = 1; i <= n1; i++){
        curr[0] = i;
        for(int j = 1; j <= n2; j++){

            if(s1[i-1] == s2[j-1]){
                curr[j] = prev[j-1];
            }
            
            else{
                int insert_ = 1 + curr[j-1];
                int delete_ = 1 + prev[j];
                int replace_ = 1 + prev[j-1];
                
                curr[j] = min(insert_,min(delete_,replace_));  // this cannot be furthur optimized using 1D 
                                                                //bcz, cur[j] depends on cur[j-1] and not just prev array
            }

        }
        prev = curr;
    }

    return prev[n2];
}


int main(){
    
}
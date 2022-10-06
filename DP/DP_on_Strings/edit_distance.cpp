#include<bits/stdc++.h>
using namespace std;

// Edit Distance
// https://leetcode.com/problems/edit-distance/submissions/

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



// shifting of index
int editDistanceUtil_1(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    if(i == 0) return j;    
    if(j == 0) return i;
    // after shifting of index, it is sort of like 1 based indexing so, 
    /*
                                    0 1 2 3 4 . . 
                                    1 2 3 4 5 . .
                                    h o r s e . . 
    */

    // let's say s2 gets exhausted (j == 0) and i = 3 previously we had i == 2 so we returned i + 1 no we can return i

                                    // similarly for i == 0

    
    if(dp[i][j] != -1){return dp[i][j];}
    
    if(s1[i-1] == s2[j-1]){
        return dp[i][j] = editDistanceUtil_1(s1,s2,i-1,j-1,dp);
    }
    
    int insert_ = 1 + editDistanceUtil_1(s1,s2,i,j-1,dp);
    int delete_ = 1 + editDistanceUtil_1(s1,s2,i-1,j,dp);
    int replace_ = 1 + editDistanceUtil_1(s1,s2,i-1,j-1,dp);
    
    return dp[i][j] = min(insert_,min(delete_,replace_));
}





int minDistance(string str1, string str2) {
    int n1 = str1.size();
    int n2 = str2.size();
    
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    int ans = editDistanceUtil_1(str1,str2,n1,n2,dp);
    return ans;
}


// Tabulation
int minDistance_Tabulation(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            if(i == 0) { dp[i][j] = j; continue; }
            if(j == 0) { dp[i][j] = i; continue; }

            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                int insert_ = 1 + dp[i][j-1];
                int delete_ = 1 + dp[i-1][j];
                int replace_ = 1 + dp[i-1][j-1];

                dp[i][j] = min(insert_,min(delete_,replace_));
            }
        }
    }
    return dp[n1][n2];
}

// Space opt
int minDistance_Tabulation_SO(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    vector<int> prev(n2+1,-1), curr(n2+1,-1);

    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            if(i == 0) { curr[j] = j; continue; }
            if(j == 0) { curr[j] = i; continue; }

            if(s1[i-1] == s2[j-1]) {
                curr[j] = prev[j-1];
            }
            else {
                int insert_ = 1 + curr[j-1];
                int delete_ = 1 + prev[j];
                int replace_ = 1 + prev[j-1];

                curr[j] = min(insert_,min(delete_,replace_));
            }
        }
        prev = curr;
    }
    return curr[n2];
}





int main() {
    string s1 = "horse";
    string s2 = "ros";
    cout<<minDistance_Tabulation(s1, s2)<<endl;
}
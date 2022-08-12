#include<bits/stdc++.h>
using namespace std;

// Shortest Common Supersequence
// https://leetcode.com/problems/shortest-common-supersequence/

// https://leetcode.com/problems/shortest-common-supersequence/discuss/2405306/Top-Down-Solution-oror-Longest-Common-Subsequence  <<-- leetcode discuss link

string shortestCommonSupersequence(string s1, string s2) {
    int n1 = s1.size();    
    int n2 = s2.size();    

    // longest common subsequence dp

    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }



    // traversing the dp to get the supersequence
    int i = n1, j = n2;
    string ans = "";
    while(i > 0 and j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans = s1[i-1] + ans;
            i--; j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {

                ans = s1[i-1] + ans;
                i--;
            }
            else {
                ans = s2[j-1] + ans;
                j--;
            }
        }
    }


      while(i>0){
          ans = s1[i-1] + ans;
          i--;
      }
      while(j>0){
          ans = s2[j-1] + ans;
          j--;
      }


    return ans;
}
int main() {   
    string s1 = "aaaaaaaa";  // (brute, groot) 
    string s2 = "aaaaaaaa";   
    cout<<shortestCommonSupersequence(s1,s2)<<endl;
}
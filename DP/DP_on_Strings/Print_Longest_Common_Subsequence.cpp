#include<bits/stdc++.h>
using namespace std;


// Printing the Longest Common Subsequence

int longestCommonSubsequenceUtil(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp, string s, string &ans) {
    if(ind1 == -1 || ind2 == -1) {
        if(s.size() > ans.size()) 
            ans = s;
        return 0;
    }

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(text1[ind1] == text2[ind2]) {
        string temp = s;
        s += text1[ind1];
        return dp[ind1][ind2] =  1 + longestCommonSubsequenceUtil(text1, text2, ind1 - 1, ind2 - 1, dp,s, ans); // if same go find other 
        s = temp;
    }

        // if not same go both ways to explore each possibilities
    return dp[ind1][ind2] = max(    longestCommonSubsequenceUtil(text1, text2, ind1 - 1, ind2, dp,s, ans) , 

                    longestCommonSubsequenceUtil(text1, text2, ind1, ind2 - 1, dp,s, ans)  );
}



string longestCommonSubsequence(string text1, string text2) {
    
    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));

    string ans = "";

    longestCommonSubsequenceUtil(text1, text2, n1-1, n2-1, dp, "", ans);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string s1 = "abcde", s2 = "ace";
    cout<<longestCommonSubsequence(s1, s2)<<endl;
}
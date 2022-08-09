#include<bits/stdc++.h>
using namespace std;

// recursion + memoization

int longestCommonSubsequenceUtil(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp) {
    if(ind1 == -1 || ind2 == -1) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(text1[ind1] == text2[ind2]) 
        return dp[ind1][ind2] =  1 + longestCommonSubsequenceUtil(text1, text2, ind1 - 1, ind2 - 1, dp); // if same go find other 
        

        // if not same go both ways to explore each possibilities
    return dp[ind1][ind2] = max(    longestCommonSubsequenceUtil(text1, text2, ind1 - 1, ind2, dp) , 

                    longestCommonSubsequenceUtil(text1, text2, ind1, ind2 - 1, dp)  );
}


//-------------------------------------------------------------------------------------------------------------------

//*********** shifting of index (bcz, for tabulation)*******************************//


//base case ind1 = -1 and ind2 = -1 (negative index is not possible)

int longestCommonSubsequenceUtil1(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp) {
    if(ind1 == 0 || ind2 == 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(text1[ind1-1] == text2[ind2-1]) 
        return dp[ind1][ind2] =  1 + longestCommonSubsequenceUtil1(text1, text2, ind1 - 1, ind2 - 1, dp);  
        
        
    return dp[ind1][ind2] = max(    longestCommonSubsequenceUtil1(text1, text2, ind1 - 1, ind2, dp) , 

                    longestCommonSubsequenceUtil1(text1, text2, ind1, ind2 - 1, dp)  );
}





int longestCommonSubsequence(string text1, string text2) {
    
    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));

    // return longestCommonSubsequenceUtil1(text1, text2, n1-1, n2-1, dp); longestCommonSubsequenceUtil(n1-1, n2-1)
    return longestCommonSubsequenceUtil1(text1, text2, n1, n2, dp);
}

//-----------------------------------------------------------------------------------------------------------------------------

// tabulation
int longestCommonSubsequence_tabulation(string text1, string text2) {  

    int n1 = text1.size();
    int n2 = text2.size();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

    /*
    for(int i = 0; i < n1; i++) {
        dp[0][i] = 0;
    }
    for(int j = 0; j < n2; j++) {
        dp[j][0] = 0;
    }
    */

    for(int i1 = 1; i1 <= n1; i1++) {
        for(int i2 = 1; i2 <= n2; i2++) {
            if(text1[i1-1] == text2[i2-1]) 
                dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
            else 
                dp[i1][i2] = max(dp[i1-1][i2] , dp[i1][i2-1]);
        }
    }


    return dp[n1][n2];

}

//--------------------------------------------------------------------------------------------------------------------------

// space optimization 2D
int longestCommonSubsequence_tabulation_SO(string text1, string text2) {  

    int n1 = text1.size();
    int n2 = text2.size();

    vector<int> prev(n2+1, 0);
    vector<int> curr(n2+1, 0);

    for(int i1 = 1; i1 <= n1; i1++) {
        for(int i2 = 1; i2 <= n2; i2++) {
            if(text1[i1-1] == text2[i2-1]) 
                curr[i2] = 1 + prev[i2 - 1];
            else 
                curr[i2] = max(prev[i2] , curr[i2-1]);
        }
        prev = curr;
    }


    return curr[n2];

}


int main() {
    string s1 = "abcde", s2 = "ace";
    cout<<longestCommonSubsequence_tabulation_SO(s1, s2)<<endl;
}
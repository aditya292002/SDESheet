#include<bits/stdc++.h>
using namespace std;


int numDistinctUtil(string s, string t, int i, int j, vector<vector<int>> &dp) {
    if(j == -1) return 1;
    if(i == -1) return 0; 

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) {
        return dp[i][j] = numDistinctUtil(s,t,i-1, j-1, dp) + numDistinctUtil(s,t, i-1, j, dp);
    }

    return dp[i][j] = numDistinctUtil(s,t,i-1,j,dp);
}



// shifting of index
int numDistinctUtil_1(string s, string t, int i, int j, vector<vector<int>> &dp) {
    if(j == 0) return 1;
    if(i == 0) return 0; 

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i-1] == t[j-1]) {
        return dp[i][j] = numDistinctUtil_1(s,t,i-1, j-1, dp) + numDistinctUtil_1(s,t, i-1, j, dp);
    }

    return dp[i][j] = numDistinctUtil_1(s,t,i-1,j,dp);
}


int numDistinct(string s, string t) {
    int ns = s.size();
    int nt = t.size();
    vector<vector<int>> dp(ns+1, vector<int>(nt+1,-1));
    int ans = numDistinctUtil_1(s,t,ns,nt,dp);
    return ans;
}


int numDistinct_tabulation(string s, string t) {
    int ns = s.size();
    int nt = t.size();
    vector<vector<double>> dp(ns+1, vector<double>(nt+1,0));

    for(int i = 0; i <= ns; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= ns; i++) {
        for(int j = 1; j <= nt; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return (int)dp[ns][nt];
}


int numDistinct_tabulation_2D(string s, string t) {
    int ns = s.size();
    int nt = t.size();

    vector<double> prev(nt+1,0);
    vector<double> curr(nt+1,0);

    prev[0] = curr[0] =  1;   // both 1 bcz,    for (dp[i][0] = 1)   every dp[row][0] = 1 
 
    for(int i = 1; i <= ns; i++) {
        for(int j = 1; j <= nt; j++) {
            if(s[i-1] == t[j-1]) {
                curr[j] = prev[j-1] + prev[j];
            }
            else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return (int)curr[nt];
}


int numDistinct_tabulation_1D(string s, string t) {
    int ns = s.size();
    int nt = t.size();

    // vector<double> prev(nt+1,0);
    vector<double> curr(nt+1,0);

    curr[0] =  1; 
 
    for(int i = 1; i <= ns; i++) {
        for(int j = nt; j >= 1; j--) {
            if(s[i-1] == t[j-1]) {
                curr[j] = curr[j-1] + curr[j];
            }
            // else {
            //     curr[j] = curr[j];
            // }
        }
    }

    return (int)curr[nt];
}


int main() {   
    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";

    cout<<numDistinct_tabulation_1D(s,t)<<endl;
}
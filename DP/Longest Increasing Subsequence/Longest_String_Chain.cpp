#include<bits/stdc++.h>
using namespace std;

// Longest String Chain
// https://leetcode.com/problems/longest-string-chain/

bool check(string small, string large){
    
    int cnt = 0;
    int i = 0 , j = 0;
    while(i < large.size() and j < small.size()){
        if(large[i] != small[j]){
            i++;
            cnt++;
        }
        else{
            i++;
            j++;
        }
    }

    if(cnt > 1){
        return 0;
    }
    return 1;
}


int longestStrChain(vector<string>& words) {
    int n = words.size();

    vector<pair<int, string>> words_;
    for(auto it: words) {
        words_.push_back({it.size(), it});
    }


    sort(words_.begin(), words_.end());
    for(int i = 0; i < words.size(); i++) {
        words[i] = words_[i].second;
    }

    vector<int> dp(n,1);
    int maxi = 1;
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if((words[i].size() - words[j].size() == 1) and  check(words[j], words[i]) and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                maxi = max(maxi, dp[i]);
            }
        }
    }

    return maxi;
}

int main() {
    vector<string> words = {"wnyxmflkf","xefx","usqhb","ttmdvv","hagmmn","tmvv","pttmdvv","nmzlhlpr","ymfk","uhpaglmmnn","zckgh","hgmmn","isqxrk","isqrk","nmzlhpr","uysyqhxb","haglmmn","xfx","mm","wymfkf","tmdvv","uhaglmmn","mf","uhaglmmnn","mfk","wnymfkf","powttkmdvv","kwnyxmflkf","xx","rnqbhxsj","uysqhb","pttkmdvv","hmmn","iq","m","ymfkf","zckgdh","zckh","hmm","xuefx","mv","iqrk","tmv","iqk","wnyxmfkf","uysyqhb","v","m","pwttkmdvv","rnqbhsj"};
    cout<<longestStrChain(words)<<endl;
}


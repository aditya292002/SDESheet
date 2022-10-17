class Solution {
public:
string reorganizeString(string s) {
    int n = s.size();
    unordered_map<char,int> mp;
    for(auto it : s) {
        mp[it]++;
    }

    int half = n/2;
    if(half*2 != n) half++;


    priority_queue<pair<int,char>, vector<pair<int,char>> > pq;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        if(mp[ch] > half) {
            return  "";
        }
        if(mp[ch] > 0) {
            pq.push({mp[ch], ch});
        }
    }

    string ans = "";
    while(ans.size() != s.size()) {
        auto ele1 = pq.top(); pq.pop();
        ans += ele1.second;
        if(ans.size() == s.size()) break;

        auto ele2 = pq.top(); pq.pop();
        ans += ele2.second;

        
        if(ele1.first - 1 > 0) {
            pq.push({ele1.first - 1, ele1.second});
        }
        if(ele1.second - 1 > 0) {
            pq.push({ele2.first - 1, ele2.second});
        }
    }

    return ans;
}
};
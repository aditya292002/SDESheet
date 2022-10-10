#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

string robotWithString(string s) {
    int n = s.size();
    string ans;
    stack<int> st;

    vector<int> last(26,0);
    for(int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }

    for(int i = 0; i < n; i++) {
        st.push(s[i]);

        while(!st.empty()) {
            int exist = 0;
            for(int j = 0; j < (st.top() - 'a'); j++) {
                if(last[j] > i) {
                    exist = 1;
                }   
            }

            if(exist) break;
            else {
                ans += st.top();
                st.pop();
            }
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}


int main() {
    cout << robotWithString("bac") << endl;
}

#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/break-a-palindrome/

string breakPalindrome(string s) { 
    int i = 0;
    while(i <= s.size()/2) {
        if(s[i] != 'a') break;
        i++;
    }

    if(s.size() == 1) return "";

    if(i == s.size()) {
        s[s.size() - 1] = 'b';
        return s;
    }
    
    if(s.size()%2 != 0 and i == ( s.size()/2 )) {
        s[s.size() - 1] = 'b';
        return s;
    }

    s[i] = 'a';
    return s;
}


int main() {
    
}

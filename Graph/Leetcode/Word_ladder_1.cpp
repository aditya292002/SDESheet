#include<bits/stdc++.h>
using namespace std;


// Word Ladder
// https://leetcode.com/problems/word-ladder/  <-- Practice Link 

// https://www.youtube.com/watch?v=pzT371vkzt8 <-- Detailed Solution 

int wordDiff(string a, string b) {
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) cnt++;

        if(cnt > 1) return 2;
    }
    return cnt;
}


// Brute Force
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> adj;
    for(int i = 0; i < wordList.size(); i++) {
        for(int j = i+1; j < wordList.size(); j++) {
            if(wordDiff(wordList[i],wordList[j]) == 1) {
                adj[wordList[i]].push_back(wordList[j]);
                adj[wordList[j]].push_back(wordList[i]);
            }
        }
    }    

    for(int i = 0; i < wordList.size(); i++) {
        if(wordDiff(wordList[i],beginWord) == 1) {
            adj[beginWord].push_back(wordList[i]);
        }
    }

    queue<pair<string,int>> q;  //{node, level}
    
    q.push({beginWord,1});  // They are asking for sequence length  (That's why we are pushing {begionWord,1} in queue)
    
    set<string> visited;
    visited.insert(beginWord);

    while(!q.empty()) {
        string x = q.front().first;
        int level = q.front().second;
        q.pop();

        for(auto it : adj[x]) {

            if(visited.find(it) == visited.end()) {

                if(it == endWord) return level + 1; 

                q.push({it,level+1}); // They are asking for sequence length 
                visited.insert(it);
            }
        }
    }

    return 0;
}


//Optimized Solution
int ladderLength_(string beginWord, string endWord, vector<string>& wordList) {

    int n = wordList.size();
    int m = beginWord.size();

    unordered_map<string, vector<string>> adj;

    for(int i = 0; i < n; i++) {   //n
        for(int j = 0; j < m; j++) { //m

            string temp = wordList[i].substr(0,j) + "*" + wordList[i].substr(j+1,m-1);
            adj[temp].push_back(wordList[i]);
        }
    }    

    for(int j = 0; j < m; j++) { //m

        string temp = beginWord.substr(0,j) + "*" + beginWord.substr(j+1,m-1);
        adj[temp].push_back(beginWord);
    }

    queue<pair<string,int>> q;
    q.push({beginWord,1});

    set<string> visited;
    visited.insert(beginWord);

    while(!q.empty()) {
        string x = q.front().first;
        int level = q.front().second;
        q.pop();

        for(int i = 0; i < m; i++) {
            string temp = x.substr(0,i) + "*" + x.substr(i+1,m-1);

            for(string next : adj[temp]) {
                if(visited.find(next) == visited.end()) {

                    if(next == endWord) return level + 1;

                    visited.insert(next);
                    q.push({next,level+1});
                }
            }
        }
    }

    return 0;
}




int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength(beginWord, endWord, wordList)<<endl;
}

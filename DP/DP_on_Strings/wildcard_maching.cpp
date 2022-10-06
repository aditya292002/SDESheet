#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vs vector<string>
#define vvs vector<vs>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define ff first
#define ss second
#define debug(a) cout<<#a<<" ";printt(a);cout<<endl;
#define ll long long
#define FOR(i,s,e) for(int i = s; i < e;i++)
#define ll long long
#define vs vector<string>
#define nline cout<<endl;
#define sort_(arr) sort(arr.begin(),arr.end());

#define un unordered_map
#define fr front
#define con continue
int dir[2][2] = {{1, 0}, {0, 1}};

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
template<class T>void printt(set<T> mySet) {for(auto it : mySet) {debug(it)}}
template<class T>void printt(queue<T> q) {while(!q.empty()) {cout<<q.front()<<" ";;q.pop();}cout<<endl;}

void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}
int convert_string_int(string s){  
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}

int mod =(int)1e9+7;
// factorial
ll fact(ll n){
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
// Combination
ll nCr(ll n, ll r) {return fact(n) / (fact(r) * fact(n - r));}

//print Queue
template<class T>void printQueue(queue<T> q) {
    while(!q.empty()) {
        debug(q.front());
        q.pop();
    }
}

//print adjacency list
void print_adjList(vector<int> adjList[], int n) {
    for(int i = 0; i < n; i++) {
        debug(adjList[i]);
    }
}

/*  s{
    TC = O(n)
    SC = O(n)
}
*/
//--------------------------------------------------------------------------------------------------------------------------------------
    

bool isAllStars(string &S1, int i) {
  for (int j = 0; j < i; j++) {
    if (S1[j] != '*')
      return false;
  }
  return true;
}

bool isMatchUtil(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
    if(i < 0 and j < 0) return true; // both strings exhausted
    
    if(j < 0) return false;

    if(i < 0 and j >= 0) return isAllStars(p,j);

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] ==  p[j] || p[j] == '?') {
        return dp[i][j] = isMatchUtil(s, p, i-1, j-1, dp);
    } 
    else if(p[j] == '*') {
        return dp[i][j] = isMatchUtil(s, p, i-1, j, dp) | isMatchUtil(s, p, i, j-1, dp);
    }

    return dp[i][j] = false; // only consition left is s[i] != p[j]   // to use this function you need to change isAllStars function ">=i" <-- this part in loop
}    

// shifting of index
bool isMatchUtil_1(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
    if(i == 0 and j == 0) return true; // both strings exhausted
    
    if(j == 0) return false;

    if(i == 0 and j >= 1) return isAllStars(p,j);

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i-1] ==  p[j-1] || p[j-1] == '?') {
        return dp[i][j] = isMatchUtil_1(s, p, i-1, j-1, dp);
    } 
    else if(p[j-1] == '*') {
        return dp[i][j] = isMatchUtil_1(s, p, i-1, j, dp) | isMatchUtil_1(s, p, i, j-1, dp);
    }

    return dp[i][j] = false; // only consition left is s[i] != p[j]
}    

bool isMatch(string s, string p) {    
    int ns = s.size();
    int np = p.size();
    vector<vector<int>> dp(ns+1, vector<int>(np+1,-1));
    int ans = isMatchUtil_1(s, p, ns, np, dp);
    return ans;
}
    



// tabulation code
bool isMatch_Tabulation(string s, string p) {
    int ns = s.size();
    int np = p.size();
    vector<vector<int>> dp(ns+1, vector<int>(np+1,0));

    for(int i = 0; i <= ns; i++) {
        for(int j = 0; j <= np; j++) {
            if(i == 0 and j == 0) {
                dp[i][j] = 1; continue;
            }
            if(i >= 1 and j == 0) {
                dp[i][j] = 0; continue;
            }
            if(i == 0 and j >= 1) {
                dp[i][j] = isAllStars(p,j); continue;
            }

            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[ns][np];
}    

// space optimization
bool isMatch_Tabulation_SO_2D(string s, string p) {
    int ns = s.size();
    int np = p.size();

    vector<int> prev(np+1,0);
    vector<int> curr(np+1,0);


    for(int i = 0; i <= ns; i++) {
        for(int j = 0; j <= np; j++) {
            if(i == 0 and j == 0) {
                curr[j] = 1; continue;
            }
            if(i >= 1 and j == 0) {
                curr[j] = 0;
                continue;
            }
            if(i == 0 and j >= 1) {
                curr[j] = isAllStars(p,j); continue;
            }

            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                curr[j] = prev[j-1];   // here current jth column --> depends on previous (j-1)th column and 
            } 
            else if(p[j-1] == '*') {
                curr[j] = prev[j] | curr[j-1];   // here current jth column --> depends on current (j-1)th column ,

                                                                                    // so can't be space optimized using 1D
            }
            else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return curr[np];
}    



int main() {
    string s = "abcabczzzde";
    string p = "*abc???de*";
}
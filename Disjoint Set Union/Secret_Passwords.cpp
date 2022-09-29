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
// vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T> void printt(vector<vector<vector<T>>> vec) { cout<<endl;for(auto it3 : vec){cout<<"[ "<<endl;for(auto it2 : it3) {for(auto it1 : it2) {     cout<<it1<<" ";}   cout<<endl;}cout<<"] "<<endl;cout<<endl;}cout<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
template<class T>void printt(queue<T> q) {while(!q.empty()) {cout<<q.front()<<" ";;q.pop();}cout<<endl;}
template<class T>void printt(set<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(multiset<T> s) {for(auto it : s) {cout<<it<<" ";} cout<<endl;}
template<class T>void printt(vector<pair<T,T>> vec) {cout<<"["<<endl;for(auto it : vec) {cout<<"{ "<<it.ff<<" "<<it.ss<<" }"<<endl;}cout<<"]"<<endl;}

void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}

unsigned countBits(unsigned int number) {    
    // log function in base 2
    // take only integer part
    return (int)log2(number)+1;
}

int convert_string_int(string s){  
    int ans = 0;
    int n = (int)(s.length());
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}

// int mod =(int)1e9+7;
// factorial
ll fact(ll n){
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
// Combination
ll nCr(ll n, ll r) {return fact(n) / (fact(r) * fact(n - r));}

//print adjacency list
void print_adjList(vector<int> adjList[], int n) {
    for(int i = 0; i < n; i++) {
        debug(adjList[i]);
    }
}   

/*
{
    TC = O(n)
    SC = O(n)
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------

// Platform -- Codeforces

// https://codeforces.com/problemset/problem/1263/D   <-- Practice Link 


// Approach - 1 

char find_set(unordered_map<char, char> &parent, char v) {
    if(parent[v] == v) return v;
    return parent[v] = find_set(parent, parent[v]); 
}

void union_set(unordered_map<char,char> &parent, unordered_map<char,int> &rank, char a, char b) {
    a = find_set(parent, a);
    b = find_set(parent, b);
    if(a == b) return;

    if(rank[a] == rank[b]) {
        rank[a]++;
        parent[b] = a;
    }
    else if(rank[a] > rank[b]) {
        parent[b] = a;
    }
    else
        parent[a] = b;
}

void solve() {
    int t;  cin>>t;
    set<char> distinct_Chars;

    unordered_map<char, char> parent;
    unordered_map<char, int> rank;
    for(char c = 'a'; c <= 'z'; c++){
        parent[c] = c;
        rank[c] = 0;
    }

    vs store;
    for(int i = 0; i < t; i++) {
        string s; cin>>s;
        sort(s.begin(), s.end());
        store.push_back(s);
    }
    sort(store.begin(), store.end());


    for(auto s : store) {
        int n = s.size();

        // debug(s)

        char setParent = '.';
        for(auto ch : s) {
            if(parent[ch] != ch) {
                setParent = parent[ch];
                break;
            }
        }
        int i = 0;
        distinct_Chars.insert(s[0]);
        if(setParent == '.') {
            i = 1;
        }

        // debug(setParent)

        for(; i < n; i++) {
            distinct_Chars.insert(s[i]);
            if(setParent == '.') {
                // debug(s[0])
                // debug(s[i])
                union_set(parent, rank, s[0], s[i]);
            }
            else {
                union_set(parent, rank, setParent, s[i]);
            }
        }
    }


    int setCount = 0;
    unordered_map<char, bool> vis;
    for(auto it : distinct_Chars) {

        // debug(parent[it])
        // debug(vis[parent[it]])
        // debug(it)

        if(vis[parent[it]] == 0) {
            setCount++;
            vis[parent[it]] = 1;
        }
        // debug(setCount)
    }

    cout<<setCount<<endl;
}


// Approach - 2 (Better)
/*

int find_set(vector<int> &parent, int a) {
    return parent[a] = (parent[a] == a ? a : find_set(parent, parent[a]));
}

void union_set(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);
    if(a == b) return;

    if(rank[a] == rank[b]) {
        rank[a]++;
        parent[b] = a;
    }
    else if(rank[a] > rank[b]) {
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}


void solve() {
    int t;  cin>>t;
    
    vi parent(26,0), rank(26,0);
    loop(i, 0, 25) {
        parent[i] = i;
    }

    vector<bool> total(26,0);   
    vector<bool> current(26,0);



    loop(j, 1, t) {
        string s; cin>>s;

        loop(i, 0, 25) current[i] = 0;  
        
        for(auto ch : s) {
            current[ch - 'a'] = true;
        }

        loop(i, 0, 25) {
            if(current[i] == true) {
                total[i] = true;
                union_set(parent, rank, s[0] - 'a', i);
            }
        }
    }


    int countSets = 0;

    loop(i, 0, 25) {
        if(total[i] == true and find_set(parent, i) == i) {
            countSets++;
        }
    }

    cout<<countSets;
}

*/

int main() {
    solve();
}

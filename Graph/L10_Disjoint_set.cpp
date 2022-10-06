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


int dir[2][2] = {{1, 0}, {0, 1}};
// const int INF = 1e9;

template<class T>void printt(vector<T> vec){cout<<" : [ ";for(auto i : vec){cout<<i<<" ";}cout<<"] "<<endl;}
template<class T>void printt(T var){cout<<" : "<<var<<endl;}
template<class T>void printt(vector<vector<T>> vec){cout<<endl;cout<<"["<<endl;for(auto ii : vec){cout<<"[ ";for(auto a : ii){cout<<a<<" ";}cout<<"]"<<endl;}cout<<"]"<<endl;}
template<class T>void printt(pair<T,T> myPair){cout<<": { "<<myPair.ff<<" "<<myPair.ss<<" }"<<endl;}
void printArray(int arr[], int n){for(int i = 0; i < n; i++){cout<<arr[i]<<" ";}cout<<endl;}
int convert_string_int(string s){
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n;i++){if(s[i] == '0'){s.substr(1);}else{break;}}
        int tenth = 1;
    for(int i = n-1; i>=0; i--){ans = ans + (tenth*(s[i] - '0'));tenth*=10;}
        return ans;
}

// factorial
int fact(int n){int res = 1;for (int i = 2; i <= n; i++)res = res * i;return res;}
// Combination
int nCr(int n, int r){return fact(n) / (fact(r) * fact(n - r));}


int mod =(int)1e9+7;

//print adjacency list
void print_adjList(vector<int> adjList[], int n){
    for(int i = 0; i < n; i++){
        debug(adjList[i]);
    }
}

/*  s{
    TC = O(n)
    SC = O(n)
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------


// Disjoint set (Union by Rank and Path Compression) 
int parent[100000];
int rank[100000];

void makeSet() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(int node) {
    if(node == parent[node]) {
        return node; 
    }

    return parent[node] = findPar(parent[node]);  // path compression 
}

void union(int u, int v) {
    u = findPar(u);
    v = findPar(v);

    if(u == v) return;

    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u; 
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    makeSet();
    int m;
    cin>>m;
    while(m--) {
        int u,v; 
        union(u,v);
    }
}
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

int mod =(int)1e9+7;
// factorial
int fact(int n){int res = 1;for (int i = 2; i <= n; i++)res = res * i;return res;}
// Combination
int nCr(int n, int r) {return fact(n) / (fact(r) * fact(n - r));}

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
//----------------------------------------------------------------------------------------------------------------------------------------

// Bipartite Graph
// Check if given Undirected Graph is Bipartite 

// https://practice.geeksforgeeks.org/problems/bipartite-graph/1    <--  Practice link

//using DFS

bool dfs(int curNode, vector<int> adj[], int prevColor, vector<int> &color) {
    color[curNode] = prevColor^1;
    for(auto nbr : adj[curNode]) {
        if(color[nbr] == -1) {
            if(dfs(nbr, adj, prevColor^1, color) == false) return false;
        }
        else {
            if(color[nbr] == prevColor^1) return false;
        }
    }
    return true;
}

bool isBipartite_(int V, vector<int>adj[]){  //to run DFS make sure you correct the name of the function 
    vector<int> color(V,-1);
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            if(dfs(i, adj, 1, color) == false) return false; 
        }
    }
    return true;
}


// using BFS

bool BFS(int src, vector<int>adj[], vector<int> &color) {
    queue<pair<int,int>> q;
    q.push({src,1});

    while(!q.empty()) {
        int node = q.front().first;
        int prevColor = q.front().second;
        color[node] = prevColor^1;
        q.pop();


        for(auto nbr : adj[node]) {
            if(color[nbr] == -1) {
                // not colored
                q.push({nbr,prevColor^1});
            }
            else {
                if(color[nbr] == prevColor^1) return false;
            }
        }
    }   
    return true;
}

bool isBipartite(int V, vector<int>adj[]) {
    vector<int> color(V,-1);
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            // that means i is not yet colored
            // let's color i 
            //BFS
            if(BFS(i, adj, color) == false) return false;
        }
    }
    return true;
}


int main() {
    int V,e; cin>>V>>e;
    // unordered_map<int, vector<int>> adj;
    vector<int> adj[V];
    for(int i = 0; i < e; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


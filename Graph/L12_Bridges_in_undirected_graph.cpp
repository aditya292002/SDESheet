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

// Bridges In A Graph
// https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0

// Leetcode question based on the concept (same solution)
// https://leetcode.com/problems/critical-connections-in-a-network/

void dfs(int curNode, int parent, int &timer, unordered_map<int , vector<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<vector<int>> &result) {
    visited[curNode] = true;
    disc[curNode] = low[curNode] = timer++;
    // timer++;

    for(int it : adj[curNode]) {
        if(it == parent) continue;

        if(!visited[it]) {
            dfs(it, curNode, timer, adj, visited, disc, low, result);
            //check if the edge is a bridge
            low[curNode] = min(low[curNode], low[it]);
            if(low[it] > disc[curNode]) {
                result.push_back({min(it,curNode), max(it,curNode)});
            }
        }
        else{
            // node already visited and not parent 
            // Back edge
            low[curNode] = min(low[curNode], disc[it]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int V, int e) {
    unordered_map<int , vector<int>> adj;
    for(auto it : edges) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> result;

    vector<bool> visited(V,false);
    vector<int> disc(V,-1); // discover array
    vector<int> low(V,-1);  // low array to store earliest time to visit the node
    int timer = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            // dfs
            dfs(i, -1, timer, adj, visited, disc, low, result); 
        }
    }
    sort(result.begin(), result.end());
    return result;
}


int main() {    
    vector<vector<int>> edges;
    int v, e; cin>>v>>e;
    for(int i = 0; i < e; i++) {
        int u,v; cin>>u>>v;
        edges.push_back({u,v});
    }
    debug(findBridges(edges,v,e))
}   

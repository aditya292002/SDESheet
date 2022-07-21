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

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//cycle detection in undirected graph using DFS
bool dfs(int curNode, int parent, vector<int> adj[], vector<int> &visited) {
    visited[curNode] = 1;
    for(auto ele : adj[curNode]) {
        if(!visited[ele]) {
            if(dfs(ele, curNode, adj, visited)) return true;
        }
        else if(ele != parent){
            return true;
        }
    }
    return false;
}

bool isCycle_(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}


//cycle detection in undirected graph using BFS
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V,0);

    for(int i = 0; i < V;i++) {
        if(!vis[i]) {
            //-------------------------------
            queue<pair<int,int>> q; // pair<int,int> to store {node,parent}
            q.push({i,-1});
            vis[i] = 1;
            
            while(!q.empty()) {
                int curNode = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(int ele : adj[curNode]) {
                    if(!vis[ele]) {
                        q.push({ele,curNode});
                        vis[ele] = 1;
                    }
                    else if(ele != parent) {
                        return true;
                    }
                }
            }

            //-------------------------------

        }
    }
    return false;
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
    cout<<isCycle(V, adj)<<endl;
}

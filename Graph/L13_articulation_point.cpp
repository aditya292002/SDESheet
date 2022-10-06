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

// articulation points in graph
void dfs(int curNode, int parent, int &timer, unordered_map<int, vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &vis, 
        vector<int> &res) {

    vis[curNode] = 1;
    disc[curNode] = low[curNode] = timer++;


    for(auto nbr : adj[curNode]) {
        if(nbr == parent) continue;

        if(!vis[nbr]) {
            dfs(nbr, curNode, timer, adj, disc, low, vis, res);
            low[curNode] = min(low[curNode], low[nbr]);

            if(low[nbr] >= disc[curNode] and parent != -1) {
                res.push_back(curNode);
            }
        }
        else {
            low[curNode] = min(low[curNode], disc[nbr]);
        }
    }
}

int main() {
    int v,e; cin>>v>>e;
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < e; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v,-1), low(v,-1);
    vector<bool> vis(v,false);

    vector<int> res;

    for(int i = 0; i < v; i++) {
        if(!vis[i]) { 
            // dfs
            if(adj[i].size() > 1) res.pb(i);
            dfs(i,-1,timer, adj, disc, low, vis, res);
        }
    }
    debug(res)
}
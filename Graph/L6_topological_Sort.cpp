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
const int INF = 1e9;

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

/*      
{
    TC = O(n)
    SC = O(n)
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------


// Topological sort
// https://practice.geeksforgeeks.org/problems/topological-sort/1/      <-- Practice Link


// Using DFS
void dfs(vector<int> adj[], int curNode, stack<int> &st, vector<int> &visited) {
    visited[curNode] = 1;
    for(int ele : adj[curNode]) {
        if(visited[ele] == 0) {
            dfs(adj, ele, st, visited);
        }
    }
    st.push(curNode);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    stack<int> st;
    for(int i = 0; i < V; i++) {
        if(visited[i] == 0) {
            dfs(adj, i, st, visited);
        }
    }
    vector<int> topo;
    while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

// topological sort using kahn's Algorithm (BFS)

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> inDegree(V,0);
    for(int i = 0; i < V; i++) {
        for(int nbr : adj[i]) {
            inDegree[nbr]++;
        }
    }    

    queue<int> q; // this queue will store all nodes with 0 indegree initially
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()) {
        int node = q.front();
        topo.push_back(node);
        q.pop();

        for(int nbr : adj[node]) {
            inDegree[nbr]--;
            if(inDegree[nbr] == 0) {
                q.push(nbr);
            }
        }    
    }
    
    return topo;
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


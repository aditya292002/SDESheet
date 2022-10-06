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

// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// DFS of Graph

//Resursive sol
void recursiveDfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &ans){
    ans.push_back(node);
    visited[node] = 1;
    for(int ele : adj[node]){
        if(visited[ele] == 0){
            recursiveDfs(ele,adj,visited,ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    vector<int> ans;

    for(int i = 0; i < V; i++){
        if(visited[i] == 0){
            recursiveDfs(i,adj,visited,ans);
        }
    }
    return ans;
}


// Iterative method using stack
vector<int> dfsOfGraph_(int V, vector<int> adj[]) {
    vector<int> dfs;
    vector<int> visited(V,0);
    
    stack<int> st;
    st.push(0);
    dfs.push_back(0);
    visited[0] = 1;

    while(!st.empty()) {
        int curVertex = st.top();
        int flag = 1;
        for(int ele : adj[curVertex]) {
            if(visited[ele] == 0){
                dfs.push_back(ele);
                visited[ele] = 1;
                st.push(ele);
                flag = 0; 
                break;
            }
        }
        if(flag){
            st.pop();
        }
    }
    return dfs;
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











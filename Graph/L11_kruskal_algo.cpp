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




int findPar(vector<int> &parent, vector<int> &rank, int node) {
    if(node == parent[node]) {
        return node; 
    }

    return parent[node] = findPar(parent,rank,parent[node]);  // path compression 
}

void union_(vector<int> &parent, vector<int> &rank, int u, int v) {
    u = findPar(parent,rank,u);
    v = findPar(parent,rank,v);

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

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<vector<int>> vis(V, vector<int>(V,0));; 
    vector<vector<int>> edges;
    for(int i = 0; i < V ;i++) {
        for(auto ele : adj[i]) {
            int weight = ele[1];
            int v = ele[0];
            int u = i;
            if(vis[u][v] ==  0) {
                vis[u][v] = 1;
                vis[v][u] = 1;
                vector<int> edge(3);
                edge[0] = weight;
                edge[1] = u;
                edge[2] = v;
                edges.pb(edge);
            }
        }
    }
    sort(edges.begin(),edges.end());

    vector<int> parent(V+10,0), rank(V+10,0);
    for(int i = 0; i < V+10; i++) {
        parent[i] = i;
    }
    int total = 0;
    for(auto edge : edges) {
        int weight = edge[0];
        int u = edge[1];
        int v = edge[2];

        // union_(u,v);
        if(findPar(parent,rank,u) != findPar(parent,rank,v)) {
            union_(parent,rank,u,v);
            total += weight;
        }
    }
    return total;
}

int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>> adjList[n];
    for(int i = 0; i <m; i++) {   
        int u,v,w; cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    // print_adjList(adjList,n);
    for(auto ele : adjList){
        debug(ele)
    }
    cout<<spanningTree(n,adjList)<<endl;
}

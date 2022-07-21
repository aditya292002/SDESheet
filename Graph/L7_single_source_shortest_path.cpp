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

// Dijkstra Algorithm
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/


//find single source shorted path using BFS
vector <int> dijkstra_(int V, vector<vector<int>> adj[], int src) {
    vector<int> dist(V,1e9);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        
        int node = q.front();
        q.pop();

        for(auto ele : adj[node]) {
            int adjNode = ele[0];
            int wt = ele[1];

            if(dist[node] + wt < dist[adjNode]) {
                dist[adjNode] = dist[node] + wt;
                q.push(adjNode);
            }
        }
    
    } 

    return dist;
} 

//Optimized way to find since source shorted path (Dijkstra)
vector <int> dijkstra(int V, vector<vector<int>> adj[], int src) {
    int INF = 1e9;
    vector<int> dist(V,INF);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq; 
    pq.push({0,src});

    vector<int> visited(V,0);
    while(!pq.empty()) {
        
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(visited[node]) continue;
        visited[node] = 1;
        
        for(auto ele : adj[node]) {
            int adjNode = ele[0];
            int wt = ele[1];

            if(dist[node] + wt < dist[adjNode]) {
                dist[adjNode] = dist[node] + wt;
                pq.push({dist[adjNode] , adjNode});
            }
        }
    
    } 

    return dist;
} 





int main() {
    int n,m; cin>>n>>m;
    vector<int> adjList[n];
    for(int i = 0; i <m; i++) {   
        int u,v; cin>>u>>v;
        adjList[u].push_back(v);
    }
    print_adjList(adjList,n);
}
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


// Minimum Spanning Tree (Using Prim's Algorithm)
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/#   (GFG Practice link -- Accepted)

int spanningTree(int V, vector<vector<int>> adj[]){
    vector<int> key(V,INT_MAX);
    vector<bool> mst(V,false);
    vector<int> parent(V,-1);

    key[0] = 0;

    for(int count = 0; count < V; count++) {

        /* In be following for loop we are just finding the minimal so instead of using a vector we can use a priority queue */
        int mini = INT_MAX, u;
        for(int v = 0; v < V; v++) {
            if(mst[v] == false and key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        mst[u] = true; //this node is included in mst
        for(auto it : adj[u]) {

            int v = it[0];
            int weight = it[1];

            if(mst[v] == false) {

                // check if adjacent node dis value can be updated
                if(key[v] > weight) {
                    key[v] = weight;
                }

                parent[v] = u;
            }
        }
    }
    int total = 0;
    for(int it : key) {
        total += it;
    }
    return total;
}       
/*

TC : O(N^2)
SC : O(3N) = O(N)

*/


// Optimized Approach
int spanningTree_(int V, vector<vector<int>> adj[]){
    vector<int> key(V,INT_MAX);
    vector<bool> mst(V,false);
    vector<int> parent(V,-1);

    key[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;   // { key[index] , index }
    pq.push({0,0});
    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();


        // Different key values for same vertex may exist in the priority queue.
        // The one with the least key value is always processed first.
        // Therefore, ignore the rest.
        if(mst[u] == true){    
            continue;
        }

        mst[u] = true; //this node is included in mst
        
        for(auto it : adj[u]) {

            int v = it[0];
            int weight = it[1];

            if(mst[v] == false and key[v] > weight) {

                // check if adjacent node dis value can be updated
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});

            }
        }
    }
    int total = 0;
    for(int it : key) {
        total += it;
    }
    return total;
}       

/*

TC : O(N log(N))
SC : O(3N) = O(N)

*/



int main() {
    int n,m; cin>>n>>m;
    vector<int> adjList[n];
    for(int i = 0; i <m; i++) {   
        int u,v; cin>>u>>v;
        adjList[u].push_back(v);
    }
    print_adjList(adjList,n);
}
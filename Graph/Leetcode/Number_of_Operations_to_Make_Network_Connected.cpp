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


// Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/ 


int makeConnected(int V, vector<vector<int>>& adj) { 
    vector<vector<int>> adjList(V);
    for(auto it : adj) {
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }


    int cntComponents = 0;

    int wiresReq = 0;   // wiresReq  = (for all components) + min no. of wires required so that all nodes a 
                                                                        // component are connected 
    vector<int> vis(V,0);

    for(int i = 0; i < V; i++) {
        // Counting the nodes in each component 
        int cntNodes = 0;
        if(!vis[i]) {
            cntComponents++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            cntNodes++;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                
                for(int nbr : adjList[node]) {
                    if(!vis[nbr]) {
                        vis[nbr] = 1;
                        cntNodes++;
                        q.push(nbr);
                    }
                }
            }
        }
        // Wires required so that each component is connected =  no. of nodes in component - 1
        if(cntNodes) {
            wiresReq += (cntNodes - 1);
        }
    }

    int cntWires = adj.size();
    int extraWires = cntWires - wiresReq;  //extrawires
    if(extraWires >= cntComponents - 1) {
        return cntComponents-1;
    }
    return -1;
}


int main() {
    vvi con = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    cout<<makeConnected(6,con)<<endl;
}











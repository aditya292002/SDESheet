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


 // Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/  <-- Practice link

bool dfs(int curNode, vector<vector<int>> &graph, vector<int> &vis, vector<int> &safeNodes, unordered_map<int,bool> &mp) {
    vis[curNode] = 1;

    if(graph[curNode].size() == 0) {
        safeNodes.push_back(curNode);
        mp[curNode] = 1; return true;
    }

    int ans = 1;    //initially assume : safe node

    for(int ele : graph[curNode]) {
        if(!vis[ele]) {
            bool sol = dfs(ele,graph,vis,safeNodes,mp);
            ans = ans & sol;   //at any adjacent is not safe : ans = 0
        }
        else {
            ans = ans & mp[ele];  //at any adjacent is not safe : ans = 0
        }
    }

    if(ans == 1) {
        mp[curNode] = 1;
        safeNodes.push_back(curNode);
        return true;
    }
    mp[curNode] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> safeNodes;
    vector<int> vis(n+1,0);
    
    unordered_map<int,bool> mp;   // to keep track if a already visited node is safe or not
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i,graph,vis,safeNodes,mp);
        }
    }   
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main(){
    // vvi graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vvi graph = {{},{0,2,3,4},{3},{4},{}};
}

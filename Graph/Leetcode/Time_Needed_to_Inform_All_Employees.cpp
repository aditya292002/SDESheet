#include<bits/stdc++.h>
using namespace std;



// Time Needed to Inform All Employees
// https://leetcode.com/problems/time-needed-to-inform-all-employees/



int dfs(int curNode, vector<vector<int>> &adj, vector<int> &informTime) {
    int maxi = 0;
    for(int nbr : adj[curNode]) {
        maxi = max(maxi, dfs(nbr, adj, informTime));
    }
    return maxi + informTime[curNode];
}

// or

// Approach : get the maximum path sum of the graph

// dfs and backtracking
// go throught all possible paths of tree 
// ans will store the sum of edges of a given path 
// whenever max path changes i.e answer is updated to a new value , make sure to update maxi if possible , so that maxi has maximum path sum
void dfs_(int curNode, vector<vector<int>> &adj, vector<int> &informTime, int &maxi, int &ans) {
    ans += informTime[curNode];
    for(auto nbr : adj[curNode]) {
        dfs_(nbr, adj, informTime, maxi, ans);
    }
    maxi = max(maxi, ans);
    ans -= informTime[curNode];  //backtrack
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++) {
        if(i != headID){
            adj[manager[i]].push_back(i);
        }
    }  

    int maxi = 0, ans = 0;
    // return dfs(headID, adj, informTime);
    dfs_(headID, adj, informTime, maxi, ans);
    return maxi;
}

int main() {
    int n = 11;
    int headID = 4;
    vector<int> manager = {5,9,6,10,-1,8,9,1,9,3,4};
    vector<int> informTime = {10,213,0,253,686,170,975,0,261,309,337};
    cout<<numOfMinutes(n,headID,manager,informTime)<<endl;
}













#include<bits/stdc++.h>
using namespace std;

// Evaluate Division
// https://leetcode.com/problems/evaluate-division/


void dfs(map<string,vector<pair<string,double>>> &adj, string a, string b, map<string,bool> &vis, double ans, double &final_ans, int &flag) {
    vis[a] = true;
    for(auto it : adj[a]) {
        if(!vis[it.first]) {
            if(it.first == b) {
                final_ans = ans*it.second;
                flag = 1;
                return;
            }
            else {
                dfs(adj,it.first,b,vis,ans*it.second,final_ans, flag);
            }
        }
    }
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    map<string,vector<pair<string,double>>> adj;
    int n = equations.size();
    for(int i = 0; i < n; i++) {
        adj[equations[i][0]].push_back({equations[i][1], values[i]});
        adj[equations[i][1]].push_back({equations[i][0], (double)(1/values[i])});
    }   

    vector<double> sol;
    for(auto it : queries) {
        string a = it[0];
        string b = it[1];
        
        
        if(a == b and adj[a].size() != 0) {
            sol.push_back(1.00);
            continue;
        } 

        map<string,bool> vis;
        double final_ans = 1;
        int flag = 0;   //flag used to check if returned answer is 1
        dfs(adj, a,b, vis, 1, final_ans, flag);
        if(final_ans == 1 and flag == 0) {
            sol.push_back(-1.00);
        }
        else {
            sol.push_back(final_ans);
        }
    }

    return sol;
}
int main() {
    vector<vector<string>> equations = {{"a","b"},{"c","d"}};
    vector<double> values = {1.0,1.0};
    vector<vector<string>> queries= {{"a","c"},{"b","d"},{"b","a"},{"d","c"}};
}



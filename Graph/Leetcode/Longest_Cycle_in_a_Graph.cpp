#include<bits/stdc++.h>
using namespace std;

// Longest Cycle in a Graph
// https://leetcode.com/problems/longest-cycle-in-a-graph/ <-- practice link 

int ans = -1;
void dfs(int curNode, vector<int> &edges, vector<int> &dist, vector<int> &dfsVis, int distance) {
    if(curNode != -1) {
        dist[curNode] = distance;
        dfsVis[curNode] = 1;

        int nextNode = edges[curNode];
        if(nextNode != -1) {
            if(dist[nextNode] == -1) {
                dfs(nextNode, edges, dist, dfsVis, distance+1);
            }
            else {
                if(dfsVis[nextNode] == 1) {
                    ans = max(ans, abs(distance-dist[nextNode]) + 1);
                }
            }
        }
        dfsVis[curNode] = 0;
    }
}

int longestCycle(vector<int> edges) {
    int V = edges.size();

    vector<int> dist(V,-1);
    vector<int> dfsVis(V,0);

    for(int i = 0; i < V; i++) {
        if(dist[i] == -1 and edges[i] != -1) {
            dfs(i, edges, dist, dfsVis, 0);
        }
    }

    if(ans == INT_MIN) return -1;
    return ans;
}

int main() {
    vector<int> edges = {3,3,4,2,3};
    cout<<longestCycle(edges)<<endl;
}

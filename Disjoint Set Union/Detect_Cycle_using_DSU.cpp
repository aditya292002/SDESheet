#include<bits/stdc++.h>
using namespace std;

// practice Link -- https://practice.geeksforgeeks.org/problems/detect-cycle-using-dsu/1


int find_set(vector<int> &parent, int v) {
    if(v == parent[v]) return v;

    return parent[v] = find_set(parent, parent[v]);
}

void union_set(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);
    if(a == b) return;

    if(rank[a] == rank[b]) {
        rank[a]++;
        parent[b] = a;
    }
    else if(rank[a] > rank[b]) {
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int detectCycle(int V, vector<int>adj[]){
    vector<int> parent(V+1), rank(V+1);
    for(int i = 0; i <= V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) {
            if(parent[it] == parent[i]) 
                return 1;
           
            if(i > it) { // to check the edge (i --- j) is considered only once
                union_set(parent, rank, it, i);
            }
        }
    }

    return 0;
}   


int main() {

}
